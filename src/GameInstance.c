///
// Created by Derek Rodriguez on 5/13/18.
//

#include "GameInstance.h"

void clear_hand(player_t *p) {
    for(unsigned short i = 0; i < MAX_HAND_SIZE; i++) {
        p->hand[i] = 0;
    }
    p-> amt_of_cards = 0;
}

void add_bet_t(player_t *p, unsigned int bet_qty)
{
    POOL[CURR_AMT_OF_BETS].bet_src = p;
    POOL[CURR_AMT_OF_BETS].qty = bet_qty;
    CURR_AMT_OF_BETS++;
}

/*
*   I can foresee this structure needing some change down the road.
*   Will probably switch the bet pool to a tree structure of sorts
*   down the line.
*/
void clear_bets()
{
    CURR_AMT_OF_BETS = 0;
}

void shuffle_shoe()
{
    for (unsigned int i = (AMT_OF_DECKS*52)-1; i > 0; i--) {
        // TODO: Replace this with something more random than just rand()
        srand(time(NULL));
        // Pick a random index from 0 to i
        unsigned int j = rand() % (i+1);

        // Swap SHOE[i] with the element at random index
        unsigned int temp = SHOE[j];
        SHOE[j] = SHOE[i];
        SHOE[i] = temp;
    }
}

void deal(player_t *p, unsigned short amt_dealt)
{
    for(unsigned short i = 0; i < amt_dealt; i++) {
        p->hand[p->amt_of_cards + i] = SHOE[TOP_OF_SHOE++];
    }
    p->amt_of_cards += amt_dealt; 
}

short calc_hand(const unsigned short *hand, const unsigned short hand_len)
{
    short score = 0;
    for(unsigned short i = 0; i < hand_len; i++) {
        switch (hand[i]) {
        case 0: // use sign bit to track if ace is in player_t's hand
            score *= -1;
            break;

        case 10: // jack
        case 11: // queen
        case 12: // king
            score += 10;
            break;
        default: // standard number cards (2-9)
            score += (hand[i]+1);
            break;
        }
    }
    //evaluate ace
    if(score < -10) { //if other cards over 10, ace is 1
        score = (score-1)*-1;
    } else if (score < 0) { // otherwise ace is 10
        score = (score-11) * -1;
    }

    return score;
}

char get_move()
{
    char userin[2];
    scanf("%s", userin);
    return userin[0];
}

void hit(player_t *p)
{
    deal(p, 1);
}

void d_down(player_t *p)
{
    // find the bet placed at the start of the round, then double that value
    for(unsigned short i = 0; i < CURR_AMT_OF_BETS; i++) {
        if(POOL[i].bet_src == p) {
            POOL[i].qty *= 2;
            break;
        }
    }
    // then deal one more card and mark player as stood
    deal(p, 1);
    p->stood = true;
}

void stand(player_t *p)
{
    p->stood = true;
}

void split(player_t *p)
{
    // this is just here so I can get a clean call with -Wextra
    printf("This feature is not yet implemented, since it will cause a lot of refactoring. Here's this player's address: %lx\n", (uintptr_t)p);
}

void setup_new_game(player_t *p, unsigned int init_funds, player_t *d)
{
    // if not a new game, then don't use init_funds
    if (p->money != USHRT_MAX) {
        init_funds = p->money;
    }

    // clean up player_ts
    clear_hand(p);
    clear_hand(d);
    char* prompt = "Welcome to BJGym. You will be starting with %i credits.\n";
    printf(prompt, init_funds);

    // generate shoe
    for (unsigned short i = 0; i < (AMT_OF_DECKS*52); ++i) {
        SHOE[i] = (unsigned short)(i%13);
    }
    shuffle_shoe();

    // get initial bet
    p->money = init_funds;
    unsigned int strt_bet_qty = 0;
    printf("How much would you like to bet?: ");
    scanf("%i", &strt_bet_qty);
    p->money -= strt_bet_qty;
    add_bet_t(p, strt_bet_qty);

    // give cards to player_t and dealer
    deal(p, 2);
    deal(d, 2);
}

void print_round_ui(player_t *p, player_t *d)
{
    puts("==========GAME STATE==========");
    printf("Player %lx:\n", (uintptr_t)p);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < p->amt_of_cards; i++) {

        switch (p->hand[i]) {
        case 0: // ace
            printf("A\t");
            break;
        case 10: //jack
            printf("J\t");
            break;
        case 11:
            printf("Q\t");
            break;
        case 12:
            printf("K\t");
            break;
        default: // number card
            printf("%i\t", p->hand[i] + 1);
        }
    }
    printf("\n\tScore: %i\n", calc_hand(p->hand, p->amt_of_cards));
    printf("\tBalance: %d\n", p->money);
    puts("---");

    printf("Dealer: %lx:\n", (uintptr_t)d);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < d->amt_of_cards; i++) {

        if(i == 0) {
             switch (d->hand[i]) {
                case 0: // ace
                    printf("A\t");
                    break;
                case 10: //jack
                    printf("J\t");
                    break;
                case 11:
                    printf("Q\t");
                    break;
                case 12:
                    printf("K\t");
                    break;
                default: // number card
                    printf("%i\t", d->hand[i] + 1);
             }
        }else {
            printf("X\t");
        }
    }
    printf("\n");
    printf("---\n");

    printf("Bet:\tplayer_t\t\tqty\n");

    for(short i = 0; i < CURR_AMT_OF_BETS; i++) {
        printf("\t%lx\t\t%i\n", (uintptr_t)POOL[i].bet_src, POOL[i].qty);
    }
    printf("---\n");
}

