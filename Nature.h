#ifndef NATURE_H
#define NATURE_H

#include <string>
#include <map>

class Nature {
    private:
        std::string _name;
        std::map<std::string, double> _stats = {
            {"attack", 1},
            {"defense", 1},
            {"speed", 1},
            {"specialAttack", 1},
            {"specialDefense", 1}
        };
    public:
        const std::string name() const {return _name;}
        const std::map<std::string, double> stats() const {return _stats;}

        Nature(std::string natureInput, std::string multiplierInput, std::string divisorInput);
};

extern std::map<std::string, Nature> natureMap;

#endif