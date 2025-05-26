#include "Nature.h"

Nature::Nature(std::string natureInput, int multiplierInput, int divisorInput) {
    natureName = natureInput;
    if (multiplierInput != divisorInput) {
        *natureStats[multiplierInput] = 1.1;
        *natureStats[divisorInput] = 0.9;
    }
};

Nature natureArray[25] = {
    Nature("Hardy", 0, 0),
    Nature("Lonely", 0, 1),
    Nature("Brave", 0, 2),
    Nature("Adamant", 0, 3),
    Nature("Naughty", 0, 4),
    Nature("Bold", 1, 0),
    Nature("Docile", 1, 1),
    Nature("Relaxed", 1, 2),
    Nature("Impish", 1, 3),
    Nature("Lax", 1, 4),
    Nature("Timid", 2, 0),
    Nature("Hasty", 2, 1),
    Nature("Serious", 2, 2),
    Nature("Jolly", 2, 3),
    Nature("Naive", 2, 4),
    Nature("Modest", 3, 0),
    Nature("Mild", 3, 1),
    Nature("Quiet", 3, 2),
    Nature("Bashful", 3, 3),
    Nature("Rash", 3, 4),
    Nature("Calm", 4, 0),
    Nature("Gentle", 4, 1),
    Nature("Sassy", 4, 2),
    Nature("Careful", 4, 3),
    Nature("Quirky", 4, 4)
};