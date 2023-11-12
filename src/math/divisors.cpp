#include "math/divisors.hpp"

#include <cmath>

namespace pe {

std::vector<int64_t> divisorsOf(int64_t number)
{
    std::vector<int64_t> divisors{1, number};
    int64_t sqrt_number = static_cast<int64_t>(std::sqrt(number));
    for(int64_t n = 2; n <= sqrt_number; ++n) {
        if(number % n == 0) {
            divisors.push_back(n);
            if(n * n != number) {
                divisors.push_back(number / n);
            }
        }
    }

    return divisors;
}

std::vector<int64_t> properDivisorsOf(int64_t number)
{
    std::vector<int64_t> divisors{1};
    int64_t sqrt_number = static_cast<int64_t>(std::sqrt(number));
    for(int64_t n = 2; n <= sqrt_number; ++n) {
        if(number % n == 0) {
            divisors.push_back(n);
            if(n * n != number) {
                divisors.push_back(number / n);
            }
        }
    }

    return divisors;
}

} // namespace pe