void debug_state(player_t *p, player_t *d)
{
    puts("==========GAME STATE==========");
    printf("Player %lx:\n", (uintptr_t)p);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < p->amt_of_cards; i++) {

        switch (p->hand[i]) {
        case 0: // ace
            printf("A\t");
            break;
        case 10: //jack
            printf("J\t");
            break;
        case 11:
            printf("Q\t");
            break;
        case 12:
            printf("K\t");
            break;
        default: // number card
            printf("%i\t", p->hand[i] + 1);
        }
    }
    printf("\n\tScore: %i\n", calc_hand(p->hand, p->amt_of_cards));
    printf("\tBalance: %d\n", p->money);
    puts("---");

    printf("Dealer: %lx:\n", (uintptr_t)d);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < d->amt_of_cards; i++) {

        switch (d->hand[i]) {
        case 0: // ace
            printf("A\t");
            break;
        case 10: //jack
            printf("J\t");
            break;
        case 11:
            printf("Q\t");
            break;
        case 12:
            printf("K\t");
            break;
        default: // number card
            printf("%i\t", d->hand[i] + 1);
        }
    }
    printf("\n\tScore: %i\n", calc_hand(d->hand, d->amt_of_cards));
    printf("\n");
    printf("---\n");

    printf("Bet:\tplayer_t\t\tqty\n");

    for(short i = 0; i < CURR_AMT_OF_BETS; i++) {
        printf("\t%lx\t\t%i\n", (uintptr_t)POOL[i].bet_src, POOL[i].qty);
    }
    printf("---\n");

}

void process_move(char code, player_t *p)
{
    switch(code) {
        case 'h' :
            hit(p);
            break;
        case 's' :
            stand(p);
            break;
        case 'd' :
            d_down(p);
            break;
        default:
            puts("BROKEN");
            break;
    }
}

void end_round_routine(player_t *p, player_t *d)
{
    // play out dealer, stops at 17
    while(calc_hand(d->hand, d->amt_of_cards) < 17) {
        hit(d);
    }

    debug_state(p, d);

    // collect player scores, and distribute apyouts accordingly
    short dealer_score = calc_hand(d->hand, d->amt_of_cards);
    short player_score = calc_hand(p->hand, p->amt_of_cards);
    printf("Player scored: %d\t Dealer scored:%d\n");
    unsigned int player_bet = 0;
    unsigned int payout;
    for(unsigned short i = 0; i < CURR_AMT_OF_BETS; i++) {
            if (POOL[i].bet_src == p) {
                player_bet = POOL[i].qty;
                break;
            }
    }
    if(player_score == 21) {
        payout = player_score == dealer_score ? player_bet : player_bet * 2.5;
    } else if(player_score < 21) {
        payout = player_score < dealer_score ? 0 : player_bet * 1.5;
    } else {
        payout = 0;
    }
    
    if(payout){
        printf("You won %d\n", payout);
        p->money += payout;
    }

    // reset POOL, player, and dealer
    clear_bets();
                               
}

void exec_game_loop()
{
    // instantiate and "initialize" entities that will be used over course of the game
    player_t agent, dealer; // instantiate player_ts
    bool game_over = false;

    // set some default values for the agent
    // this will make it easier to recycle some code for new rounds
    agent.money = USHRT_MAX;
    agent.stood = false;
    // this is the outermost loop
    while(!game_over) {
        while(!agent.stood){
            setup_new_game(&agent, 100, &dealer);
            print_round_ui(&agent, &dealer);
            printf("What would you like to do?[h]it/[s]tand/[d]ouble: ");
            char move_code = get_move();
            process_move(move_code, &agent);

            // auto check for broken hands at the end of the round
            if(calc_hand(agent.hand, agent.amt_of_cards) > 21) {
                agent.stood = true;
            }
            
        }

        // perform end-of-round subroutine, some of this might get moved
        // into the loop
        debug_state(&agent, &dealer);
        puts("Rolling dealer...");
        end_round_routine(&agent, &dealer);
        printf("End of Round. New [r]ound, new [g]ame or [q]uit?");
        char code = get_move();
        switch(code) {
            case 'r':
                puts("New Round!");
                agent.stood=false;
                break;
            case 'g':
                game_over = true;
                break;
            default:
                puts("What is wrong with you?");
                return;
        }
    }
}
