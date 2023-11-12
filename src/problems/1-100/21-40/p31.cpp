#include "problems/problem_registry.hpp"

constexpr int64_t CoinValues[8] = {
    200,
    100,
    50,
    20,
    10,
    5,
    2,
    1
};

void addCoins(int coin, int64_t currentSum, int64_t &count, const int64_t maxSum)
{
    int64_t steps = maxSum / CoinValues[coin];
    for(int64_t i = 0; i <= steps; ++i) {
        int64_t newSum = currentSum + CoinValues[coin] * i;
        
        if(newSum == maxSum) {
            ++count;
            return;
        }
        if(newSum > maxSum) {
            return;
        }

        if(coin < 7) {
            addCoins(coin + 1, newSum, count, maxSum);
        }
    }
}

int64_t problem_31()
{
    const int64_t maxSum = 200;
    int64_t count = 0;
    addCoins(0LL, 0LL, count, maxSum);

    return count;
}

REGISTER_FUNCTION(31, problem_31);
