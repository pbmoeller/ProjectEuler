#include "problems/problem_registry.hpp"

#include "math/primes.hpp"

int64_t problem_35()
{
    std::vector<int64_t> primes = pe::generate_primes_below(1'000'000);

    int64_t count = 0;
    for(int64_t p : primes) {
        if(pe::isCircularPrime(p)) {
            ++count;
        }
    }

    return count;
}

REGISTER_FUNCTION(35, problem_35);
