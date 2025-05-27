#ifndef GROWTH_RATE_H
#define GROWTH_RATE_H
#include <string>
#include <iostream>
#include <map>

struct GrowthRate {
    std::string name;
    std::map<int, int> toNextLevel = {{1, 0}};
    std::map<int, int> toLevel = {{1, 0}};
};

extern void makeGrowthRates();
extern std::map<std::string, GrowthRate> growthRateMap;

#endif