//
// Created by BULENT DERVISOGLU on 12/14/25.
//

#ifndef POKER_RECOVERED_POKER_TYPES_H
#define POKER_RECOVERED_POKER_TYPES_H
//
// Created by Bulent Dervisoglu on 12/12/25.
//

#ifndef POKER_POKER_TYPES_H
#define POKER_POKER_TYPES_H
#include <iostream>
using namespace std;
#include <random>

// Main Card/Hand structures
enum C_Rank {XXX, ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT,SEVEN};
enum C_Suit {YYY, HEART, DIAMOND, CLUB, SPADE};
struct One_Card {
    C_Suit suit;// HEART through SPADE, YYY if not assigned (error!)
    C_Rank rank;// ACE through SEVEN, XXX if not yesy assigned (error!)
};

struct Dist_Prob {
    float dist;           // Number of ways distribution occurs
    float prob;          // Probability of distribution occuring
};


constexpr int HAND_SIZE = 6;        // I hate the "0" subscript, let it run from 1 to 5 for 5 cards
constexpr int DECK_SIZE = 33;       // I hate the "0" ssubscript, let it run from 1 to 32 for 32 cards

// There are 12 hands worth evaluating from Royal_Flush to Nothing
// These will be pre-computed in Poker_Primitives
constexpr   int NUM_DP = 13;        // Number of different Poker hands to be evaluated
/*
 *  0       Unused
 *  1       Royal Flush, = Straight-Flush ACE, KING, QUEEN, JACK TEN in any suit
 *  2       Straight Flush that excludes the Royal-Flush; includes TEN, NINE,EIGHT, SEVEN, ACE
 *  3       4-of-same-rank plus a 5th card
 *  4       Flush, five cards in any suit but not in sequencew
 *  5       Full-House
 *  6       3-of-a-kind
 *  7       Straight, not all same suit, includes TEN, NINE, EIGHT, SEVEN, ACE
 *  8       2-Pairs plus a 5th card
 *  9       1-Pair plus 3 separate cards
 *  10      4 cards, needs an Upper or lower card to form straight
 *  11      4 cards of same suit, needs a 5th card in same suit for ANY flush
 *  12      Nothing
 */
constexpr   long ways_ALL = 201376;
constexpr   long Royal_Flush = 1;
constexpr   long Straight_Flush = 2;
constexpr   long Four_of_a_Kind = 3;
constexpr   long Flush = 4;
constexpr   long Full_House = 5;
constexpr   long Three_of_a_Kind = 6;
constexpr   long Straight = 7;
constexpr   long Two_Pairs = 8;
constexpr   long One_Pair = 9;
constexpr   long Four_in_Sequence = 10;
constexpr   long Four_of_same_Suit = 11;
constexpr   long Nothing = 12;





// Declare a Global array to store some pre-determined [N:K] values
// comb_NK[N][K] gives the distribution and probability of N cards taken K at a time
// These will be pre-computed in Poker_Primitives

#endif //POKER_POKER_TYPES_H

#endif //POKER_RECOVERED_POKER_TYPES_H