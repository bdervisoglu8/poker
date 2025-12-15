//
// Created by BULENT DERVISOGLU on 12/14/25.
//
//
// Created by Bulent Dervisoglu on 12/13/25.
//

#include "Probability.h"


// Compute Distribution # and Probability % for all poker hands that are to be analyzed

void Probability () {

extern Dist_Prob DP[NUM_DP];
extern long ways_NK[DECK_SIZE][HAND_SIZE];

/*
constexpr   long WAYS_ALL = 201376;
constexpr   int Royal_Flush = 1;
constexpr   int Straight_Flush = 2;
constexpr   int Four_of_a_Kind = 3;
constexpr   int Flush = 4;
constexpr   int Full_House = 5;
constexpr   int Three_of_a_Kind = 6;
constexpr   int Straight = 7;
constexpr   int Two_Pairs = 8;
constexpr   int One_Pair = 9;
constexpr   int Four_in_Sequence = 10;
constexpr   int Four_of same_Suit = 11;
constexpr   int Nothing = 12;
 */

    for (int code = 1; code <= NUM_DP; code ++) {

        switch (code) {
            // Royal Flush:Any of 4 suits, each having only one way ACE, KING, QUEEN, JACK, TEN
            case (Royal_Flush):
                {DP[Royal_Flush].dist = 4;
                DP[Royal_Flush].prob = DP[Royal_Flush].dist / ways_ALL;
                printf("Royal_Flush:                Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Royal_Flush].dist, 100*DP[Royal_Flush].prob);
                break;}

                // Royal Straight:Any of 4 suits, each having 4 possible ways startingh with a KING or QUEEN or JACK or TEN
            case (Straight_Flush): {
                DP[Straight_Flush].dist = 4*4;
                DP[Straight_Flush].prob = DP[Straight_Flush].dist / ways_ALL;
                printf("Straıght_Flush:             Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Straight_Flush].dist, 100*DP[Straight_Flush].prob);
                break;}
                // There 8 possible Four-of-a-Kind distribution and the 5th card is 1 of remaining 7 ranks times 4 suits
            case (Four_of_a_Kind): {
                DP[Four_of_a_Kind].dist = 8*7*4;
                DP[Four_of_a_Kind].prob = DP[Four_of_a_Kind].dist / ways_ALL;
                printf("Four_of_a_Kind:             Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Four_of_a_Kind].dist, 100*DP[Four_of_a_Kind].prob);
                break;}
                // 5 cards of same suit out of 8 times 4 suits but take away Straight_Flush and Royal_Flush
            case (Flush): {
                DP[Flush].dist = ways_NK[8][5] * 4 - DP[Straight_Flush].dist - DP[Royal_Flush].dist;
                DP[Flush].prob = DP[Flush].dist / ways_ALL;
                printf("Flush:                      Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Flush].dist, 100*DP[Flush].prob);
                break;}
                // 8 Ranks each taken in [4:3] ways and remaining 7 ranks each taken in [4:2] ways
            case (Full_House): {
                DP[Full_House].dist = ways_NK[4][3] * 8 * ways_NK[4][2] * 7;
                DP[Full_House].prob = DP[Full_House].dist / ways_ALL;
                printf("Full_House:                 Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Full_House].dist, 100*DP[Full_House].prob);
                break;}
                // 8 ranks each taken in any of [4:3] ways and remaining 7 ranks taken in [7:2] ways and 4 * 4 suits
            case (Three_of_a_Kind): {
                DP[Three_of_a_Kind].dist = ways_NK[4][3] * 8 * ways_NK[7][2] * 4 * 4;
                DP[Three_of_a_Kind].prob = DP[Three_of_a_Kind].dist / ways_ALL;
                printf("Three_of_a_Kind =           Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Three_of_a_Kind].dist, 100*DP[Three_of_a_Kind].prob);
                break;}
                // 5 sequences starting with ACE, or KING, or QUEEN, or JACK, OR TEN x each card can be in any of 4 suits, minus Straight Flush or Royal Flush
            case (Straight): {
                DP[Straight].dist = 5 * 4 * 4 * 4 * 4 * 4 - DP[Royal_Flush].dist - DP[Straight_Flush].dist;
                DP[Straight].prob = DP[Straight].dist / ways_ALL;
                printf("Straight =                  Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Straight].dist, 100*DP[Straight].prob);
                break;}
                // 8 ranks taken in [4:2] ways times remaining 7 ranks taken in [4:2] ways times 6 ranks in 4 colors
            case (Two_Pairs): {
                DP[Two_Pairs].dist = 8 * ways_NK[4][2] * 7 * ways_NK[4][2] * 6 * 4;
                DP[Two_Pairs].prob = DP[Two_Pairs].dist / ways_ALL;
                printf("Two_Pairs =                 Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Two_Pairs].dist, 100*DP[Two_Pairs].prob);
                break;}
                // 8 ranks taken in [4:2] ways times 7 ranks taken 3 at a time in 4 x 4 x 4 suits
            case (One_Pair): {
                DP[One_Pair].dist = ways_NK[4][2] * 8 * ways_NK[7][3] * 4 * 4 * 4;
                DP[One_Pair].prob = DP[One_Pair].dist / ways_ALL;
                printf("One_Pair =                  Distribution = %6.0f,       Probability = %6.3f%%\n", DP[One_Pair].dist, 100*DP[One_Pair].prob);
                break;}
                // 4 sequences Starting with KING, or QUEEN, or JACK, OR TEN each in any of 4 suits times last card in any of 2 ranks times 3 suits
            case (Four_in_Sequence): {
                DP[Four_in_Sequence].dist = 4 * 4 * 4 * 4 * 4 * 2 * 3;
                DP[Four_in_Sequence].prob = DP[Four_in_Sequence].dist / ways_ALL;
                printf("Four_in_sequence =          Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Four_in_Sequence].dist, 100*DP[Four_in_Sequence].prob);
                break;}
                // 4 out of 8 cards in same suit times 4 suits ties last card in any 1 of remaining 4 ranks times 3 suits
            case (Four_of_same_Suit): {
                DP[Four_of_same_Suit].dist = ways_NK[8][4] * 4 * ways_NK[4][1] * 3;
                DP[Four_of_same_Suit].prob = DP[Four_of_same_Suit].dist / ways_ALL;
                printf("Four_of_same_Suit =         Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Four_of_same_Suit].dist, 100*DP[Four_of_same_Suit].prob);
                break;}
                // All remaining hands: ways_ALL - sum of the cases above
            case (Nothing): {
                DP[Nothing].dist = ways_ALL - (DP[Royal_Flush].dist + DP[Straight_Flush].dist + DP[Four_of_a_Kind].dist +
                    DP[Flush].dist + DP[Full_House].dist + DP[Three_of_a_Kind].dist + DP[Straight].dist +
                        DP[Two_Pairs].dist + DP[One_Pair].dist + DP[Four_of_same_Suit].dist + DP[Four_in_Sequence].dist);
                DP[Nothing].prob = DP[Nothing].dist/ways_ALL;
                printf("Nothing =                   Distribution = %6.0f,       Probability = %6.3f%%\n", DP[Nothing].dist, 100*DP[Nothing].prob);
                break;}
            }

        }
}

