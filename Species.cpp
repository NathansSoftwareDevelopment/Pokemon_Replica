#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Species.h"
#include "Type.h"
#include "json.hpp"
using json = nlohmann::json;

void from_json(const json& inputJson, Species& inputSpecies) {
    inputSpecies.name = inputJson.at("name").get<std::string>();

    inputSpecies.experienceValue = inputJson.at("base-experience").get<int>();

    inputSpecies.stats["HitPoints"] = inputJson.at("stats").at("hp").get<int>();
    inputSpecies.stats["Attack"] = inputJson.at("stats").at("attack").get<int>();
    inputSpecies.stats["Defense"] = inputJson.at("stats").at("defense").get<int>();
    inputSpecies.stats["SpecialAttack"] = inputJson.at("stats").at("special-attack").get<int>();
    inputSpecies.stats["SpecialDefense"] = inputJson.at("stats").at("special-defense").get<int>();
    inputSpecies.stats["Speed"] = inputJson.at("stats").at("speed").get<int>();

    inputSpecies.effortValues["HitPoints"] = inputJson.at("effort-values").at("hp").get<int>();
    inputSpecies.effortValues["Attack"] = inputJson.at("effort-values").at("attack").get<int>();
    inputSpecies.effortValues["Defense"] = inputJson.at("effort-values").at("defense").get<int>();
    inputSpecies.effortValues["SpecialAttack"] = inputJson.at("effort-values").at("special-attack").get<int>();
    inputSpecies.effortValues["SpecialDefense"] = inputJson.at("effort-values").at("special-defense").get<int>();
    inputSpecies.effortValues["Speed"] = inputJson.at("effort-values").at("speed").get<int>();

    if (inputJson.at("types").contains("1")) {
        std::string typeString = inputJson.at("types").at("1").get<std::string>();
        typeString[0] = static_cast<char>(std::toupper(typeString[0]));
        inputSpecies.type1 = &typeMap.find(typeString)->second;
        // std::cout << test->name << std::endl;
        // std::cout << "Type Search: " << inputJson.at("types").at("1").get<std::string>() << std::endl;
        // std::cout << "Type Name: " << typeMap.find(inputJson.at("types").at("1").get<std::string>())->first << std::endl;
        // std::cout << "Actual Type Name: " << typeMap.find(inputJson.at("types").at("1").get<std::string>())->second.name << std::endl;
    } else {
        inputSpecies.type1 = &typeMap.find("None")->second;
    }
    if (inputJson.at("types").contains("2")) {
        std::string typeString = inputJson.at("types").at("2").get<std::string>();
        typeString[0] = static_cast<char>(std::toupper(typeString[0]));
        inputSpecies.type2 = &typeMap.find(typeString)->second;
    } else {
        inputSpecies.type2 = &typeMap.find("None")->second;
    }

    if (inputJson.at("abilities").contains("1")) {
        inputSpecies.abilities[1] = inputJson.at("abilities").at("1").get<std::string>();
    } else {
        inputSpecies.abilities[1] = "none";
    }
    if (inputJson.at("abilities").contains("2")) {
        inputSpecies.abilities[2] = inputJson.at("abilities").at("2").get<std::string>();
    } else {
        inputSpecies.abilities[2] = "none";
    }
    if (inputJson.at("abilities").contains("3")) {
        inputSpecies.abilities[3] = inputJson.at("abilities").at("3").get<std::string>();
    } else {
        inputSpecies.abilities[3] = "none";
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

    inputJson.at("moves").at("level-up").get_to(inputSpecies.moves.levelUp);
    inputJson.at("moves").at("egg").get_to(inputSpecies.moves.egg);
    inputJson.at("moves").at("machine").get_to(inputSpecies.moves.machine);
    inputJson.at("moves").at("tutor").get_to(inputSpecies.moves.tutor);
    inputJson.at("moves").at("other").get_to(inputSpecies.moves.other);
}

std::map<std::string, Species> speciesMap;

void generateSpeciesMap() {
    std::string filePath = "Species.json";
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