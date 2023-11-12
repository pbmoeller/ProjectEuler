#include "problems/problem_registry.hpp"
#include "math/sequences.hpp"

int64_t problem_14()
{
    int64_t longestChainNumber = 0;
    int maxSteps = 0;
    for(int64_t n = 1; n < 1'000'000; ++n) {
        int steps = 1;

        int64_t number = n;
        while(number != 1) {
            number = pe::calculate_next_collatz_number(number);
            ++steps;
        }
        if(steps > maxSteps) {
            maxSteps = steps;
            longestChainNumber = n;
        }
    }

    return longestChainNumber;
}

REGISTER_FUNCTION(14, problem_14);
