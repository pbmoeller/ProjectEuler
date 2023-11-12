#include "problems/problem_registry.hpp"

#include "math/divisors.hpp"

#include <vector>
#include <numeric>

int64_t problem_21()
{
    std::vector<int64_t> numberPairs(10001, 0);
    for(int64_t n = 2; n <= 10000; ++n) {
        auto d = pe::properDivisorsOf(n);
        numberPairs[n] = std::accumulate(d.begin(), d.end(), 0LL);
    }

    int64_t sum = 0;
    for(size_t idx = 2; idx <= 10000; ++idx) {
        if(numberPairs[idx] < 10000
           && idx == numberPairs[numberPairs[idx]]
           && idx != numberPairs[idx]) {
            sum += numberPairs[idx];
        }
    }

    return sum;
}

REGISTER_FUNCTION(21, problem_21);
