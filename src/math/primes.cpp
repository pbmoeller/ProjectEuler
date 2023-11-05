#include "math/primes.hpp"


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
