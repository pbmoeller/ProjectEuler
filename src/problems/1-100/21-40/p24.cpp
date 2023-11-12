#include "problems/problem_registry.hpp"
#include "math/math.hpp"

#include <vector>

std::vector<int64_t> calculate_nth_permutation(std::vector<int64_t> &elements, int64_t n)
{
    std::vector<int64_t> results;
    n -= 1;

    for(int64_t size = elements.size(); size > 0; --size) {
        int64_t f = pe::factorial(size - 1);
        int64_t index = n / f;
        n %= f;

        results.push_back(elements[index]);
        elements.erase(elements.begin() + index);
    }

    return results;
}

int64_t problem_24()
{
    std::vector<int64_t> elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 1'000'000;
    std::vector<int64_t> permutation = calculate_nth_permutation(elements, n);

    int64_t result = 0;
    for(size_t idx = 0; idx < permutation.size(); ++idx) {
        result *= 10;
        result += permutation[idx];
    }

    return result;
}

REGISTER_FUNCTION(24, problem_24);
