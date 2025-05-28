#include <string>
#include "Species.h"
#include "Type.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

void from_json(const json& inputJson, Species& inputSpecies) {
    inputSpecies.name = inputJson.at("name").get<std::string>();

    inputSpecies.stats["HitPoints"] = inputJson.at("stats").at("hp").get<int>();
    inputSpecies.stats["Attack"] = inputJson.at("stats").at("attack").get<int>();
    inputSpecies.stats["Defense"] = inputJson.at("stats").at("defense").get<int>();
    inputSpecies.stats["SpecialAttack"] = inputJson.at("stats").at("special-attack").get<int>();
    inputSpecies.stats["SpecialDefense"] = inputJson.at("stats").at("special-defense").get<int>();
    inputSpecies.stats["Speed"] = inputJson.at("stats").at("speed").get<int>();

    if (inputJson.at("types").contains("1")) {
        inputSpecies.type1 = inputJson.at("types").at("1").get<std::string>();
    } else {
        inputSpecies.type1 = "none";
    }
    inputSpecies.type1[0] = static_cast<char>(std::toupper(inputSpecies.type1[0]));
    if (inputJson.at("types").contains("2")) {
        inputSpecies.type2 = inputJson.at("types").at("2").get<std::string>();
    } else {
        inputSpecies.type2 = "none";
    }
    inputSpecies.type2[0] = static_cast<char>(std::toupper(inputSpecies.type2[0]));

    if (inputJson.at("abilities").contains("1")) {
        inputSpecies.abilities[0] = inputJson.at("abilities").at("1").get<std::string>();
    } else {
        inputSpecies.abilities[0] = "none";
    }
    if (inputJson.at("abilities").contains("2")) {
        inputSpecies.abilities[1] = inputJson.at("abilities").at("2").get<std::string>();
    } else {
        inputSpecies.abilities[1] = "none";
    }
    if (inputJson.at("abilities").contains("3")) {
        inputSpecies.abilities[2] = inputJson.at("abilities").at("3").get<std::string>();
    } else {
        inputSpecies.abilities[2] = "none";
    }

    if (inputJson.contains("evolve")) {
        inputSpecies.evolution = inputJson.at("evolve").get<std::string>();
    } else {
        inputSpecies.evolution = "none";
    }

    std::string tempGrowthRate;
    if (inputJson.contains("growth-rate")) {
        tempGrowthRate = inputJson.at("growth-rate").get<std::string>();
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
    inputSpecies.growthRate = tempGrowthRate;
}

std::map<std::string, Species> speciesMap;

void generateSpeciesMap() {
    std::string filePath = "..\\Species.json";
    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
    json j_parsed_file;
    ifs >> j_parsed_file;

    for (json::iterator it = j_parsed_file.begin(); it != j_parsed_file.end(); ++it) {
        std::string speciesKey = it.key();
        json speciesJson = it.value();

        Species currentSpecies;
        currentSpecies = speciesJson.get<Species>();
        currentSpecies.name = speciesKey;

        speciesMap[speciesKey] = currentSpecies;
    }
}