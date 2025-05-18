#ifndef MOVE_H
#define MOVE_H
#include <string>

class Move {
    public:
        std::string moveName;
        std::string moveType;
        std::string moveDamageCategory;
        int movePower;
        int moveAccuracy;
        int movePP;
        bool moveUniqueness;
        Move(std::string moveInputName, std::string moveInputType, std::string moveInputDamageCategory, int moveInputPower, int moveInputAccuracy, int moveInputPP, bool moveInputUniqueness);
};

#endif