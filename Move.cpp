#include <algorithm>
#include <array>
#include "Move.h"

Move::Move(std::string moveInputName, std::string moveInputType, std::string moveInputDamageCategory, int moveInputPower, int moveInputAccuracy, int moveInputPP, std::map<std::string, double> moveInputConditionChances, double moveInputFlinchChance, bool moveInputUniqueness) {
    moveName = moveInputName;
    moveType = moveInputType;
    moveDamageCategory = moveInputDamageCategory;
    movePower = moveInputPower;
    moveAccuracy = moveInputAccuracy;
    movePP = moveInputPP;
    moveConditionChances.insert(moveInputConditionChances.begin(), moveInputConditionChances.end());
    moveFlinchChance = moveInputFlinchChance;
    moveUniqueness = moveInputUniqueness;
}