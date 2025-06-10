#ifndef SPECIES_H
#define SPECIES_H
#include <string>
#include <set>
#include <map>
#include "Type.h"
#include "json.hpp"
using json = nlohmann::json;

struct learnSet {
    std::map<std::string, int> levelUp;
    std::set<std::string> egg;
    std::set<std::string> machine;
    std::set<std::string> tutor;
    std::map<std::string, std::string> other;
};

class Species {
    private:
        std::string _name;
        std::map<std::string, int> _stats;
        std::map<std::string, int> _effortValues;
        Type* _type1;
        Type* _type2;
        std::map<int, std::string> _abilities;
        std::string _evolution;
        int _evolutionLevel;
        std::string _growthRate;
        int _experienceValue;
        learnSet _moves;
    public:
        const std::string name() const {return _name;}
        const std::map<std::string, int> stats() const {return _stats;}
        const std::map<std::string, int> effortValues() const {return _effortValues;}
        const Type* type1() const {return _type1;}
        const Type* type2() const {return _type2;}
        const std::map<int, std::string> abilities() const {return _abilities;}
        const std::string evolution() const {return _evolution;}
        const int evolutionLevel() const {return _evolutionLevel;}
        const std::string growthRate() const {return _growthRate;}
        const int experienceValue() const {return _experienceValue;}
        const learnSet moves() const {return _moves;}

        Species(const json& inputJSON);
};

extern void generateSpeciesMap();

extern std::map<std::string, Species> speciesMap;

#endif