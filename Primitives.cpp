//
// Created by BULENT DERVISOGLU on 12/14/25.
//
//
// Created by Bulent Dervisoglu on 12/6/25.
//
#include <iostream>
using namespace std;
#include <random>
#include <chrono>
//>>>>>>>>>>>>>>RANDOM NUMBER VGENERATOR>>>>>>>>>>>>>>>>>>>>>>>
/*
 * @brief Generates a random integer between min and max (inclusive).
 * * @param min The lower bound of the range.
 * @param max The upper bound of the range.
 * @return A randomly generated integer.
 */
int generateRandomInt(int min, int max) {
    // 1. Create a random number generator engine (Mersenne Twister is high-quality)
    // We seed the engine using the current time for better randomness.
    static std::mt19937_64 engine(
    std::chrono::high_resolution_clock::now().time_since_epoch().count()
    );

    // 2. Define the distribution
    // std::uniform_int_distribution ensures a uniform chance for every number in the range [min, max]
    std::uniform_int_distribution<int> distribution(min, max);

    // 3. Generate and return the number
    return distribution(engine);
}



long compute_NK(int N, int K) {
    if (K < 0 || K > N) {
        return 0; // Invalid input: cannot choose a negative number or more than available
    }
    // Optimization: C(N, K) is the same as C(N, N-K).
    // Choosing the smaller K simplifies the calculation and reduces iterations.

    // Base cases
    if (K == 0 || K == N) {
        return 1;
    }
    if (K == 1) {
        return N;
    }

    // Iterative calculation: (N * (N-1) * ... * (N-K+1)) / K!
    long result = 1;
    for (int i = 1; i <= K; ++i) {
        // We multiply the result by (N - i + 1) and then divide by i.
        // This distributes the division step, helping to keep intermediate results smaller.
        result = result * (N - i + 1) / i;
    }
    return result;
}


