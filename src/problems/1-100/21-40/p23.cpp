#include "problems/problem_registry.hpp"
#include "math/divisors.hpp"

#include <vector>
#include <numeric>

int64_t problem_23()
{
    // Calculate abundant Numbers 
    const int64_t upperLimit = 28123;
    std::vector<int64_t> abundantNumbers;
    for(int64_t n = 4; n < upperLimit; ++n) {
        std::vector<int64_t> properDivisors = properDivisorsOf(n);
        int64_t sum = std::accumulate(properDivisors.begin(), properDivisors.end(), 0LL);
        if(sum > n) {
            abundantNumbers.push_back(n);
        }
    }

    // Calculate sum of abundant numbers below upperLimit
    std::vector<bool> sumOfAbundantNumbers(upperLimit, false);
    for(int64_t abundantNumber1 : abundantNumbers) {
        for(int64_t abundantNumber2 : abundantNumbers) {
            int64_t sum = abundantNumber1 + abundantNumber2;
            if(sum < upperLimit) {
                sumOfAbundantNumbers[sum] = true;
            }
        }
    }

    // Sum of all numbers which are not a sum of abundant numbers
    int64_t sum = 0;
    for(int64_t i = 0; i < sumOfAbundantNumbers.size(); ++i) {
        if(!sumOfAbundantNumbers[i]) {
            sum += i;
        }
    }

    return sum;
}

REGISTER_FUNCTION(23, problem_23);
