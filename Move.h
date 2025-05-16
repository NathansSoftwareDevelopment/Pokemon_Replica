#ifndef MOVE_H
#define MOVE_H
#include <string>

class Move {
    public:
        std::string name;
        std::string type;
        std::string damageCategory;
        int power;
        int accuracy;
        Move(std::string nameInput, std::string typeInput, std::string damageCategoryInput, int powerInput, int accuracyInput);
};

#endif