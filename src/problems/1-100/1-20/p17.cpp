#include "problems/problem_registry.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> zeroToNineteen = {
    "", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

std::vector<std::string> tens = {
    "",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

std::string toWord(int number)
{
    if(number == 0) {
        return "zero";
    } else if(number == 1000) {
        return "one thousand";
    }
    std::string word{""};

    int digits[3] = {0, 0, 0};
    digits[2] = number % 10;
    int d = number % 100;
    number /= 10;
    digits[1] = number % 10;
    number /= 10;
    digits[0] = number % 10;

    if(digits[0] > 0) {
        word += zeroToNineteen[digits[0]] + " hundred";
    }
    if(d > 0 && digits[0] > 0) {
        word += " and ";
    }
    if(d >= 1 && d <= 19) {
        word += zeroToNineteen[d];
    } else if(d >= 20 && d <= 99) {
        word += tens[digits[1]] + "-" + zeroToNineteen[digits[2]];
    }

    return word;
}

int64_t countLetters(const std::string &str)
{
    return std::count_if(str.begin(), str.end(), std::isalpha);
}

int64_t problem_17()
{
    int64_t letters = 0;
    for(int i = 1; i <= 1000; ++i) {
        std::string numberWord = toWord(i);
        letters += countLetters(numberWord);
    }

    return letters;
}

REGISTER_FUNCTION(17, problem_17);
