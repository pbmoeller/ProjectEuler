#include "problems/problem_registry.hpp"

int64_t problem_3()
{
    int64_t number = 600851475143;
    int64_t maxFactor = 1;
    int64_t z = 2;
    while(z * z <= number) {
        if(number % z == 0) {
            maxFactor = z;
            number /= z;
        } else {
            ++z;
        }
    }
    if(number > 1) {
        maxFactor = number;
    }

    return maxFactor;
}

REGISTER_FUNCTION(3, problem_3);
