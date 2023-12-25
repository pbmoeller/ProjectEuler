#include "problems/problem_registry.hpp"
#include "math/io.hpp"

#include <string>
#include <vector>
#include <sstream>

int64_t problem_81()
{
    // Read file into string buffer
    std::string fileContent = pe::readFile("data/p81_matrix.txt");

    // Init matrix
    std::vector<std::vector<int64_t>> matrix(80, std::vector<int64_t>(80, 0LL));

    // Read values from buffer into matrix
    std::string line;
    std::stringstream sstr;
    sstr.str(fileContent);
    for(int64_t row = 0; row < 80; ++row) {
        std::getline(sstr, line);
        size_t last = 0;
        for(int64_t col = 0; col < 80; ++col) {
            size_t next = line.find(',', last);
            matrix[row][col] = atoi(line.substr(last, next).c_str());
            last = next + 1;
        }
    }

    // Create new matrix and calculate minimal path sum
    std::vector<std::vector<int64_t>> minimalPathSums(80, std::vector<int64_t>(80, 0LL));
    minimalPathSums[0][0] = matrix[0][0];

    // calculate first row and first column, they only base on one cell before
    for(int64_t x = 1; x < 80; ++x) {
        minimalPathSums[0][x] = matrix[0][x] + minimalPathSums[0][x - 1];
        minimalPathSums[x][0] = matrix[x][0] + minimalPathSums[x - 1][0];
    }

    // Calculate the minimum path sum
    for(int64_t row = 1; row < 80; ++row) {
        for(int64_t col = 1; col < 80; ++col) {
            minimalPathSums[row][col] = matrix[row][col] + std::min(minimalPathSums[row - 1][col],
                                                                    minimalPathSums[row][col - 1]);
        }
    }

    return minimalPathSums[79][79];
}

REGISTER_FUNCTION(81, problem_81);
