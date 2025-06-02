#include "Growth_Rate.h"
#include <string>
#include <map>
#include <cmath>

GrowthRate::GrowthRate(std::string inputName, std::map<int, int> inputToNextLevel, std::map<int, int> inputToLevel) {
    _name = inputName;
    _toNextLevel = inputToNextLevel;
    _toLevel = inputToLevel;
}

std::map<std::string, GrowthRate> growthRateMap;

void makeGrowthRates() {
    std::map<std::string, std::map<int, int>> growthsRates = {{"Fluctuating", {}}, {"Slow", {}}, {"Medium Slow", {}}, {"Medium Fast", {}}, {"Fast", {}}, {"Erratic", {}}};

    for (int level = 2; level < 101; level++) {
        if (level < 15) {
            growthsRates["Fluctuating"][level] = (pow(level, 3)*((floor((level + 1)/3.0)+24)))/50.0;
        } else if (15 <= level && level < 37) {
            growthsRates["Fluctuating"][level] = (pow(level, 3)*(level + 14))/50.0;
        } else if (37 <= level && level < 101) {
            growthsRates["Fluctuating"][level] = (pow(level, 3)*(floor((level/2.0))+32))/50.0;
        }
        growthsRates["Slow"][level] = (5*pow(level, 3))/4.0;
        growthsRates["Medium Slow"][level] = (6/5.0)*pow(level, 3) - 15*pow(level, 2) + 100*level - 140;
        growthsRates["Medium Fast"][level] = pow(level, 3);
        growthsRates["Fast"][level] = (4*pow(level, 3))/5.0;
        if (level < 51) {
            growthsRates["Erratic"][level] = (pow(level, 3)*(100 - level))/50.0;
        } else if (51 <= level && level < 69) {
            growthsRates["Erratic"][level] = (pow(level, 3)*(150 - level))/100.0;
        } else if (69 <= level && level < 99) {
            growthsRates["Erratic"][level] = (pow(level, 3)*floor((1911 - (10*level))/3))/500.0;
        } else if (99 <= level && level < 101) {
            growthsRates["Erratic"][level] = (pow(level, 3)*(160 - level))/100.0;
        }
    }

    for (std::pair<std::string, std::map<int, int>> growthRate : growthsRates) {
        // std::cout << growthRate.first << std::endl;
        std::map<int, int> toNextLevel;
        for (int level = 1; level < 100; level++) {
            toNextLevel[level] = growthRate.second[level+1] - growthRate.second[level];
            // printf("\t%d -> %d = %d\n", level, level+1, toNextLevel[level]);
        }
        growthRateMap.emplace(growthRate.first, GrowthRate(growthRate.first, toNextLevel, growthRate.second));
    }
}