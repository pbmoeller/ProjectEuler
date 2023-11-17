#include "problems/problem_registry.hpp"
#include "math/string.hpp"

#include <bitset>
#include <string>

bool isDecimalNumberPalindromic(int64_t number)
{
    std::string decimal = std::to_string(number);
    return pe::isPalindrome(decimal);
}

bool isBinaryNumberPalindromic(int64_t number)
{
    std::string binary = std::bitset<20>(number).to_string();
    pe::removeLeadingChars(binary, '0');
    return pe::isPalindrome(binary);
}

int64_t problem_36()
{
    int64_t sum = 0;
    for(int64_t i = 0; i < 1'000'000; ++i) {
        if(isDecimalNumberPalindromic(i) && isBinaryNumberPalindromic(i)) {
            sum += i;
        }
    }

    return sum;
}

REGISTER_FUNCTION(36, problem_36);
