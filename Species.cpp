#include <string>
#include "Species.h"
#include "Type.h"

const Species Charmander {
    "Charmander",
    {39, 52, 43, 60, 50, 65},
    "Fire",
    "None",
    {"Blaze", "None", "Solar Power"},
    "Charmeleon"
};

const Species Charmeleon {
    "Charmeleon",
    {58, 64, 58, 80, 65, 80},
    "Fire",
    "None",
    {"Blaze", "None", "Solar Power"},
    "Charizard"
};

const Species Charizard {
    "Charizard",
    {78, 84, 78, 109, 85, 100},
    "Fire",
    "Flying",
    {"Blaze", "None", "Solar Power"},
    "Charizard"
};

std::map<std::string, const Species> speciesMap = {
    {"Charmander", Charmander},
    {"Charmeleon", Charmeleon},
    {"Charizard", Charizard},
};