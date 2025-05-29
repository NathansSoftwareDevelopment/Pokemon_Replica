#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

double roundToMultipleOf4096(double inputValue) {
    double scaledValue = inputValue * 4096.0;
    double roundedScaledValue = std::round(scaledValue);
    double result = roundedScaledValue / 4096.0;
    return result;
}

double roundHalfDown(double inputValue) {
    if (inputValue > 0) {
        return std::floor(inputValue + 0.5 - 1e-9);
    } else {
        return std::ceil(inputValue - 0.5);
    }
}

#endif UTILS_H