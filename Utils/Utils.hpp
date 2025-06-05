#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

inline int generateRandom(int lowerBound, int upperBound) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return std::uniform_int_distribution<int>(lowerBound, upperBound)(gen);
}

inline double roundToMultipleOf4096(double inputValue) {
    static std::vector<double> roundingValues = {0};
    double maxElement = *std::max_element(roundingValues.begin(), roundingValues.end());
    if (maxElement < inputValue) {
        for (double i = maxElement; i < inputValue+1; i+=(1/4096.0)) {
            roundingValues.emplace_back(i);
        }
    }
    std::sort(roundingValues.begin(), roundingValues.end());

    double closestElement = 0;
    double currentRoundingValue;
    for (int i = 0; i <= roundingValues.size()-1; i++) {
        currentRoundingValue = roundingValues[i];
        if (std::abs(inputValue-currentRoundingValue) <= std::abs(inputValue-roundingValues[closestElement])) {
            closestElement = i;
        } else {
            break;
        }
    }
    return roundingValues[closestElement];
}

inline double roundHalfDown(double inputValue) {
    if (inputValue > 0) {
        return std::floor(inputValue + 0.5 - 1e-9);
    } else {
        return std::ceil(inputValue - 0.5);
    }
}

#endif