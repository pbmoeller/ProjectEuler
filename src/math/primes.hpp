#ifndef PROJECT_EULER_MATH_PRIMES_HPP
#define PROJECT_EULER_MATH_PRIMES_HPP

#include <vector>
#include <cstdint>

bool isPrime(int64_t number);

std::vector<int64_t> generate_n_primes(int64_t count);
std::vector<int64_t> generate_primes_below(int64_t upperBound);

#endif // PROJECT_EULER_MATH_PRIMES_HPP
