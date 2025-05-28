#ifndef SPECIES_H
#define SPECIES_H
#include <string>
#include <map>
#include "Type.h"
#include "json.hpp"
using json = nlohmann::json;

struct Species {
    std::string name;
    std::map<std::string, int> stats;
    std::string type1;
    std::string type2;
    std::string abilities[3];
    std::string evolution;
    std::string growthRate;
};

inline void from_json(const json& j, Species& s);
extern void generateSpeciesMap();

extern std::map<std::string, Species> speciesMap;

#endif