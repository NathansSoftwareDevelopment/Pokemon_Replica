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
    _name = inputName;
    _type = &typeMap.find(inputType)->second;
    _damageCategory = inputDamageCategory;
    _power = inputPower;
    _accuracy = inputAccuracy;
    _PP = inputPP;
    _flinchChance = inputFlinchChance;
    _conditionChances.insert(inputConditionChances.begin(), inputConditionChances.end());
    _userStageChances.insert(inputUserStageChances.begin(), inputUserStageChances.end());
    _opponentStageChances.insert(inputOpponentStageChances.begin(), inputOpponentStageChances.end());
    _uniqueness = inputUniqueness;
}

Move::Move(const json& inputJSON) {
    _name = inputJSON.at("name");
    _type = &typeMap.find(inputJSON.at("type").get<std::string>())->second;
    _damageCategory = inputJSON.at("damageCategory").get<std::string>();
    _power = inputJSON.at("power").get<int>();
    _accuracy = inputJSON.at("accuracy").get<int>();
    _PP = inputJSON.at("PP").get<int>();
    _flinchChance = inputJSON.at("flinchChance").get<int>();
    _conditionChances;
    _userStageChances;
    _opponentStageChances;
}

std::map<std::string, Move> moveMap;

void generateMoveMap() {
    moveMap.emplace("Cheat", Move("Cheat", "None", "Special", 100000, 1000, 1000));
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