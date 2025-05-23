#ifndef SPECIES_H
#define SPECIES_H
#include <string>
#include <map>
#include "Type.h"

struct Species {
    std::string speciesName;
    int speciesStats[6];
    std::string speciesType1;
    std::string speciesType2;
    std::string speciesAbilities[3];
    std::string speciesEvolution;
};

extern std::map<std::string, const Species> speciesMap;

#endif