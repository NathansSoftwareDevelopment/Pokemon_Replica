#ifndef GROWTH_RATE_H
#define GROWTH_RATE_H
#include <string>
#include <iostream>
#include <map>

struct GrowthRate {
    std::string name;
    std::map<int, int> toNextLevel;
    std::map<int, int> toLevel;
};

extern std::map<std::string, GrowthRate> growthRateMap;

#endif