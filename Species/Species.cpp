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

    _stats["HitPoints"] = inputJSON.at("stats").at("HitPoints").get<int>();
    _stats["Attack"] = inputJSON.at("stats").at("Attack").get<int>();
    _stats["Defense"] = inputJSON.at("stats").at("Defense").get<int>();
    _stats["SpecialAttack"] = inputJSON.at("stats").at("SpecialAttack").get<int>();
    _stats["SpecialDefense"] = inputJSON.at("stats").at("SpecialDefense").get<int>();
    _stats["Speed"] = inputJSON.at("stats").at("Speed").get<int>();

    _effortValues["HitPoints"] = inputJSON.at("effort-values").at("HitPoints").get<int>();
    _effortValues["Attack"] = inputJSON.at("effort-values").at("Attack").get<int>();
    _effortValues["Defense"] = inputJSON.at("effort-values").at("Defense").get<int>();
    _effortValues["SpecialAttack"] = inputJSON.at("effort-values").at("SpecialAttack").get<int>();
    _effortValues["SpecialDefense"] = inputJSON.at("effort-values").at("SpecialDefense").get<int>();
    _effortValues["Speed"] = inputJSON.at("effort-values").at("Speed").get<int>();

    _type1 = &typeMap.find(inputJSON.at("types").at("1").get<std::string>())->second;
    _type2 = &typeMap.find(inputJSON.at("types").at("2").get<std::string>())->second;

    _abilities[1] = inputJSON.at("abilities").at("1").get<std::string>();
    _abilities[2] = inputJSON.at("abilities").at("2").get<std::string>();
    _abilities[3] = inputJSON.at("abilities").at("3").get<std::string>();

    _evolution = inputJSON.at("evolve").at("evolves-to").get<std::string>();

    _growthRate = inputJSON.at("growth-rate").get<std::string>();

    _experienceValue = inputJSON.at("base-experience").get<int>();

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