#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Species.h"
#include "Type.h"
#include "json.hpp"
using json = nlohmann::json;

Species::Species(const json& inputJSON) {
    _name = inputJSON.at("name").get<std::string>();

    _stats["HitPoints"] = inputJSON.at("stats").at("hp").get<int>();
    _stats["Attack"] = inputJSON.at("stats").at("attack").get<int>();
    _stats["Defense"] = inputJSON.at("stats").at("defense").get<int>();
    _stats["SpecialAttack"] = inputJSON.at("stats").at("special-attack").get<int>();
    _stats["SpecialDefense"] = inputJSON.at("stats").at("special-defense").get<int>();
    _stats["Speed"] = inputJSON.at("stats").at("speed").get<int>();

    _effortValues["HitPoints"] = inputJSON.at("effort-values").at("hp").get<int>();
    _effortValues["Attack"] = inputJSON.at("effort-values").at("attack").get<int>();
    _effortValues["Defense"] = inputJSON.at("effort-values").at("defense").get<int>();
    _effortValues["SpecialAttack"] = inputJSON.at("effort-values").at("special-attack").get<int>();
    _effortValues["SpecialDefense"] = inputJSON.at("effort-values").at("special-defense").get<int>();
    _effortValues["Speed"] = inputJSON.at("effort-values").at("speed").get<int>();

    std::string typeString1 = inputJSON.at("types").at("1").get<std::string>();
    typeString1[0] = static_cast<char>(std::toupper(typeString1[0]));
    _type1 = &typeMap.find(typeString1)->second;
    std::string typeString2 = inputJSON.at("types").at("2").get<std::string>();
    typeString2[0] = static_cast<char>(std::toupper(typeString2[0]));
    _type2 = &typeMap.find(typeString2)->second;

    _abilities[1] = inputJSON.at("abilities").at("1").get<std::string>();
    _abilities[2] = inputJSON.at("abilities").at("2").get<std::string>();
    _abilities[3] = inputJSON.at("abilities").at("3").get<std::string>();

    _evolution = inputJSON.at("evolve").get<std::string>();

    std::string tempGrowthRate;
    if (inputJSON.contains("growth-rate")) {
        tempGrowthRate = inputJSON.at("growth-rate").get<std::string>();
    } else {
        tempGrowthRate = "slow";
    }
    tempGrowthRate[0] = static_cast<char>(std::toupper(tempGrowthRate[0]));
    if (tempGrowthRate == "Medium-slow") {
        tempGrowthRate = "Medium Slow";
    } else if (tempGrowthRate == "Medium") {
        tempGrowthRate = "Medium Fast";
    } else if (tempGrowthRate == "Fast-then-very-slow") {
        tempGrowthRate = "Fluctuating";
    } else if (tempGrowthRate == "Slow-then-very-fast") {
        tempGrowthRate = "Erratic";
    }
    _growthRate = tempGrowthRate;

    _moves.levelUp = inputJSON.at("moves").at("level-up");
    _moves.egg = inputJSON.at("moves").at("egg");
    _moves.machine = inputJSON.at("moves").at("machine");
    _moves.tutor = inputJSON.at("moves").at("tutor");
    _moves.other = inputJSON.at("moves").at("other");
}

std::map<std::string, Species> speciesMap;

void generateSpeciesMap() {
    std::string filePath = "Species.json";
    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
    json speciesFile;
    ifs >> speciesFile;

    for (json::iterator specie = speciesFile.begin(); specie != speciesFile.end(); ++specie) {
        std::string speciesName = specie.key();
        json speciesJSON = specie.value();

        speciesMap.emplace(speciesName, Species(speciesJSON));
    }
}