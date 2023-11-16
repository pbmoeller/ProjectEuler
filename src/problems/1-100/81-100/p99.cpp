#include "problems/problem_registry.hpp"

#include <string>
#include <vector>
#include <fstream>

struct Number
{
    double base;
    double exponent;
};

std::vector<Number> readNumbers(const std::string &filename)
{
    // Open file
    std::ifstream ifs(filename);
    if(!ifs.is_open()) {
        throw std::runtime_error("[P 99] Cannot read file: " + filename);
    }

    // Read file
    std::vector<Number> numbers;
    std::string line;
    while(std::getline(ifs, line)) {
        size_t found = line.find(',');
        if(found != std::string::npos) {
            Number nbr;
            nbr.base     = atoi(line.substr(0, found).c_str());
            nbr.exponent = atoi(line.substr(found + 1, std::string::npos).c_str());
            numbers.push_back(nbr);
        }
    }

    // Close file
    ifs.close();

    return numbers;
}

int64_t problem_99()
{
    std::vector<Number> numbers = readNumbers("data/p99_base_exp.txt");

    int maxIndex = 0;
    for(int currentLine = 1; currentLine < numbers.size(); ++currentLine) {
        const Number &max = numbers[maxIndex];
        const Number &cur = numbers[currentLine];

        if((std::log(max.base) * max.exponent) < (std::log(cur.base) * cur.exponent)) {
            maxIndex = currentLine;
        }
    }

    return static_cast<int64_t>(maxIndex + 1);
}

REGISTER_FUNCTION(99, problem_99);
