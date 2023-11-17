#include "problems/problem_registry.hpp"
#include "math/primes.hpp"

bool isLeftToRightTruncable(int64_t prime) {
    int64_t decimalPower = 10;
    int64_t currentPrime = prime % decimalPower;
    while(currentPrime != prime) {
        if(!pe::isPrime(currentPrime)) {
            return false;
        }
        decimalPower *= 10;
        currentPrime = prime % decimalPower;
    }
    return true;
}

bool isRightToLeftTruncable(int64_t prime) {
    prime /= 10;
    while(prime > 0) {
        if(!pe::isPrime(prime)) {
            return false;
        }
        prime /= 10;
    }
    return true;
}

int64_t problem_37()
{
    int64_t sum = 0;
    int64_t prime = 7;
    
    for(int i = 0; i < 11; ) {
        prime = pe::nextPrime(prime);
        if(isLeftToRightTruncable(prime) && isRightToLeftTruncable(prime)) {
            sum += prime;
            ++i;
        }
    }

    return sum;
}

REGISTER_FUNCTION(37, problem_37);
