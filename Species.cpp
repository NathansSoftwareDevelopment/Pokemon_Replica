#include <string>
#include "Species.h"
#include "Type.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

void from_json(const json& inputJson, Species& inputSpecies) {
    inputSpecies.speciesName = inputJson.at("name").get<std::string>();

    inputSpecies.speciesStats[0] = inputJson.at("stats").at("hp").get<int>();
    inputSpecies.speciesStats[1] = inputJson.at("stats").at("attack").get<int>();
    inputSpecies.speciesStats[2] = inputJson.at("stats").at("defense").get<int>();
    inputSpecies.speciesStats[3] = inputJson.at("stats").at("special-attack").get<int>();
    inputSpecies.speciesStats[4] = inputJson.at("stats").at("special-defense").get<int>();
    inputSpecies.speciesStats[5] = inputJson.at("stats").at("speed").get<int>();

    if (inputJson.at("types").contains("1")) {
        inputSpecies.speciesType1 = inputJson.at("types").at("1").get<std::string>();
    } else {
        inputSpecies.speciesType1 = "none";
    }
    inputSpecies.speciesType1[0] = static_cast<char>(std::toupper(inputSpecies.speciesType1[0]));
    if (inputJson.at("types").contains("2")) {
        inputSpecies.speciesType2 = inputJson.at("types").at("2").get<std::string>();
    } else {
        inputSpecies.speciesType2 = "none";
    }
    inputSpecies.speciesType2[0] = static_cast<char>(std::toupper(inputSpecies.speciesType2[0]));

    if (inputJson.at("abilities").contains("1")) {
        inputSpecies.speciesAbilities[0] = inputJson.at("abilities").at("1").get<std::string>();
    } else {
        inputSpecies.speciesAbilities[0] = "none";
    }
    if (inputJson.at("abilities").contains("2")) {
        inputSpecies.speciesAbilities[1] = inputJson.at("abilities").at("2").get<std::string>();
    } else {
        inputSpecies.speciesAbilities[1] = "none";
    }
    if (inputJson.at("abilities").contains("3")) {
        inputSpecies.speciesAbilities[2] = inputJson.at("abilities").at("3").get<std::string>();
    } else {
        inputSpecies.speciesAbilities[2] = "none";
    }

    if (inputJson.contains("evolve")) {
        inputSpecies.speciesEvolution = inputJson.at("evolve").get<std::string>();
    } else {
        inputSpecies.speciesEvolution = "none";
    }
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
        currentSpecies.speciesName = speciesKey;

        speciesMap[speciesKey] = currentSpecies;
    }
}