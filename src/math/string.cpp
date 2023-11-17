#include "math/string.hpp"

namespace pe {

bool isPalindrome(const std::string &str)
{
    int idx_fwd = 0;
    int idx_bwd = str.length() - 1;
    for(; idx_fwd <= idx_bwd; ++idx_fwd, --idx_bwd) {
        if(str[idx_fwd] != str[idx_bwd]) {
            return false;
        }
    }
    return true;
}

void removeLeadingChars(std::string &str, const char ch)
{
    size_t pos = 0;
    while(pos < str.length() && str[pos] == ch) {
        ++pos;
    }

    str.erase(0, pos);
}

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

std::string addStrings(const std::string &str1, const std::string &str2)
{
    size_t length1 = str1.length();
    size_t length2 = str2.length();
    size_t maxLength = std::max(length1, length2);
    std::string result;
    result.resize(maxLength);

    char carry = 0;
    for(size_t idx = 0; idx < maxLength; ++idx) {
        char digit1 = 0;
        if(idx < length1) {
            digit1 = str1[idx] - '0';
        }
        char digit2 = 0;
        if(idx < length2) {
            digit2 = str2[idx] - '0';
        }
        char sum = carry + digit1 + digit2;
        result[idx] = '0' + (sum % 10);
        carry = sum / 10;
    }
    while(carry > 0) {
        result.push_back('0' + (carry % 10));
        carry /= 10;
    }

    return result;
}

} // namespace pe
