#include "problems/problem_registry.hpp"

#include <vector>

int64_t factorial(int64_t n)
{
    if(n <= 1) {
        return 1;
    } else {
        return factorial(n - 1) * n;
    }
}

std::vector<int64_t> calculate_nth_permutation(std::vector<int64_t> &elements, int64_t n)
{
    std::vector<int64_t> results;
    n -= 1;

    for(int64_t size = elements.size(); size > 0; --size) {
        int64_t index = n / factorial(size - 1);
        n %= factorial(size - 1);

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
