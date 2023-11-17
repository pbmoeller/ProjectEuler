#ifndef PROJECT_EULER_MATH_STRING_HPP
#define PROJECT_EULER_MATH_STRING_HPP

#include <string>
#include <cstdint>

namespace pe {

bool isPalindrome(const std::string &str);
void removeLeadingChars(std::string &str, const char ch);
size_t multiplyStringWith(std::string &number, int n);
std::string addStrings(const std::string &str1, const std::string &str2);

} // namespace pe

#endif // PROJECT_EULER_MATH_STRING_HPP
