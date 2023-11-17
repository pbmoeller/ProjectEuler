#include "problems/problem_registry.hpp"

int64_t problem_1()
{
    int64_t sum = 0;
    for(int64_t i = 1; i < 1000; ++i) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

REGISTER_FUNCTION(1, problem_1);
