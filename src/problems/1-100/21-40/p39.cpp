#include "problems/problem_registry.hpp"

// Analysis before calculation
//
//          a + b + c = n
//      <=> c = n - a - b        (1)
// 
//          a^2 + b^2 = c^2      (2)
// 
//      => insert (1) into (2)
// 
//          a^2 + b^2 = (n - a - b)^2                   // set braces
//      <=> a^2 + b^2 = ((n - a) - b)^2                 // bin. formula
//      <=> a^2 + b^2 = (n - a)^2 - 2b(n - a) + b^2     // - b^2
//      <=> a^2       = (n - a)^2 - 2b(n - a) 
//      <=> a^2       = n^2 - 2an + a^2 - 2b(n - a)     // - a^2
//      <=> 0         = n^2 - 2an - 2b(n - a)           // + 2b(n - a)
//      <=> 2b(n - a) = n^2 - 2an                       // / 2(n - a)
//      <=> b         = (n^2 - 2an) / 2(n - a)
//      <=> b         = (n * (n - 2a)) / 2 (n - a)
//      <=> b         = 0.5n * (n - 2a) / (n - a)
//
// 
//          a > 0 && b > 0 && c > 0
//          c > a && c > b
//                  c  <  a + b
//      <=>        2c  <  a + b + c
//          a + b + c  = n <= 1000
//       =>        2c  = n <  1000
//      <=>         c  = n <  500
//       =>         a  <  500
//       =>         b  <  500

int64_t problem_39()
{
    int64_t maxSolutions = 0;
    int64_t number;
    for(int64_t n = 0; n < 1000; ++n) {
        int64_t solutions = 0;
        for(int64_t a = 1; a <= n / 2; ++a) {
            double b = 0.5 * n * (n - 2 * a) / (n - a);
            if(b <= 0) {
                continue;
            }
            if(b == (static_cast<int64_t>(b))) {
                int64_t c = n - a - static_cast<int64_t>(b);
                ++solutions;
            }
        }
        if(solutions > maxSolutions) {
            maxSolutions = solutions;
            number = n;
        }
    }
    return number;
}

REGISTER_FUNCTION(39, problem_39);
