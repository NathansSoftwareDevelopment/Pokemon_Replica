#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <array>
#include <map>
#include "Type.h"

class Move {
    public:
        std::string moveName;
        Type* moveType;
        std::string moveDamageCategory;
        int movePower;
        int moveAccuracy;
        int movePP;
        int moveFlinchChance;
        std::map<std::string, int> moveConditionChances;
        std::map<std::string, std::array<int, 2>> moveUserStageChances;
        std::map<std::string, std::array<int, 2>> moveOpponentStageChances;
        bool moveUniqueness;
        Move(
            std::string moveInputName, std::string moveInputType, std::string moveInputDamageCategory, int moveInputPower, int moveInputAccuracy, int moveInputPP, int moveInputFlinchChance = 0,
            std::map<std::string, int> moveInputConditionChances = {}, std::map<std::string, std::array<int, 2>> moveInputUserStageChances = {}, std::map<std::string, std::array<int, 2>> moveInputOpponentStageChances = {}, bool moveInputUniqueness = {}
        );
};

extern std::map<std::string, Move> moveMap;

#endif