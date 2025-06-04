#ifndef GROWTH_RATE_H
#define GROWTH_RATE_H
#include <string>
#include <iostream>
#include <map>

class GrowthRate {
    private:
        std::string _name;
        std::map<int, int> _toNextLevel = {{1, 0}};
        std::map<int, int> _toLevel = {{1, 0}};
    public:
        const std::string name() const {return _name;}
        const std::map<int, int> toNextLevel() const {return _toNextLevel;}
        const std::map<int, int> toLevel() const {return _toLevel;}

        GrowthRate(std::string inputName, std::map<int, int> inputToNextLevel, std::map<int, int> inputToLevel);
};

extern void makeGrowthRates();
extern std::map<std::string, GrowthRate> growthRateMap;

#endif