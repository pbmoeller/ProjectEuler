#include "problems/problem_registry.hpp"
#include "math/io.hpp"

#include <string>
#include <vector>
#include <algorithm>

int64_t problem_22()
{
    std::string fileContent = pe::readFile("data/p22_names.txt");

    // Read names
    size_t first = -1;
    size_t second = -1;
    std::vector<std::string> names;
    while(true) {
        first = fileContent.find('"', second + 1);
        second = fileContent.find('"', first + 1);
        if(first != std::string::npos) {
            names.push_back(fileContent.substr(first + 1, second - first - 1));
        } else {
            break;
        }
    }

    // Sort names
    std::sort(names.begin(), names.end());

    // Calculate total score
    int64_t totalScore = 0;
    for(int64_t i = 0; i < names.size(); ++i) {
        int64_t nameScore = 0;
        for(int64_t j = 0; j < names[i].length(); ++j) {
            nameScore += (names[i][j] - 'A') + 1;
        }
        totalScore += (i + 1) * nameScore;
    }

    return totalScore;
}

REGISTER_FUNCTION(22, problem_22);
