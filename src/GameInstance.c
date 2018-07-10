//
// Created by Derek Rodriguez on 5/13/18.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "GameInstance.h"

void add_bet(player *p, unsigned int bet_qty)
{
    POOL[CURR_AMT_OF_BETS].bet_source = p;
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
    for (unsigned int i = (AMT_OF_DECKS*52)-1; i > 0; i--)
    {
        // TODO: make this more random
        srand(time(NULL));
        // Pick a random index from 0 to i
        unsigned int j = rand() % (i+1);

        // Swap SHOE[i] with the element at random index
        unsigned int temp = SHOE[j];
        SHOE[j] = SHOE[i];
        SHOE[i] = temp;
    }
}

void deal(player *p)
{
    p->hand[p->amt_of_cards] = SHOE[TOP_OF_SHOE++];
    p->hand[p->amt_of_cards + 1] = SHOE[TOP_OF_SHOE++];
    p->amt_of_cards += 2;
}

void get_move()
{

}

const short calc_hand(const unsigned short *hand, const unsigned short hand_len)
{
    short score = 0;
    for(unsigned short i = 0; i < hand_len; i++) {

        switch (hand[i])
        {
        case 0: // use sign bit to track if ace is in player's hand
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

void hit(player *p)
{

}

void d_down(player *p)
{

}

void stand(player *p)
{

}

void split(player *p)
{

}

void setup_new_game(player *p, unsigned int init_funds, player *d)
{
    // clean up players
    p->amt_of_cards = 0;
    d->amt_of_cards = 0;
    char* prompt = "Welcome to BJGym. You will be starting this round with %i credits.";
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
    add_bet(p, strt_bet_qty);

    // give cards to player and dealer
    deal(p);
    deal(d);

    // DEBUG: dump state
    debug_state(p, d);

}

const bool is_over()
{
    return 0;
}

void debug_state(player *p, player *d)
{
    puts("==========GAME STATE==========");
    printf("Player %x:\n", (unsigned int)p);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < p->amt_of_cards; i++) {

        switch (p->hand[i])
        {
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

    printf("Dealer: %x:\n", (unsigned int)d);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < d->amt_of_cards; i++) {

        switch (d->hand[i])
        {
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

    printf("Bet:\tplayer\t\tqty\n");

    for(short i = 0; i < CURR_AMT_OF_BETS; i++)
    {
        printf("\t%x\t%i\n", (unsigned int)POOL[i].bet_source, POOL[i].qty);
    }
    printf("---\n");

}

char get_player_decision(player *ag)
{
    printf("What would you like to do?[h]it/[s]tand/[d]ouble: ");
    char userin[2];
    scanf("%s", userin);
    return *userin;
}

void process_move(char code)
{
    switch(code) {
    case 'h' :
        puts("you hit!");
        break;
    case 's' :
        puts("you stood!");
        break;
    case 'd' :
        puts("doubling down!");
        break;
    default:
        puts("BROKEN");
        break;
    }
}

void exec_game_loop()
{
    player agent, dealer; // instantiate players
    agent.stood = false;
    setup_new_game(&agent, 100, &dealer);
    char move_code = get_player_decision(&agent);
    process_move(move_code);
}
