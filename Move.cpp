#include <algorithm>
#include <array>
#include "Move.h"
#include "Type.h"

Move::Move(std::string moveInputName, std::string moveInputType, std::string moveInputDamageCategory, int moveInputPower, int moveInputAccuracy, int moveInputPP, std::map<std::string, int> moveInputConditionChances, int moveInputFlinchChance, bool moveInputUniqueness) {
    moveName = moveInputName;
    moveType = &typeMap.find(moveInputType)->second;
    moveDamageCategory = moveInputDamageCategory;
    movePower = moveInputPower;
    moveAccuracy = moveInputAccuracy;
    movePP = moveInputPP;
    moveConditionChances.insert(moveInputConditionChances.begin(), moveInputConditionChances.end());
    moveFlinchChance = moveInputFlinchChance;
    moveUniqueness = moveInputUniqueness;
}