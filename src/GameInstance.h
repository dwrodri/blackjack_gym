//
// Created by Derek Rodriguez on 5/13/18.
//

#include <stdbool.h>

#ifndef BLACKJACK_GYM_GAMEINSTANCE_H
#define BLACKJACK_GYM_GAMEINSTANCE_H

#endif //BLACKJACK_GYM_GAMEINSTANCE_H

#define HAND_SIZE 8
#define SHOE_SIZE 312
#define MAX_BETS 4

// TYPEDEFS

typedef struct
{
    short hand[HAND_SIZE]; // the amount of cards in hand
    unsigned int money; // amount of money in wallet
}player;

typedef struct
{
    player* bet_source; //
    unsigned int qty;

}bet;

// GLOBAL VARIABLES

static unsigned short SHOE[SHOE_SIZE]; // shoe = 6 decks
static unsigned int TOP_OF_SHOE = 0; // index of top of deck
static bet POOL[MAX_BETS]; // all bets placed during match go in the pool
static unsigned short CURR_AMT_OF_BETS = 0; 

//PROTOTYPES

void add_bet(player *p,  unsigned int bet_qty); // add bet to list
void clear_bets(); // wipe all bets from POOL
void shuffle_shoe(); // shuffle the shoe
void deal(player *p); //
unsigned int calc_hand(short *hand); // get score of hand
void get_move(); // read user input to perform move
void hit(); // get new card
void d_down(); // double down
void stand(); // stop handing out cards to this player
void split(); // split hand
void setup_new_game(player *p, unsigned int init_funds, player *d); // routine for new game
bool is_over(); // check for bust
void dump(player *p, player *d); // print current game state
void exec_game_loop(); //main game loop

