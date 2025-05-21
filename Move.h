#ifndef MOVE_H
#define MOVE_H
#include <string>
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
        std::map<std::string, int> moveConditionChances;
        int moveFlinchChance;
        bool moveUniqueness;
        Move(std::string moveInputName, std::string moveInputType, std::string moveInputDamageCategory, int moveInputPower, int moveInputAccuracy, int moveInputPP, std::map<std::string, int> moveInputConditionChances, int moveFlinchChance, bool moveInputUniqueness);
};

extern std::map<std::string, Move> moveMap;

#endif