//
// Created by Derek Rodriguez on 5/13/18.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "GameInstance.h"

int calculate_hand(short *hand)
{
    return 0;
}
void get_move()
{

}

void hit()
{

}

void d_down()
{

}

void stand()
{

}
void start_game(int player_count)
{

    // generate deck
    for (unsigned int i = 0; i < SHOE_SIZE; ++i) {
        SHOE[i] = i%13;
    }

    for (unsigned int i = SHOE_SIZE-1; i > 0; i--)
    {
        // TODO: replace this with something better
        srand(time(NULL));
        // Pick a random index from 0 to i
        unsigned int j = rand() % (i+1);

        // Swap SHOE[i] with the element at random index
        unsigned int temp = SHOE[j];
        SHOE[j] = SHOE[i];
        SHOE[i] = temp;
    }
    
}

bool is_over()
{
    return 0;
}

void dump_player_data()
{

}

void exec_game_loop()
{

}








