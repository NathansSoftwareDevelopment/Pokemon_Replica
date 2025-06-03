#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <array>
#include <map>
#include "Type.h"
#include "json.hpp"

class Move {
    private:
        std::string _name;
        Type* _type;
        std::string _damageCategory;
        int _power;
        int _accuracy;
        int _PP;
        int _flinchChance;
        std::map<std::string, int> _conditionChances;
        std::map<std::string, std::array<int, 2>> _userStageChances;
        std::map<std::string, std::array<int, 2>> _opponentStageChances;
        bool _uniqueness;
    public:
        const std::string name() const {return _name;};
        const Type* type() const {return _type;};
        const std::string damageCategory() const {return _damageCategory;};
        const int power() const {return _power;};
        const int accuracy() const {return _accuracy;};
        const int PP() const {return _PP;};
        const int flinchChance() const {return _flinchChance;};
        const std::map<std::string, int> conditionChances() const {return _conditionChances;};
        const std::map<std::string, std::array<int, 2>> userStageChances() const {return _userStageChances;};
        const std::map<std::string, std::array<int, 2>> opponentStageChances() const {return _opponentStageChances;};
        const bool uniqueness() const {return _uniqueness;};
        Move(
            std::string inputName, std::string inputType, std::string inputDamageCategory, int inputPower, int inputAccuracy, int inputPP, int inputFlinchChance = 0,
            std::map<std::string, int> inputConditionChances = {}, std::map<std::string, std::array<int, 2>> inputUserStageChances = {}, std::map<std::string, std::array<int, 2>> inputOpponentStageChances = {}, bool inputUniqueness = {}
        );
        Move(const nlohmann::json& inputJSON);
};

extern std::map<std::string, Move> moveMap;
extern void generateMoveMap();

#endif