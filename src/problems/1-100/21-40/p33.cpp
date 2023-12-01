#include "problems/problem_registry.hpp"

#include <numeric>

int64_t problem_33()
{
    // Brute Force solution - test all fractions
    int64_t totalNominator = 1;
    int64_t totalDenominator = 1;
    for(int64_t denominator = 10; denominator <= 99; ++denominator) {
        for(int64_t nominator = 10; nominator < denominator; ++nominator) {
            int64_t denominatorHigh = denominator / 10;
            int64_t denominatorLow = denominator % 10;
            int64_t nominatorHigh = nominator / 10;
            int64_t nominatorLow = nominator % 10;

            for(int64_t cancellingDigit = 1; cancellingDigit <= 9; ++cancellingDigit) {
                if(cancellingDigit == denominatorHigh && cancellingDigit == nominatorHigh) {
                    if(nominator * denominatorLow == denominator * nominatorLow) {
                        totalNominator *= nominator;
                        totalDenominator *= denominator;
                    }
                }
                if(cancellingDigit == denominatorHigh && cancellingDigit == nominatorLow) {
                    if(nominator * denominatorLow == denominator * nominatorHigh) {
                        totalNominator *= nominator;
                        totalDenominator *= denominator;
                    }
                }
                if(cancellingDigit == denominatorLow && cancellingDigit == nominatorHigh) {
                    if(nominator * denominatorHigh == denominator * nominatorLow) {
                        totalNominator *= nominator;
                        totalDenominator *= denominator;
                    }
                }
                if(cancellingDigit == denominatorLow && cancellingDigit == nominatorLow) {
                    if(nominator * denominatorHigh == denominator * nominatorHigh) {
                        totalNominator *= nominator;
                        totalDenominator *= denominator;
                    }
                }
            }
        }
    }

    int64_t gcd = std::gcd(totalNominator, totalDenominator);

    return totalDenominator / gcd;
}

REGISTER_FUNCTION(33, problem_33);
