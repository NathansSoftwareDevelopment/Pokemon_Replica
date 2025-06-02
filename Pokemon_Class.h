#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H

#include <string>
#include "Nature.h"
#include "Type.h"
#include "Move.h"
#include "Species.h"

class Pokemon {
    private:
        void setSpeciesStats();
        void setPokemonIndividualValues(int IndividualValues[6]);
        void setPokemonNature(std::string pokemonNatureName);
        void calculatePokemonStats();
        void setPokemonMoves(std::string inputMove1, std::string InputMove2, std::string inputMove3, std::string inputMove4);
    public:
        Species* species;
        std::string name;

        int level;
        int experience;

        Nature* nature;
        
        std::string ability;
        
        std::string item;

        Type* type1;
        Type* type2;

        std::map<int, Move*> moves;
        
        std::string condition;

        std::map<std::string, int> speciesStats;
        
        std::map<std::string, int> individualValues;

        std::map<std::string, int> effortValues;

        std::map<std::string, int> maxStats = {
            {"HitPoints", 1},
            {"Attack", 1},
            {"Defense", 1},
            {"SpecialAttack", 1},
            {"SpecialDefense", 1},
            {"Speed", 1}
        };

        std::map<std::string, int> currentStats = {
            {"HitPoints", 1},
            {"Attack", 1},
            {"Defense", 1},
            {"SpecialAttack", 1},
            {"SpecialDefense", 1},
            {"Speed", 1}
        };

        std::map<std::string, int> currentStages = {
            {"Attack", 0},
            {"Defense", 0},
            {"SpecialAttack", 0},
            {"SpecialDefense", 0},
            {"Speed", 0},
            {"Accuracy", 0},
            {"Evasion", 0}
        };

        void setPokemonEffortValues(int EffortValues[6]);
        void setPokemonTypes();
        void evolve();
        void setPokemonCurrentStats();
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