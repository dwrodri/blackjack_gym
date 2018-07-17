// 
// Created by Derek Rodriguez on 5/13/18.
//
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

#ifndef BLACKJACK_GYM_GAMEINSTANCE_H
#define BLACKJACK_GYM_GAMEINSTANCE_H

#endif 

#define MAX_HAND_SIZE 8
#define AMT_OF_DECKS 6
#define MAX_BETS 4

// TYPEDEFS

typedef struct
{
    unsigned short hand[MAX_HAND_SIZE]; // place where cards are stored
    unsigned short amt_of_cards;// amt of cards
    unsigned int money; // amount of money in wallet
	bool stood;
}player; //!< the datatype for storing player state

typedef struct
{
    player* bet_src; //<! mem address of player
    unsigned int qty; 
}bet; //!< Think of this as like a log entry for the bets being placed. The actual ledger is the array. 


static unsigned short SHOE[AMT_OF_DECKS * 52]; //!< many decks
static unsigned int TOP_OF_SHOE = 0; //!< index of top of deck
static bet POOL[MAX_BETS]; //!< all bets placed during match go in the pool
static unsigned short CURR_AMT_OF_BETS = 0; //!< this doubles as the tracker for the POOL list 


void add_bet(player *p,  unsigned int bet_qty); //! add bet to list
void clear_bets(); //! wipe all bets from POOL
void shuffle_shoe(); //! shuffle the shoe
void deal(player *p); //! take cards from shoe at place them in the player's hand
const short calc_hand(const unsigned short *hand, const unsigned short hand_len); //! get score of hand
void get_move(); //! read user input to perform move
void hit(player *p); //! get new card
void d_down(player *p); //! double down
void stand(player *p); //! stop handing out cards to this player
void split(player *p); //! split hand
void setup_new_game(player *p, unsigned int init_funds, player *d); //! routine for new game
const bool is_over(); //! check for bust
void print_game_UI(); //! print human_friendly game state from player's POV
void debug_state(player *p, player *d); //! print current game state
void exec_game_loop(); //!main game loop

