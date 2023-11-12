#include "problems/problem_registry.hpp"
#include "math/primes.hpp"

int64_t problem_7()
{
    return pe::generate_n_primes(10001).back();
}

REGISTER_FUNCTION(7, problem_7);
