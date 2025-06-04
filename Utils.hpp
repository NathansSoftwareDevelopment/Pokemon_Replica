#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

inline int generateRandom(int lowerBound, int upperBound) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::cout << std::uniform_int_distribution<int>(lowerBound, upperBound)(gen) << std::endl;
    return std::uniform_int_distribution<int>(lowerBound, upperBound)(gen);
}

inline double roundToMultipleOf4096(double inputValue) {
    double scaledValue = inputValue * 4096.0;
    double roundedScaledValue = std::round(scaledValue);
    double result = roundedScaledValue / 4096.0;
    return result;
}

inline double roundHalfDown(double inputValue) {
    if (inputValue > 0) {
        return std::floor(inputValue + 0.5 - 1e-9);
    } else {
        return std::ceil(inputValue - 0.5);
    }
}

#endif