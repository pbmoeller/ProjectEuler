#include "problems/problem_registry.hpp"

#include <unordered_set>

int64_t problem_30()
{
    constexpr int64_t fifthPowerLUT[10] = {
        0,
        1 * 1 * 1 * 1 * 1,
        2 * 2 * 2 * 2 * 2,
        3 * 3 * 3 * 3 * 3,
        4 * 4 * 4 * 4 * 4,
        5 * 5 * 5 * 5 * 5,
        6 * 6 * 6 * 6 * 6,
        7 * 7 * 7 * 7 * 7,
        8 * 8 * 8 * 8 * 8,
        9 * 9 * 9 * 9 * 9,
    };
    constexpr int64_t maxNumber = 6 * fifthPowerLUT[9];

    int64_t totalSum = 0;
    for(int64_t i = 2; i <= maxNumber; ++i) {
        int64_t sum = 0;
        int64_t x = i;
        while(x > 0) {
            sum += fifthPowerLUT[x % 10];
            x /= 10;
        }
        if(sum == i) {
            totalSum += sum;
        }
    }

    return totalSum;
}

REGISTER_FUNCTION(30, problem_30);
