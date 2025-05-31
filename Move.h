#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <array>
#include <map>
#include "Type.h"

class Move {
    public:
        std::string name;
        Type* type;
        std::string damageCategory;
        int power;
        int accuracy;
        int PP;
        int flinchChance;
        std::map<std::string, int> conditionChances;
        std::map<std::string, std::array<int, 2>> userStageChances;
        std::map<std::string, std::array<int, 2>> opponentStageChances;
        bool uniqueness;
        Move(
            std::string inputName, std::string inputType, std::string inputDamageCategory, int inputPower, int inputAccuracy, int inputPP, int inputFlinchChance = 0,
            std::map<std::string, int> inputConditionChances = {}, std::map<std::string, std::array<int, 2>> inputUserStageChances = {}, std::map<std::string, std::array<int, 2>> inputOpponentStageChances = {}, bool inputUniqueness = {}
        );
        Move(){};
};

extern std::map<std::string, Move> moveMap;

#endif