#ifndef SPECIES_H
#define SPECIES_H
#include <string>
#include <set>
#include <map>
#include "Type.h"
#include "json.hpp"
using json = nlohmann::json;

struct learnSet {
    std::map<std::string, int> levelUp;
    std::set<std::string> egg;
    std::set<std::string> machine;
    std::set<std::string> tutor;
    std::map<std::string, std::string> other;
};

class Species {
    public:
        std::string name;
        std::map<std::string, int> stats;
        std::map<std::string, int> effortValues;
        Type* type1;
        Type* type2;
        std::string abilities[3];
        std::string evolution;
        std::string growthRate;
        int experienceValue;
        learnSet moves;
        Species(){};
};

inline void from_json(const json& j, Species& s);
extern void generateSpeciesMap();

extern std::map<std::string, Species> speciesMap;

#endif