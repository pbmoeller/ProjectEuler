#include "problems/problem_registry.hpp"
#include "math/string.hpp"

#include <string>

int64_t problem_20()
{
    // 100! is a very big number so we multiply it as a string
    std::string number = "1";
    int max = 100;
    for(int i = 2; i <= max; ++i) {
        pe::multiplyStringWith(number, i);
    }

    int64_t sumOfDigits = 0;
    for(int i = 0; i < number.size(); ++i) {
        sumOfDigits += (number[i] - '0');
    }

    return sumOfDigits;
}

REGISTER_FUNCTION(20, problem_20);
