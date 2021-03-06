// 
// Created by Derek Rodriguez on 5/13/18.
//

#include <inttypes.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#ifndef BLACKJACK_GYM_GAMEINSTANCE_H
#define BLACKJACK_GYM_GAMEINSTANCE_H

#endif 

// card constant macros
#define ACE 0
#define JACK 10
#define QUEEN 11
#define KING 12

// game parameter macros
#define MAX_HAND_SIZE 8
#define AMT_OF_DECKS 6
#define MAX_BETS 4


typedef struct
{
    short hand[MAX_HAND_SIZE]; // place where cards are stored
    unsigned short amt_of_cards;// amt of cards
    unsigned int money; // amount of money in wallet
	 bool stood;
}player_t; //!< the datatype for storing player_t state

typedef struct
{
    player_t* bet_src; //<! mem address of player_t who placed this bet
    unsigned int qty; //<! amount placed by player, updates on double
} bet_t; //!< used as a log entry in the bet ledger.


static short SHOE[AMT_OF_DECKS * 52]; //!< many decks
static unsigned int TOP_OF_SHOE = 0; //!< index of top of deck
static bet_t POOL[MAX_BETS]; //!< all bet_ts placed during match go in the pool
static unsigned short CURR_AMT_OF_BETS = 0; //!< tracks amount of usage in the pool

void clear_hand(player_t *p); //! reset the hand of a player
void add_bet_t(player_t *p,  unsigned int bet_qty); //! add bet to list
void clear_bets(); //! wipe all bets from POOL
void shuffle_shoe(); //! shuffle the shoe
void deal(player_t *p, unsigned short amt_dealt); //! take cards from shoe at place them in the player_t's hand
short calc_hand(const short *hand, const unsigned short hand_len); //! get score of hand
char get_move(); //! read user input to perform move
void hit(player_t *p); //! get new card
void d_down(player_t *p); //! double down
void stand(player_t *p); //! stop handing out cards to this player_t
void split(player_t *p); //! split hand
void setup_new_game(player_t *p, unsigned int init_funds, player_t *d); //! routine for new game
void print_round_ui(); //! print human_friendly game state from player_t's POV
void debug_state(player_t *p, player_t *d); //! print current game state
void process_move(char code, player_t *p); //! perform action for player_t based on code
void end_round_routine(player_t *p, player_t *d); //! let dealer "play out", distribute payouts
void exec_game_loop(); //! main game loop
