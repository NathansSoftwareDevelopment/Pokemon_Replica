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
    std::string typeString = inputJson.at("type").at("name").get<std::string>();
    typeString[0] = static_cast<char>(std::toupper(typeString[0]));
    inputMove.type = &typeMap.find(typeString)->second;

    std::string categoryString = inputJson.at("damage_class").at("name").get<std::string>();
    categoryString[0] = static_cast<char>(std::toupper(categoryString[0]));
    inputMove.damageCategory = categoryString;

    inputMove.power = inputJson.at("power").get<int>();

    inputMove.accuracy = inputJson.at("accuracy").get<int>();

    inputMove.PP = inputJson.at("pp").get<int>();

    inputMove.flinchChance = inputJson.at("meta").at("flinch_chance").get<int>();

    // inputMove.conditionChances;

    // inputMove.userStageChances;
    // inputMove.opponentStageChances;
}
}