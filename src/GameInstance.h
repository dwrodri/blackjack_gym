//
// Created by Derek Rodriguez on 5/13/18.
//

#include <stdbool.h>

#ifndef BLACKJACK_GYM_GAMEINSTANCE_H
#define BLACKJACK_GYM_GAMEINSTANCE_H

#endif //BLACKJACK_GYM_GAMEINSTANCE_H

#define HAND_SIZE 10
#define SHOE_SIZE 312

static unsigned int SHOE[SHOE_SIZE];

typedef struct{
    short hand[HAND_SIZE];
    unsigned int money;
}player;

int calculate_hand(short *hand);
void get_move(); //read user input to perform move

void hit(); //get new card

void d_down(); //double down

void stand(); //stop handing out cards to this player

void split(); //split hand

void start_game(); // generate deck, shuffle deck, take bets and deal

bool is_over(); //check for bust

void dump_player_data(); //print player's money and hand

void exec_game_loop();

