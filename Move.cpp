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


void from_json(const json& inputJson, Move& inputMove) {
    inputMove.name = inputJson.at("name");

    std::string typeString = inputJson.at("type").get<std::string>();
    inputMove.type = &typeMap.find(typeString)->second;

    inputMove.damageCategory = inputJson.at("damageCategory").get<std::string>();

    inputMove.power = inputJson.at("power").get<int>();

    inputMove.accuracy = inputJson.at("accuracy").get<int>();

    inputMove.PP = inputJson.at("PP").get<int>();

    inputMove.flinchChance = inputJson.at("flinchChance").get<int>();

    inputMove.conditionChances;

    inputMove.userStageChances;
    inputMove.opponentStageChances;
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

        moveMap[moveName] = movesJSON.get<Move>();
    }
}