#include "Move.h"

Move::Move(std::string nameInput, std::string typeInput, std::string damageCategoryInput, int powerInput, int accuracyInput) {
    name = nameInput;
    type = typeInput;
    damageCategory = damageCategoryInput;
    power = powerInput;
    accuracy = accuracyInput;
}