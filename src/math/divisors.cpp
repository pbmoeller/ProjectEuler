#include "math/divisors.hpp"

#include <cmath>

std::vector<int64_t> divisorsOf(int64_t number) {
    std::vector<int64_t> divisors{1, number};
    int64_t sqrt_number = static_cast<int64_t>(std::sqrt(number)) + 1;
    for(int64_t n = 2; n < sqrt_number; ++n) {
        if(number % n == 0) {
            divisors.push_back(n);
            divisors.push_back(number / n);
        }
    }
    if(sqrt_number * sqrt_number == number) {
        divisors.push_back(sqrt_number);
    }

    return divisors;
}
