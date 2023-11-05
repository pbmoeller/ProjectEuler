#include "problems/problem_registry.hpp"
#include "math/divisors.hpp"
#include "math/sequences.hpp"

int64_t problem_12()
{
    int64_t n = 0;
    int64_t nextTrinangleNumber = 0;
    bool found = false;
    while(!found) {
        nextTrinangleNumber = calculate_nth_triangle_number(n);
        auto divisors = divisorsOf(nextTrinangleNumber);
        if(divisors.size() > 500) {
            found = true;
        }
        ++n;
    }
    return nextTrinangleNumber;
}

REGISTER_FUNCTION(12, problem_12);
