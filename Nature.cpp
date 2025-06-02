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
    {"Hardy", Nature("Hardy", "attack", "attack")},
    {"Lonely", Nature("Lonely", "attack", "defense")},
    {"Brave", Nature("Brave", "attack", "speed")},
    {"Adamant", Nature("Adamant", "attack", "specialAttack")},
    {"Naughty", Nature("Naughty", "attack", "specialDefense")},
    {"Bold", Nature("Bold", "defense", "attack")},
    {"Docile", Nature("Docile", "defense", "defense")},
    {"Relaxed", Nature("Relaxed", "defense", "speed")},
    {"Impish", Nature("Impish", "defense", "specialAttack")},
    {"Lax", Nature("Lax", "defense", "specialDefense")},
    {"Timid", Nature("Timid", "speed", "attack")},
    {"Hasty", Nature("Hasty", "speed", "defense")},
    {"Serious", Nature("Serious", "speed", "speed")},
    {"Jolly", Nature("Jolly", "speed", "specialAttack")},
    {"Naive", Nature("Naive", "speed", "specialDefense")},
    {"Modest", Nature("Modest", "specialAttack", "attack")},
    {"Mild", Nature("Mild", "specialAttack", "defense")},
    {"Quiet", Nature("Quiet", "specialAttack", "speed")},
    {"Bashful", Nature("Bashful", "specialAttack", "specialAttack")},
    {"Rash", Nature("Rash", "specialAttack", "specialDefense")},
    {"Calm", Nature("Calm", "specialDefense", "attack")},
    {"Gentle", Nature("Gentle", "specialDefense", "defense")},
    {"Sassy", Nature("Sassy", "specialDefense", "speed")},
    {"Careful", Nature("Careful", "specialDefense", "specialAttack")},
    {"Quirky", Nature("Quirky", "specialDefense", "specialDefense")}
};