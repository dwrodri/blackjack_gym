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
}

void clear_bets()
{
    CURR_AMT_OF_BETS = 0;
}

void shuffle_shoe()
{
    for (unsigned int i = SHOE_SIZE-1; i > 0; i--)
    {
        // TODO: replace srand with something more secure
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

unsigned int calc_hand(short *hand)
{
    return 0;
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
    for (unsigned short i = 0; i < SHOE_SIZE; ++i) {
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
    dump(p, d);

}

bool is_over()
{
    return 0;
}

void dump(player *p, player *d)
{
    puts("==========GAME STATE==========");
    printf("Player %x:\n", (unsigned int)p);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < p->amt_of_cards; i++){
        printf("%i\t", p->hand[i]);
    }
    printf("\n");
    printf("\tBalance: %d\n", p->money);
    puts("---");

    printf("Dealer: %x:\n", (unsigned int)d);
    printf("\tHand:\t");
    for(unsigned short i = 0; i < d->amt_of_cards; i++){
        printf("%i\t", d->hand[i]);
    }
    printf("\n");
    puts("---");


}

void exec_game_loop()
{
    player agent, dealer;
    setup_new_game(&agent, 100, &dealer);

}