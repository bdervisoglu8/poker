//
// Created by BULENT DERVISOGLU on 12/14/25.
//
//
// Created by Bulent Dervisoglu on 12/6/25.
//
#include "Poker_Types.h"
#include "Primitives.h"
// These are the externally declared hands for 4 players

C_Suit Card_Suit;
C_Rank Card_Rank;

// local extern values
extern long ways_NK[DECK_SIZE][HAND_SIZE];
extern int DECK_NK[DECK_SIZE];

// Build a "Newly Opened" card deck with all suits and ranks in order
void Get_Fresh_Deck (One_Card DECK[DECK_SIZE]) {
// Go through all 4 suits in HEART, DIAMOND, CLUB, SPADE order
    int number;
    number = 0;
    for (int i = 1; i <= 4; i++) {
        if (i == 1) {Card_Suit = HEART;}
        else if (i == 2) {Card_Suit = DIAMOND;}
        else if (i == 3) {Card_Suit = CLUB;}
        else if (i == 4) {Card_Suit = SPADE;}
        // Gi through akk ranks in ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN order
        for (int j = 1; j <= 8; j++) {
            switch (j) {
                case 1: {Card_Rank = ACE; break;}
                case 2: {Card_Rank = KING; break;}
                case 3: {Card_Rank = QUEEN; break;}
                case 4: {Card_Rank = JACK; break;}
                case 5: {Card_Rank = TEN; break;}
                case 6: {Card_Rank = NINE; break;}
                case 7: {Card_Rank = EIGHT; break;}
                case 8: {Card_Rank = SEVEN; break;
            }
            }
            number++;
            // put the selected card into the next position in DECK
            DECK[number].suit = Card_Suit;
            DECK[number].rank  = Card_Rank;
            printf("DECK[%d]: suit = %d , Rank = %d\n", i, DECK[number].suit, DECK[number].rank);
        }
    }
    // DECK is now ordered in HEART[ACE, KING, ...] through SPADE[ACE, KING, ..] order
}

//====================================================================

// Build a randomly shuffled card deck
void Random_Deck (One_Card DECK[DECK_SIZE]) {
extern One_Card WEST[HAND_SIZE];
extern One_Card NORTH[HAND_SIZE];
extern One_Card EAST[HAND_SIZE];
extern One_Card SOUTH[HAND_SIZE];

One_Card TMP_DECK[DECK_SIZE];

int Tmp_File [DECK_SIZE];
int i, j, number;
printf("Entered Random_Deck\n");

    // First move DECK into TMP_DECK
    for (i = 1; i <= 32; i++) {
        TMP_DECK[i] = DECK[i];          // This statement works because both TEMP_DECK and DECK are structures of same type
    }

    for (i = 1; i <= 32; i++) {
    // Indicate this number has not been drawn yet
        Tmp_File [i] = 0;
    }

    // Now generate 32 randomly selected UNIQUE numbers
    i = 1;
    while (i <= 32) {
        number = generateRandomInt(1, 32);
        while (Tmp_File[number] != 0) {
            number = generateRandomInt(1, 32);
        }
        Tmp_File[number] = i;
        i++;
    }

    // Move cards from TMP_DECK to DECK as indicated by the positions in TMP_File
    // Tmp_File[] contains 32 randomly selected number
    // Now move the cards from DECK pointed by the Tmp_File into the WEST, NORTH, EAST, and SOUTH hands
    // DECK may or may not be in any particular order.
    for (i = 1; i <= 32; i++) {
        DECK[i].suit = TMP_DECK[Tmp_File[i]].suit;
        DECK[i].rank = TMP_DECK[Tmp_File[i]].rank;
    }
    // Now move cards into the individual player hands
    int offset = 0;
    printf("\n");
    for (i = 1; i <= 5; i++) {
        WEST[i].suit = DECK[offset + i].suit;
        WEST[i].rank = DECK[offset + i].rank;
        printf("WEST[%d]: suit = %d , rank = %d\n", i,WEST[i].suit, WEST[i].rank);
    }
    offset = 5;
        printf("\n");
        for (i = 1; i <= 5; i++) {
        NORTH[i].suit = DECK[offset + i].suit;
        NORTH[i].rank = DECK[offset + i].rank;
        printf("NORTH[%d]: suit = %d , rank = %d\n", i,NORTH[i].suit, NORTH[i].rank);
    }
    offset = 10;
    printf("\n");
    for (i = 1; i <= 5; i++) {
        EAST[i].suit = DECK[offset + i].suit;
        EAST[i].rank = DECK[offset + i].rank;
        printf("EAST[%d]: suit = %d , rank = %d\n", i,EAST[i].suit, EAST[i].rank);
    }
    offset = 15;

    for (i = 1; i <= 5; i++) {
        SOUTH[i].suit = DECK[offset + i].suit;
        SOUTH[i].rank = DECK[offset + i].rank;
        printf("SOUTH[%d]: suit = %d , rank = %d\n", i,SOUTH[i].suit, SOUTH[i].rank);
    }

    // print the remaining DECK
    printf("\n\n");
    for (i = 21; i <= 32; i++) {
    printf("DECK[%d]: suit = %d , rank = %d\n", i,DECK[i].suit, DECK[i].rank);
    }
    printf("\n\nRandom_Deck completed\n");
}


// =================================================================
// Functiomn to sort a given HAND;
void Sort_Hand (One_Card HAND[HAND_SIZE]) {
    int pos, i, j;
    One_Card TMP_CARD;
    // Start by assuming the card at position "p[os" has the smallest rank of all cards in the same hand\n");
    printf("\nSort a new hand\n");
    for (i = 1; i <= HAND_SIZE - 1; i++) {
        printf("HAND[%d].suit = %d , .rank = %d\n",i,HAND[i].suit, HAND[i].rank);
    }
    pos = 1;
    while (pos < 5){
        i = pos + 1;
        // Compare card at pos to all other cards in the same hand;
        while (i <= 5) {
            if ((HAND[pos].rank < HAND[i].rank) || (HAND[pos].rank == HAND[i].rank) && (HAND[pos].suit < HAND[i].suit)){
                // HAND[pos] rank is smaller than HAND[i]. Move down to next i
                i++;
                }
                else {
                    // Card at HAND[i] is smaller than HAND[pos]. Interchange Cards a HAND[pos] and HAND[i]
                    TMP_CARD = HAND[pos];
                    HAND[pos] = HAND[i];
                    HAND[i] = TMP_CARD;
                    // Make this card the new sma;llest at HAND[pos]
                    pos = 1;
                    i = pos+1;
                }
            }
    // Card at HAND[pos] shold stay at the top. Move pos down by 1 and repeat
        pos++;
        i = pos + 1;
    }
    // HAND has been sorted
    printf("AFTER SORTING\n");
    for (i = 1; i <= 5; i++)
        printf("HAND[%d].suite = %d , HAND[%d].rank = %d\n",i, HAND[i].suit, i, HAND[i].rank);
}


bool computations_NK(){
    for (int N = 1; N <= 32; N++) {
        for (int K = 1; K <= 5; K++) {
            ways_NK[N][K] = compute_NK(N, K);
        }
    }
    // Do a cursory check
    if (ways_NK[32][5] != ways_ALL) {
        printf("ERROR in cumpute_NK: ways_NK[32][5] = %ld , ways_ALL = %ld\n",ways_NK[32][5], ways_ALL);
        return false;
    }
    return true;
}

