#include "problems/problem_registry.hpp"

// We deal with Pythagorean triples, which are defined by 1) and 2)
//   1) a*a + b*b = c*c
//   2) a < b < c
// And we try to solve for
//   3) a + b + c = 1000
// 
// A fundamental formula for generating these triples is the euclid's formula, which is
//   4) a = m*m - n*n ; b = 2*m*n ; c = m*m + n*n; m > n > 0;
// 
// We can insert 4) into 3) and receive:
//   5) n = 500 / m - m
// 
// With this solution these is only one for loop necessary to solve to the solution.
// The result for the problem is the product
//   6) p = a * b * c

int64_t validate(int64_t m, int64_t n)
{
    if(m <= n) {
        return 0;
    }

    int64_t a = m * m - n * n;
    int64_t b = 2 * m * n;
    int64_t c = m * m + n * n;

    if(a + b + c == 1000) {
        return a * b * c;
    }

    return 0;
}

int64_t calculate_n(int64_t m)
{
    return ((500ll / m) - m );
}

int64_t problem_9()
{
    for(int64_t m = 1; m < 500; ++m) {
        int64_t n = calculate_n(m);

        int64_t ret = validate(m, n);
        if(ret > 0) {
            return ret;
        }
    }

    return 0;
}

REGISTER_FUNCTION(9, problem_9);
