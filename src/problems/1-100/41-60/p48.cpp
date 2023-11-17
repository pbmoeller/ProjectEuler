#include "problems/problem_registry.hpp"

int64_t problem_48()
{
    int64_t sum = 0;
    for(int64_t i = 1; i <= 1000; ++i) {
        int64_t tmp = i;
        for(int64_t j = 1; j < i; ++j) {
            tmp *= i;
            tmp %= 10000000000;
        }
        sum += tmp;
    }
    return sum % 10000000000;
}

REGISTER_FUNCTION(48, problem_48);
