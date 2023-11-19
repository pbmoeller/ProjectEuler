#include "problems/problem_registry.hpp"

#include <string>

// Digits   | Quantity      | Range                     | Digits in Range   | Total Digits := TD(d)
//    1     |   9x          | 1         - 9             | 9                 | 9
//    2     |   90x         | 10        - 99            | 180               | 189
//    3     |   900x        | 100       - 999           | 2700              | 2889
//    4     |   ...         | ...                       | ...               | ...
//    d     |   9*10^(d-1)  | 10^(d-1)  - 10^(d-1) - 1  | 9 * d * 10^(d-1)  | 9 * d * 10^(d-1) + TD(d-1)
//

int64_t nthDigit(int64_t n)
{
    int64_t k = 1;
    int64_t minDigitSum = 1;
    int64_t maxDigitSum = 9;
    while(n > maxDigitSum) {
        minDigitSum = maxDigitSum;
        ++k;
        maxDigitSum += k * 9 * std::pow(10, k - 1);
    }

    int64_t startingNumber = std::pow(10, k - 1);
    int64_t numberInRange = n - minDigitSum;
    int64_t number = startingNumber + numberInRange / k;
    int64_t digit = numberInRange % k;

    int64_t d = 0;
    std::string str = std::to_string(number);
    if(digit == 0) {
        d = str[str.size() - 1] - '0';
    } else {
        d = str[digit - 1] - '0';
    }

    return d;
}

int64_t problem_40()
{
    return nthDigit(1LL)
        * nthDigit(10LL)
        * nthDigit(100LL)
        * nthDigit(1000LL)
        * nthDigit(10000LL)
        * nthDigit(100000LL)
        * nthDigit(1000000LL);
}

REGISTER_FUNCTION(40, problem_40);
