#include "problems/problem_registry.hpp"

#include <string>

size_t multiplyStringWith(std::string &number, int n)
{
    size_t length = number.size();
    int carry = 0;
    for(int i = 0; i < length; ++i) {
        int digit = number[i] - '0';
        int newDigit = n * digit + carry;
        number[i] = newDigit % 10 + '0';
        carry = newDigit / 10;
    }
    while(carry > 0) {
        int newDigit = carry % 10;
        number += (static_cast<char>(newDigit) + '0');
        carry /= 10;
    }

    return number.length();
}

int64_t problem_20()
{
    // 100! is a very big number so we multiply it as a string
    std::string number = "1";
    int max = 100;
    for(int i = 2; i <= max; ++i) {
        multiplyStringWith(number, i);
    }

    int64_t sumOfDigits = 0;
    for(int i = 0; i < number.size(); ++i) {
        sumOfDigits += (number[i] - '0');
    }

    return sumOfDigits;
}

REGISTER_FUNCTION(20, problem_20);
