#include "problems/problem_registry.hpp"

#include <vector>
#include <algorithm>
#include <numeric>

int64_t problem_16()
{
    const size_t MaxDigits = 1024;
    const int Exponent = 1000;

    // Vector of digits (in reverse order)
    std::vector<int64_t> digits(MaxDigits, 0);
    digits[0] = 1;
    size_t digitCount = 1;

    for(int i = 1; i <= Exponent; ++i) {
        // Multiply all used digits by 2. We handle overflow later.
        for(size_t j = 0; j < digitCount; ++j) {
            digits[j] *= 2;
        }

        // Handle the overflow
        for(size_t j = 0; j < digitCount; ++j) {
            digits[j + 1] += digits[j] / 10;    // add overflow to next digit
            digits[j] %= 10;                    // Take rest for current digit
            if(digits[j + 1] > 0) {
                // The next digit is now set - maybe through overflow. 
                // We increase the digitCount if it is not already higher.
                // Maximum needed, because we never want to decrease the number.
                digitCount = std::max(digitCount, j + 2);
            }
        }
    }

    return std::accumulate(digits.begin(), digits.end(), 0ll);
}

REGISTER_FUNCTION(16, problem_16);
