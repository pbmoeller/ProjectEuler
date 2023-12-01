#include "problems/problem_registry.hpp"

#include "math/primes.hpp"

#include <vector>
#include <numeric>

int64_t problem_27()
{
    // n^2 + a*n + b
    // |a| < 1000
    // |b| <= 1000
    // n? maybe also < 1000

    int64_t maxConsecutivePrimes = 0;
    int64_t consecutivePrimes = 0;
    int64_t productAB = 0;

    for(int64_t a = -999; a <= 999; ++a) {
        for(int64_t b = -1000; b <= 1000; ++b) {
            consecutivePrimes = 0;
            for(int64_t n = 0; n < 1000; ++n) {
                int64_t p = n * n + a * n + b;
                if(pe::isPrime(p)) {
                    ++consecutivePrimes;
                } else {
                    break;
                }
            }
            if(consecutivePrimes > maxConsecutivePrimes) {
                maxConsecutivePrimes = consecutivePrimes;
                productAB = a * b;
            }
        }
    }

    return productAB;
}

REGISTER_FUNCTION(27, problem_27);
