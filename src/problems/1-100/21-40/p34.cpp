#include "problems/problem_registry.hpp"

#include "math/math.hpp"

int64_t problem_34()
{
    // These numbers are called 'factorion'. Only 4 of them exist, where 1 and 2 are discared
    // by the problem. The tricky task is to find an upper bound. 1M is just a goof guess which can
    // easily be calculated.
    // https://de.wikipedia.org/wiki/Faktorion

    constexpr int64_t factorials[10] = {
        pe::factorial(0), pe::factorial(1), pe::factorial(2), pe::factorial(3), pe::factorial(4),
        pe::factorial(5), pe::factorial(6), pe::factorial(7), pe::factorial(8), pe::factorial(9)
    };

    int64_t totalSum = 0;
    for(int64_t i = 3; i < 1'000'000; ++i) {
        int64_t sum = 0;
        int64_t x = i;
        while(x > 0) {
            sum += factorials[x % 10];
            x /= 10;
        }
        if(sum == i) {
            totalSum += sum;
        }
    }

    return totalSum;
}

REGISTER_FUNCTION(34, problem_34);
