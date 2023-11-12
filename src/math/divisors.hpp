#ifndef PROJECT_EULER_MATH_DIVISORS_HPP
#define PROJECT_EULER_MATH_DIVISORS_HPP

#include <vector>
#include <cstdint>

namespace pe {

std::vector<int64_t> divisorsOf(int64_t number);
std::vector<int64_t> properDivisorsOf(int64_t number);

} // namespace pe

#endif // PROJECT_EULER_MATH_DIVISORS_HPP
