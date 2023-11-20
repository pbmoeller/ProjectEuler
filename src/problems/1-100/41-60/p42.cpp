#include "problems/problem_registry.hpp"
#include "math/io.hpp"

//          t_n                 = n/2 (n + 1)
//  <=>     2 * t_n             = n^2 + n
//  <=>     2 * t_n + 1/4       = n^2 + 1/2 * 2n + (1/2)^2 
//  <=>     2 * t_n + 1/4       = (n + 1/2)^2 
//  <=>     sqrt(2 * t_n + 1/4) = (n + 1/2)
//  <=>     n                   = sqrt(2 * t_n + 1/4) - 1/2
//

bool isTriangular(const int64_t number)
{
    double n = std::sqrt(2.0 * number + 0.25) - 0.5;
    return n == static_cast<int64_t>(n);
}

bool isTriangular(const std::string &word)
{
    int64_t number = 0;
    for(size_t i = 0; i < word.length(); ++i) {
        number += (word[i] - 'A' + 1);
    }
    return isTriangular(number);
}

int64_t problem_42()
{
    std::string fileContent = pe::readFile("data/p42_words.txt");

    // Read words
    size_t first = -1;
    size_t second = -1;
    int64_t triangularWords = 0;
    while(true) {
        first = fileContent.find('"', second + 1);
        second = fileContent.find('"', first + 1);
        if(first != std::string::npos) {
            if(isTriangular(fileContent.substr(first + 1, second - first - 1))) {
                ++triangularWords;
            }
        } else {
            break;
        }
    }

    return triangularWords;
}

REGISTER_FUNCTION(42, problem_42);
