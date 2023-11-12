#include "problems/problem_registry.hpp"
#include "math/primes.hpp"

#include <numeric>

int64_t problem_10()
{
    int64_t sum = 0;
    auto primes = pe::generate_primes_below(2'000'000);
    sum = std::accumulate(primes.begin(), primes.end(), sum);
    return sum;
}

REGISTER_FUNCTION(10, problem_10);
