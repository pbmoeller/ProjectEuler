#include "problems/problem_registry.hpp"
#include "math/string.hpp"

#include <string>

int64_t problem_4()
{
    int largestPalindrom = 0;
    for(int a = 100; a <= 999; ++a) {
        for(int b = 100; b <= 999; ++b) {
            int product = a * b;
            std::string productString = std::to_string(product);
            if(product > largestPalindrom && pe::isPalindrome(productString)) {
                largestPalindrom = product;
            }
        }
    }

    return largestPalindrom;
}

REGISTER_FUNCTION(4, problem_4);
