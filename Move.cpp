#include <algorithm>
#include <array>
#include "Move.h"
#include "Type.h"

Move::Move(
    std::string moveInputName, std::string moveInputType, std::string moveInputDamageCategory, int moveInputPower, int moveInputAccuracy, int moveInputPP, int moveInputFlinchChance,
    std::map<std::string, int> moveInputConditionChances, std::map<std::string, std::array<int, 2>> moveInputUserStageChances, std::map<std::string, std::array<int, 2>> moveInputOpponentStageChances, bool moveInputUniqueness
) {
    moveName = moveInputName;
    moveType = &typeMap.find(moveInputType)->second;
    moveDamageCategory = moveInputDamageCategory;
    movePower = moveInputPower;
    moveAccuracy = moveInputAccuracy;
    movePP = moveInputPP;
    moveFlinchChance = moveInputFlinchChance;
    moveConditionChances.insert(moveInputConditionChances.begin(), moveInputConditionChances.end());
    moveUserStageChances.insert(moveInputUserStageChances.begin(), moveInputUserStageChances.end());
    moveOpponentStageChances.insert(moveInputOpponentStageChances.begin(), moveInputOpponentStageChances.end());
    moveUniqueness = moveInputUniqueness;
}