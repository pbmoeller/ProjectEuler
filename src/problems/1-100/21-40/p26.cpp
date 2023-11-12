#include "problems/problem_registry.hpp"

int64_t problem_26()
{
    // Solution based on
    // http://www.arndt-bruenner.de/mathe/scripts/periodenlaenge.htm

    int64_t maxValue = 0;
    int64_t longestRecurringCycle = 0;
    for(int64_t currentValue = 10; currentValue < 1000; ++currentValue) {
        int64_t cycleLength = 0;
        int64_t remainder = 1;

        int64_t value = currentValue;
        while(value % 2 == 0) {
            value /= 2;
        }
        while(value % 5 == 0) {
            value /= 5;
        }

        do {
            remainder *= 10;
            remainder = remainder % value;
            ++cycleLength;
        } while(remainder != 1 && remainder != 0);

        if(remainder == 1) {
            if(longestRecurringCycle < cycleLength) {
                longestRecurringCycle = cycleLength;
                maxValue = currentValue;
            }
        }
    }

    return maxValue;
}

REGISTER_FUNCTION(26, problem_26);
