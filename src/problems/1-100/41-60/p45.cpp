#include "problems/problem_registry.hpp"
#include "math/io.hpp"

// Triangular:
//          t_n                 = n/2 (n + 1)
//  <=>     2 * t_n             = n^2 + n
//  <=>     2 * t_n + 1/4       = n^2 + 1/2 * 2n + (1/2)^2 
//  <=>     2 * t_n + 1/4       = (n + 1/2)^2 
//  <=>     sqrt(2 * t_n + 1/4) = (n + 1/2)
//  <=>     n                   = sqrt(2 * t_n + 1/4) - 1/2
//
// Pentagonal:
//          p_n                 = n/2 (3n - 1)
//  <=>     [...]
//  <=>     n                   = 1/6 + sqrt(2/3 * p_n + (1/6)^2)
//  <=>     n                   = 1/6 *(1 + sqrt(24 * p_n + 1))
// 
// Hexagonal:
//          h_n                 = n(2n -1)
//  <=>     [...]
//  <=>     n                   = 1/4 + sqrt(h_n / 2 + (1/4)^2)
//  <=>     n                   = 1/4 * (1 + sqrt(16(h_n / 2 + (1/4)^2))
//  <=>     n                   = 1/4 * (1 + sqrt(16 * h_n + 1))
// 
// Additional: Every hexagonal number is a triangular number
// 
// => Search hexagonal numbers and test if they are pentagonal
//

bool isPentagonal(const int64_t number)
{
    double p = (1.0 + std::sqrt(24.0 * static_cast<double>(number) + 1)) / 6.0;
    return p == static_cast<int64_t>(p);
}

int64_t problem_45()
{
    bool found = false;
    int64_t n = 143;
    int64_t h_n = 0;
    while(!found) {
        ++n;
        h_n = n * (2 * n - 1);
        if(isPentagonal(h_n)) {
            found = true;
        }
    }
    return h_n;
}

REGISTER_FUNCTION(45, problem_45);
