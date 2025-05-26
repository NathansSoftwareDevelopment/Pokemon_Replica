#ifndef NATURE_H
#define NATURE_H

#include <string>
#include <map>

class Nature {
    public:
        std::string name;
        float attack = 1;
        float defense = 1;
        float speed = 1;
        float specialAttack = 1;
        float specialDefense = 1;
        float* stats[5] = { 
            &attack,
            &defense,
            &speed,
            &specialAttack,
            &specialDefense
        };
        Nature(std::string natureInput, int multiplierInput, int divisorInput);
};

extern Nature natureArray[25];

#endif