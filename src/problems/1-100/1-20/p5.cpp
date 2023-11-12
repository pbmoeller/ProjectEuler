#include "problems/problem_registry.hpp"
#include "math/divisors.hpp"

#include <set>
#include <vector>
#include <algorithm>

int64_t problem_5()
{
    std::vector<int64_t> requiredDivisors{
         1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    };
    int64_t maxNumber = 1;
    for(int i = 0; i < requiredDivisors.size(); ++i) {
        maxNumber *= requiredDivisors[i];
    }
    std::vector<int64_t> divisors = pe::divisorsOf(maxNumber);

    std::sort(divisors.begin(), divisors.end());
    
    int smallestDivisor = 0;
    for(int64_t divisor : divisors) {
        bool all = true;
        for(int64_t requiredDivisor : requiredDivisors) {
            if(divisor % requiredDivisor != 0) {
                all = false;
                break;
            }
        }
        if(all) {
            smallestDivisor = divisor;
            break;
        }
    }

    return smallestDivisor;
}

REGISTER_FUNCTION(5, problem_5);
