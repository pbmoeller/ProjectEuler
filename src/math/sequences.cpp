#include "math/sequences.hpp"

int64_t calculate_nth_triangle_number(int64_t n)
{
    return ((n * n + n) / 2);
}
