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
        std::string _growthRate;
        int _experienceValue;
        learnSet _moves;
    public:
        std::string name() const {return _name;}
        std::map<std::string, int> stats() const {return _stats;}
        std::map<std::string, int> effortValues() const {return _effortValues;}
        Type* type1() const {return _type1;}
        Type* type2() const {return _type2;}
        std::map<int, std::string> abilities() const {return _abilities;}
        std::string evolution() const {return _evolution;}
        std::string growthRate() const {return _growthRate;}
        int experienceValue() const {return _experienceValue;}
        learnSet moves() const {return _moves;}

        Species& name(std::string inputName) {_name = inputName; return *this;}
        Species& stats(std::map<std::string, int> inputStats) {_stats = inputStats; return *this;}
        Species& effortValues(std::map<std::string, int> inputEffortValues) {_effortValues = inputEffortValues; return *this;}
        Species& type1(Type* inputType1) {_type1 = inputType1; return *this;}
        Species& type2(Type* inputType2) {_type2 = inputType2; return *this;}
        Species& abilities(std::map<int, std::string> inputAbilities) {_abilities = inputAbilities; return *this;}
        Species& evolution(std::string inputEvolution) {_evolution = inputEvolution; return *this;}
        Species& growthRate(std::string inputGrowthRate) {_growthRate = inputGrowthRate; return *this;}
        Species& experienceValue(int inputExperienceValue) {_experienceValue = inputExperienceValue; return *this;}
        Species& moves(learnSet inputMoves) {_moves = inputMoves; return *this;}

        Species(){};
};

inline void from_json(const json& j, Species& s);
extern void generateSpeciesMap();

extern std::map<std::string, Species> speciesMap;

#endif