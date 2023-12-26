#include "problems/problem_registry.hpp"
#include "math/io.hpp"

#include <string>
#include <vector>
#include <sstream>

int64_t sample_82()
{
    // Init matrix
    std::vector<std::vector<int64_t>> matrix = {
        { 131, 673, 234, 103, 18  },
        { 201,  96, 342, 965, 150 },
        { 630, 803, 746, 422, 111 },
        { 537, 699, 497, 121, 956 },
        { 805, 732, 524,  37, 331 }
    };

    // Create new matrix and set initial values
    std::vector<std::vector<int64_t>> minimalPathSums(5, std::vector<int64_t>(5, 0LL));
    for(int64_t row = 0; row < 5; ++row) {
        minimalPathSums[row][0] = matrix[row][0];
    }

    // For every column do 3 iterations.
    //   1. set minimal value by using minimal value from left and adding current cell
    //   2. set minimal value by comparing current minimal value against new value by adding cell above to current cell
    //   3. set minimal value by comparing current minimal value against new value by adding cell below to current cell
    for(int64_t col = 1; col < 5; ++col) {
        // 1.
        for(int64_t row = 0; row < 5; ++row) {
            minimalPathSums[row][col] = minimalPathSums[row][col - 1] + matrix[row][col];
        }
        // 2.
        for(int64_t row = 1; row < 5; ++row) {
            minimalPathSums[row][col] = std::min(minimalPathSums[row][col],
                                                 minimalPathSums[row - 1][col] + matrix[row][col]);
        }
        // 3.
        for(int64_t row = 0; row < 4; ++row) {
            minimalPathSums[row][col] = std::min(minimalPathSums[row][col],
                                                 minimalPathSums[row + 1][col] + matrix[row][col]);
        }
    }

    // Get minimal value in last row
    int64_t minimalPathSum = std::numeric_limits<int64_t>::max();
    for(int64_t row = 0; row < 5; ++row) {
        minimalPathSum = std::min(minimalPathSum, minimalPathSums[row][4]);
    }

    return minimalPathSum;

}

constexpr int64_t MaxRows = 80i64;
constexpr int64_t MaxColumns = 80i64;

int64_t problem_82()
{
    // Read file into string buffer
    std::string fileContent = pe::readFile("data/p82_matrix.txt");

    // Init matrix
    std::vector<std::vector<int64_t>> matrix(MaxRows, std::vector<int64_t>(MaxColumns, 0i64));

    // Read values from buffer into matrix
    std::string line;
    std::stringstream sstr;
    sstr.str(fileContent);
    for(int64_t row = 0; row < MaxRows; ++row) {
        std::getline(sstr, line);
        size_t last = 0;
        for(int64_t col = 0; col < MaxColumns; ++col) {
            size_t next = line.find(',', last);
            matrix[row][col] = atoi(line.substr(last, next).c_str());
            last = next + 1;
        }
    }

    // Create new matrix and set initial values
    std::vector<std::vector<int64_t>> minimalPathSums(MaxRows, std::vector<int64_t>(MaxColumns, std::numeric_limits<int64_t>::max()));
    for(int64_t row = 0; row < MaxRows; ++row) {
        minimalPathSums[row][0] = matrix[row][0];
    }

    // For every column do 3 iterations.
    //   1. set minimal value by using minimal value from left and adding current cell
    //   2. set minimal value by comparing current minimal value against new value by adding cell above to current cell
    //   3. set minimal value by comparing current minimal value against new value by adding cell below to current cell
    for(int64_t col = 1; col < MaxColumns; ++col) {
        // 1.
        for(int64_t row = 0; row < MaxRows; ++row) {
            minimalPathSums[row][col] = minimalPathSums[row][col - 1] + matrix[row][col];
        }
        // 2.
        for(int64_t row = 1; row < MaxRows; ++row) {
            minimalPathSums[row][col] = std::min(minimalPathSums[row][col],
                                                 minimalPathSums[row - 1][col] + matrix[row][col]);
        }
        // 3.
        for(int64_t row = MaxRows - 2; row >= 0; --row) {
            minimalPathSums[row][col] = std::min(minimalPathSums[row][col],
                                                 minimalPathSums[row + 1][col] + matrix[row][col]);
        }
    }

    // Get minimal value in last row
    int64_t minimalPathSum = std::numeric_limits<int64_t>::max();
    for(int64_t row = 0; row < MaxRows; ++row) {
        minimalPathSum = std::min(minimalPathSum, minimalPathSums[row][MaxColumns - 1]);
    }

    return minimalPathSum;
}

REGISTER_FUNCTION(82, problem_82);
