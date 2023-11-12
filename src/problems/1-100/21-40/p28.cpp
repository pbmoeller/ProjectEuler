#include "problems/problem_registry.hpp"

int64_t problem_28()
{
    int64_t sum = 1;

    for(int64_t spiralSize = 3; spiralSize <= 1001; spiralSize += 2) {
        int64_t square = spiralSize * spiralSize;
        for(int64_t i = 0; i < 4; ++i) {
            sum += square - (spiralSize - 1) * i;
        }
    }

    return sum;
}

REGISTER_FUNCTION(28, problem_28);
