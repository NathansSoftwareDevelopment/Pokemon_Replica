#include <string>
#include "Nature.h"

Nature::Nature(std::string natureInput, std::string multiplierInput, std::string divisorInput) {
    _name = natureInput;
    if (multiplierInput != divisorInput) {
        _stats[multiplierInput] = 1.1;
        _stats[divisorInput] = 0.9;
    }
};

Nature natureArray[25] = {
    Nature("Hardy", "attack", "attack"),
    Nature("Lonely", "attack", "defense"),
    Nature("Brave", "attack", "speed"),
    Nature("Adamant", "attack", "specialAttack"),
    Nature("Naughty", "attack", "specialDefense"),
    Nature("Bold", "defense", "attack"),
    Nature("Docile", "defense", "defense"),
    Nature("Relaxed", "defense", "speed"),
    Nature("Impish", "defense", "specialAttack"),
    Nature("Lax", "defense", "specialDefense"),
    Nature("Timid", "speed", "attack"),
    Nature("Hasty", "speed", "defense"),
    Nature("Serious", "speed", "speed"),
    Nature("Jolly", "speed", "specialAttack"),
    Nature("Naive", "speed", "specialDefense"),
    Nature("Modest", "specialAttack", "attack"),
    Nature("Mild", "specialAttack", "defense"),
    Nature("Quiet", "specialAttack", "speed"),
    Nature("Bashful", "specialAttack", "specialAttack"),
    Nature("Rash", "specialAttack", "specialDefense"),
    Nature("Calm", "specialDefense", "attack"),
    Nature("Gentle", "specialDefense", "defense"),
    Nature("Sassy", "specialDefense", "speed"),
    Nature("Careful", "specialDefense", "specialAttack"),
    Nature("Quirky", "specialDefense", "specialDefense")
};