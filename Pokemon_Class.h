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

        int maxHitPoints;
        int maxAttack;
        int maxDefense;
        int maxSpecialAttack;
        int maxSpecialDefense;
        int maxSpeed;
        int* maxStats[6] = {
            &maxHitPoints,
            &maxAttack,
            &maxDefense,
            &maxSpecialAttack,
            &maxSpecialDefense,
            &maxSpeed
        };

        int currentHitPoints;
        int currentAttack;
        int currentDefense;
        int currentSpecialAttack;
        int currentSpecialDefense;
        int currentSpeed;
        int* currentStats[6] = {
            &currentHitPoints,
            &currentAttack,
            &currentDefense,
            &currentSpecialAttack,
            &currentSpecialDefense,
            &currentSpeed,
        };

        int currentAttackStage = 0;
        int currentDefenseStage = 0;
        int currentSpecialAttackStage = 0;
        int currentSpecialDefenseStage = 0;
        int currentSpeedStage = 0;
        int currentAccuracyStage = 0;
        int currentEvasionStage = 0;
        int *currentStages[7] = {
            &currentAttackStage,
            &currentDefenseStage,
            &currentSpecialAttackStage ,
            &currentSpecialDefenseStage,
            &currentSpeedStage,
            &currentAccuracyStage,
            &currentEvasionStage
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