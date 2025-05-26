#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H

#include <string>
#include "Nature.h"
#include "Type.h"
#include "Move.h"
#include "Species.h"

class Pokemon {
    public:
        const Species* species;
        std::string name;

        int level;
        int experience;

        Nature* nature;
        
        std::string ability;
        
        std::string item;

        Type* type1;
        Type* type2;

        Move* move1;
        Move* move2;
        Move* move3;
        Move* move4;
        Move** moves[4] = {
            &move1,
            &move2,
            &move3,
            &move4
        };
        
        std::string condition;

        std::map<std::string, int> speciesStats;
        
        int HitPointsIndividualValue;
        int AttackIndividualValue;
        int DefenseIndividualValue;
        int SpecialAttackIndividualValue;
        int SpecialDefenseIndividualValue;
        int SpeedIndividualValue;
        int* IndividualValues[6] = {
            &HitPointsIndividualValue,
            &AttackIndividualValue,
            &DefenseIndividualValue,
            &SpecialAttackIndividualValue,
            &SpecialDefenseIndividualValue,
            &SpeedIndividualValue
        };

        int HitPointsEffortValue;
        int AttackEffortValue;
        int DefenseEffortValue;
        int SpecialAttackEffortValue;
        int SpecialDefenseEffortValue;
        int SpeedEffortValue;
        int* EffortValues[6] = {
            &HitPointsEffortValue,
            &AttackEffortValue,
            &DefenseEffortValue,
            &SpecialAttackEffortValue,
            &SpecialDefenseEffortValue,
            &SpeedEffortValue
        };

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

        void setSpeciesStats(const Species*);
        void setPokemonIndividualValues(int IndividualValues[6]);
        void setPokemonEffortValues(int EffortValues[6]);
        void setPokemonNature(std::string pokemonNatureName);
        void setPokemonTypes(const Species*);
        void calculatePokemonStats();
        void setPokemonMoves(std::string inputMove1, std::string InputMove2, std::string inputMove3, std::string inputMove4);
        void evolve();
        void setPokemonCurrentStats();
        void calculateStageChanges();

        
        Pokemon(std::string inputName, const Species* inputSpecies, std::string inputNature, std::string inputAbility, int inputIndividualValues[6]);
        Pokemon(
            std::string inputName, const Species* inputSpecies, std::string inputNature, int inputLevel, int inputExperience, std::string inputAbility,
            std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4, 
            std::string inputCondition,
            int inputIndividualValues[6], int inputEffortValues[6]
        );
        ~Pokemon();
};

#endif