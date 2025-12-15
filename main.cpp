#include <iostream>
using namespace std;
#include "Poker_Types.h"
#include "Functions.h"
#include "Probability.h"
// GLOBAL VARIABLES

// GLOBAL VARIABLES that will be included in any file which includes Power_Card_Types.h
One_Card CARD;                  // Generic, single card

One_Card WEST[HAND_SIZE];
One_Card NORTH[HAND_SIZE];
One_Card EAST[HAND_SIZE];
One_Card SOUTH[HAND_SIZE];
One_Card DECK[DECK_SIZE];
One_Card TMP_DECK[DECK_SIZE];

Dist_Prob DP[NUM_DP];

// long WAYS_ALL = 201376;                         // Equals to [32:5]
long ways_NK[DECK_SIZE][HAND_SIZE];             // Stores thre [N:K' values pre-computed before

int main() {

    // Do the basic computations for [N:K]
    if (!computations_NK()) {
        printf("PROGRAM FAILED\n");
        return 0;
    }

    Get_Fresh_Deck(DECK);

    // Shuffle the DECK
    Random_Deck (DECK);

    // Now sort rsch player's hand
    printf("\nWill sort WEST hand\n");
    Sort_Hand(WEST);

    printf("\nWill sort NORTH hand\n");
    Sort_Hand(NORTH);

    printf("\nWill sort EAST hand\n");
    Sort_Hand(EAST);

    printf("\nWill sort SOUTH hand\n");
    Sort_Hand(SOUTH);


   // Calculate the basic distributions and probabilities
    Probability();

}
