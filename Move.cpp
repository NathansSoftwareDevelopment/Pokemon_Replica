#include <algorithm>
#include "Move.h"

Move::Move(std::string moveInputName, std::string moveInputType, std::string moveInputDamageCategory, int moveInputPower, int moveInputAccuracy, int moveInputPP) {
    moveName = moveInputName;
    moveType = moveInputType;
    moveDamageCategory = moveInputDamageCategory;
    movePower = moveInputPower;
    moveAccuracy = moveInputAccuracy;
    movePP = moveInputPP;
}