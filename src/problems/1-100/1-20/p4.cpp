#include "problems/problem_registry.hpp"

#include <string>

bool isPalindrom(int number)
{
    std::string str = std::to_string(number);

    int idx_fwd = 0;
    int idx_bwd = str.length() - 1;
    for(; idx_fwd <= idx_bwd; ++idx_fwd, --idx_bwd) {
        if(str[idx_fwd] != str[idx_bwd]) {
            return false;
        }
    }
    return true;
}

int64_t problem_4()
{
    int largestPalindrom = 0;
    for(int a = 100; a <= 999; ++a) {
        for(int b = 100; b <= 999; ++b) {
            int product = a * b;
            if(product > largestPalindrom && isPalindrom(product)) {
                largestPalindrom = product;
            }
        }
    }

    return largestPalindrom;
}

REGISTER_FUNCTION(4, problem_4);
