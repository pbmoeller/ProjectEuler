#include "problems/problem_registry.hpp"

int nextFibonacci(int secondLast, int last) {
    return secondLast + last;
}

int64_t problem_2()
{
    int secondLast = 1;
    int last = 2;
    int sum = 2;

    while(last < 4'000'000) {
        int next = nextFibonacci(secondLast, last);
        if(next >= 4'000'000) {
            break;
        }
        else if(next % 2 == 0) {
            sum += next;
        }
        secondLast = last;
        last = next;
    }
    
    return sum;
}

REGISTER_FUNCTION(2, problem_2);
