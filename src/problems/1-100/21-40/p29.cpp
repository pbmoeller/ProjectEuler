#include "problems/problem_registry.hpp"

#include <unordered_set>

int64_t problem_29()
{
    std::unordered_set<double> distinctTerms;
    for(int64_t a = 2; a <= 100; ++a) {
        for(int64_t b = 2; b <= 100; ++b) {
            distinctTerms.insert(std::pow(a, b));
        }
    }

    return static_cast<int64_t>(distinctTerms.size());
}

REGISTER_FUNCTION(29, problem_29);
