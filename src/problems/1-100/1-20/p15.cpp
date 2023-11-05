#include "problems/problem_registry.hpp"

#include <cstdint>
#include <vector>

int64_t problem_15()
{
    int64_t grid[21][21];

    // Init Grid
    for(size_t i = 0; i < 21; ++i) {
        grid[i][0] = 1;
        grid[0][i] = 1;
    }

    for(size_t row = 1; row < 21; ++row) {
        for(size_t col = 1; col < 21; ++col) {
            grid[row][col] = grid[row - 1][col] + grid[row][col - 1];
        }
    }

    return grid[20][20];
}

REGISTER_FUNCTION(15, problem_15);
