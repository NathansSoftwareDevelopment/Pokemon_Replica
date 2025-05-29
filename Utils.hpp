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


#endif UTILS_H