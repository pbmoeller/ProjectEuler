#include "problems/problem_registry.hpp"
#include "math/string.hpp"

int64_t problem_25()
{
    std::string previous = "1";
    std::string current = "2";
    std::string next = "";

    int64_t termIndex = 3;
    while(next.length() < 1000) {
        next = pe::addStrings(previous, current);

        previous = current;
        current = next;

        ++termIndex;
    }

    return termIndex;
}

REGISTER_FUNCTION(25, problem_25);
