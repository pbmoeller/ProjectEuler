#include "problems/problem_registry.hpp"

int64_t sumOfSquares(int64_t first, int64_t last)
{
    int64_t sum = 0;
    for(int64_t i = first; i <= last; ++i) {
        sum += i * i;
    }
    return sum;
}

int64_t squareOfSum(int64_t first, int64_t last)
{
    int64_t sum = 0;
    for(int64_t i = first; i <= last; ++i) {
        sum += i;
    }
    return sum * sum;
}

int64_t problem_6()
{
    return squareOfSum(1, 100) - sumOfSquares(1, 100);
}

REGISTER_FUNCTION(6, problem_6);
