#ifndef PROJECT_EULER_MATH_MATH_HPP
#define PROJECT_EULER_MATH_MATH_HPP

#include <vector>
#include <cstdint>

namespace pe {

constexpr int64_t factorial(int64_t n)
{
    if(n <= 1) {
        return 1;
    } else {
        return factorial(n - 1) * n;
    }
}

} // namespace pe

#endif // PROJECT_EULER_MATH_MATH_HPP
