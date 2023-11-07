#include "problems/problem_registry.hpp"

bool isLeapYear(int year) {
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

int64_t problem_19()
{
    int daysPerMonth[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int days = 0;
    int64_t sundaysOnFirstOfTheMonth = 0;
    for(int year = 1900; year <= 2000; ++year) {
        for(int month = 0; month < 12; ++month) {
            days += daysPerMonth[month];
            if(month == 1 && isLeapYear(year)) {
                days += 1;
            }

            if(days % 7 == 6) {
                if(year != 1900) {                  // We start to count in 1901, but be don't know
                    ++sundaysOnFirstOfTheMonth;     // the day of 1.1.1901, but we know 1.1.1900 was a monday.
                }
            }
        }
    }

    return sundaysOnFirstOfTheMonth;
}

REGISTER_FUNCTION(19, problem_19);
