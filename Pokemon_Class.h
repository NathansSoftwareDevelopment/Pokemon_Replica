#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H

#include <string>
#include "Nature.h"
#include "Type.h"
#include "Move.h"
#include "Species.h"

class Pokemon {
    private:
        Species* _species;
        std::string _name;

        int _level;
        int _experience;

        Nature* _nature;

        std::string _ability;

        std::string _item;

        Type* _type1;
        Type* _type2;

        std::map<int, Move*> _moves;

        std::string _condition;

        std::map<std::string, int> _speciesStats;

        std::map<std::string, int> _individualValues;

        std::map<std::string, int> _effortValues;

        std::map<std::string, int> _maxStats = {
            {"HitPoints", 1},
            {"Attack", 1},
            {"Defense", 1},
            {"SpecialAttack", 1},
            {"SpecialDefense", 1},
            {"Speed", 1}
        };

        std::map<std::string, int> _currentStats = {
            {"HitPoints", 1},
            {"Attack", 1},
            {"Defense", 1},
            {"SpecialAttack", 1},
            {"SpecialDefense", 1},
            {"Speed", 1}
        };

        std::map<std::string, int> _currentStages = {
            {"Attack", 0},
            {"Defense", 0},
            {"SpecialAttack", 0},
            {"SpecialDefense", 0},
            {"Speed", 0},
            {"Accuracy", 0},
            {"Evasion", 0}
        };


        void setSpeciesStats();
        void setPokemonIndividualValues(int IndividualValues[6]);
        void setPokemonNature(std::string pokemonNatureName);
        void calculatePokemonStats();
        void setPokemonMoves(std::string inputMove1, std::string InputMove2, std::string inputMove3, std::string inputMove4);
    public:
        const Species* species() const {return _species;}
        const std::string name() const {return _name;}
        const int level() const {return _level;}
        const int experience() const {return _experience;}
        const Nature* nature() const {return _nature;}
        const std::string ability() const {return _ability;}
        const std::string item() const {return _item;}
        const Type* type1() const {return _type1;}
        const Type* type2() const {return _type2;}
        const std::map<int, Move*> moves() const {return _moves;}
        const std::string condition() const {return _condition;}
        const std::map<std::string, int> speciesStats() const {return _speciesStats;}
        const std::map<std::string, int> individualValues() const {return _individualValues;}
        const std::map<std::string, int> effortValues() const {return _effortValues;}
        const std::map<std::string, int> maxStats() const {return _maxStats;}
        const std::map<std::string, int> currentStats() const {return _currentStats;}
        const std::map<std::string, int> currentStages() const {return _currentStages;}

        Pokemon& currentStat(std::string inputStatName, int inputStat) {_currentStats[inputStatName] = inputStat; return *this;}
        Pokemon& effortValue(std::string inputValueName, int inputValue) {_effortValues[inputValueName] = inputValue; return *this;}
        Pokemon& effortValues(int EffortValues[6]);
        Pokemon& pokemonTypes();
        Pokemon& pokemonCurrentStats();

        void evolve();
        void calculateStageChanges();
        void addExperience(int inputExperience);

        Pokemon(std::string inputName, Species* inputSpecies, std::string inputNature, std::string inputAbility, int inputIndividualValues[6]);
        Pokemon(
            std::string inputName, Species* inputSpecies, std::string inputNature, int inputLevel, int inputExperience, std::string inputAbility,
            std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4, 
            std::string inputCondition,
            int inputIndividualValues[6], int inputEffortValues[6]
        );
        ~Pokemon();
};

#endif