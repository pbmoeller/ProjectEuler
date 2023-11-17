#include "math/primes.hpp"

#include <cmath>

namespace pe {

bool isPrime(int64_t number)
{
    if(number <= 1) {
        return false;
    }
    if(number <= 3) {
        return true;
    }
    if(number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    for(int64_t i = 5; i * i <= number; i += 6) {
        if(number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

constexpr int64_t numberOfDigits(int64_t number)
{
    int64_t digits = 0;
    while(number > 0) {
        ++digits;
        number /= 10;
    }
    return digits;
}

int64_t rotateNumberLeft(int64_t number, int64_t digits = -1)
{
    if(digits == -1) {
        digits = numberOfDigits(number);
    }

    int64_t lastDigit = number % 10;
    int64_t result = number / 10 + lastDigit * std::pow(10, digits - 1);

    return result;
}

bool isCircularPrime(int64_t number)
{
    if(!isPrime(number)) {
        return false;
    }

    int64_t digits = numberOfDigits(number);
    int64_t nextNumber = number;
    for(int64_t i = 0; i < digits - 1; ++i) {
        nextNumber = rotateNumberLeft(nextNumber, digits);
        if(!isPrime(nextNumber)) {
            return false;
        }
    }

    return true;
}

std::vector<int64_t> generate_n_primes(int64_t count)
{
    std::vector<int64_t> primes;
    int number = 2;
    while(primes.size() < count) {
        if(isPrime(number)) {
            primes.push_back(number);
        }
        ++number;
    }
    return primes;
}

std::vector<int64_t> generate_primes_below(int64_t upperBound)
{
    std::vector<int64_t> primes;
    int number = 2;
    while(number < upperBound) {
        if(isPrime(number)) {
            primes.push_back(number);
        }
        ++number;
    }
    return primes;
}

int64_t nextPrime(int64_t prime)
{
    int64_t nextPrime = prime + 1;
    while(!isPrime(nextPrime)) {
        ++nextPrime;
    }
    return nextPrime;
}

} // namespace pe
