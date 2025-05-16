#ifndef NATURE_H
#define NATURE_H

#include <string>
#include <map>

class Nature {
    public:
        std::string natureName;
        float natureAttack = 1;
        float natureDefense = 1;
        float natureSpeed = 1;
        float natureSpecialAttack = 1;
        float natureSpecialDefense = 1;
        float* natureStats[5] = { 
            &natureAttack,
            &natureDefense,
            &natureSpeed,
            &natureSpecialAttack,
            &natureSpecialDefense
        };
        Nature(std::string natureInput, int multiplierInput, int divisorInput);
};

extern Nature natureArray[25];

#endif