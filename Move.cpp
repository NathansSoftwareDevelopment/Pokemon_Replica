#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <array>
#include "Move.h"
#include "Type.h"
#include "json.hpp"
using json = nlohmann::json;

Move::Move(
    std::string inputName, std::string inputType, std::string inputDamageCategory, int inputPower, int inputAccuracy, int inputPP, int inputFlinchChance,
    std::map<std::string, int> inputConditionChances, std::map<std::string, std::array<int, 2>> inputUserStageChances, std::map<std::string, std::array<int, 2>> inputOpponentStageChances, bool inputUniqueness
) {
    name = inputName;
    type = &typeMap.find(inputType)->second;
    damageCategory = inputDamageCategory;
    power = inputPower;
    accuracy = inputAccuracy;
    PP = inputPP;
    flinchChance = inputFlinchChance;
    conditionChances.insert(inputConditionChances.begin(), inputConditionChances.end());
    userStageChances.insert(inputUserStageChances.begin(), inputUserStageChances.end());
    opponentStageChances.insert(inputOpponentStageChances.begin(), inputOpponentStageChances.end());
    uniqueness = inputUniqueness;
}

Move::Move(const json& inputJSON) {
    name = inputJSON.at("name");

    std::string typeString = inputJSON.at("type").get<std::string>();
    type = &typeMap.find(typeString)->second;

    damageCategory = inputJSON.at("damageCategory").get<std::string>();

    power = inputJSON.at("power").get<int>();

    accuracy = inputJSON.at("accuracy").get<int>();

    PP = inputJSON.at("PP").get<int>();

    flinchChance = inputJSON.at("flinchChance").get<int>();

    conditionChances;

    userStageChances;
    opponentStageChances;
}

std::map<std::string, Move> moveMap;

void generateMoveMap() {
    std::string filePath = "Move.json";
    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
    json movesFile;
    ifs >> movesFile;

    for (json::iterator move = movesFile.begin(); move != movesFile.end(); move++) {
        std::string moveName = move.key();
        json movesJSON = move.value();

        moveMap.emplace(moveName, Move(movesJSON));
    }
}