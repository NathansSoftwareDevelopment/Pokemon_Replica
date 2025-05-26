#ifndef SPECIES_H
#define SPECIES_H
#include <string>
#include <map>
#include "Type.h"
#include "json.hpp"
using json = nlohmann::json;

struct Species {
    std::string speciesName;
    std::map<std::string, int> speciesStats;
    std::string speciesType1;
    std::string speciesType2;
    std::string speciesAbilities[3];
    std::string speciesEvolution;
};

inline void from_json(const json& j, Species& s);
extern void generateSpeciesMap();

extern std::map<std::string, Species> speciesMap;

#endif