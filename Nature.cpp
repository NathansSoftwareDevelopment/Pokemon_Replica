#include <string>
#include <map>
#include "Nature.h"

Nature::Nature(std::string natureInput, std::string multiplierInput, std::string divisorInput) {
    _name = natureInput;
    if (multiplierInput != divisorInput) {
        _stats[multiplierInput] = 1.1;
        _stats[divisorInput] = 0.9;
    }
};

std::map<std::string, Nature> natureMap = {
    {"Hardy", Nature("Hardy", "Attack", "Attack")},
    {"Lonely", Nature("Lonely", "Attack", "Defense")},
    {"Brave", Nature("Brave", "Attack", "Speed")},
    {"Adamant", Nature("Adamant", "Attack", "SpecialAttack")},
    {"Naughty", Nature("Naughty", "Attack", "SpecialDefense")},
    {"Bold", Nature("Bold", "Defense", "Attack")},
    {"Docile", Nature("Docile", "Defense", "Defense")},
    {"Relaxed", Nature("Relaxed", "Defense", "Speed")},
    {"Impish", Nature("Impish", "Defense", "SpecialAttack")},
    {"Lax", Nature("Lax", "Defense", "SpecialDefense")},
    {"Timid", Nature("Timid", "Speed", "Attack")},
    {"Hasty", Nature("Hasty", "Speed", "Defense")},
    {"Serious", Nature("Serious", "Speed", "Speed")},
    {"Jolly", Nature("Jolly", "Speed", "SpecialAttack")},
    {"Naive", Nature("Naive", "Speed", "SpecialDefense")},
    {"Modest", Nature("Modest", "SpecialAttack", "Attack")},
    {"Mild", Nature("Mild", "SpecialAttack", "Defense")},
    {"Quiet", Nature("Quiet", "SpecialAttack", "Speed")},
    {"Bashful", Nature("Bashful", "SpecialAttack", "SpecialAttack")},
    {"Rash", Nature("Rash", "SpecialAttack", "SpecialDefense")},
    {"Calm", Nature("Calm", "SpecialDefense", "Attack")},
    {"Gentle", Nature("Gentle", "SpecialDefense", "Defense")},
    {"Sassy", Nature("Sassy", "SpecialDefense", "Speed")},
    {"Careful", Nature("Careful", "SpecialDefense", "SpecialAttack")},
    {"Quirky", Nature("Quirky", "SpecialDefense", "SpecialDefense")}
};