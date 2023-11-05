#include "math/sequences.hpp"

int64_t calculate_nth_triangle_number(int64_t n)
{
    return ((n * n + n) / 2);
}

int64_t calculate_next_collatz_number(int64_t n)
{
    return (n % 2 == 0) ? (n / 2) : (3 * n + 1);
}