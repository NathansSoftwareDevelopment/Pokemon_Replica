#ifndef NATURE_H
#define NATURE_H

#include <string>
#include <map>

class Nature {
    public:
        std::string name;
        std::map<std::string, double> stats = {
            {"attack", 1},
            {"defense", 1},
            {"speed", 1},
            {"specialAttack", 1},
            {"specialDefense", 1}
        };
        Nature(std::string natureInput, std::string multiplierInput, std::string divisorInput);
};

extern Nature natureArray[25];

#endif