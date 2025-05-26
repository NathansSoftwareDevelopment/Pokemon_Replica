#include <algorithm>
#include <array>
#include "Move.h"
#include "Type.h"

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