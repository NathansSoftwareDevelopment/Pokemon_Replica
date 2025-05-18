#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H

#include <string>
#include "Nature.h"

class Pokemon {
    public:
        std::string pokemonSpecies;
        std::string pokemonName;

        int pokemonLevel;
        int pokemonExperience;

        Nature* pokemonNature;
        
        std::string pokemonAbility;
        
        std::string pokemonItem;

        std::string pokemonType1;
        std::string pokemonType2;

        std::string pokemonMove1;
        std::string pokemonMove2;
        std::string pokemonMove3;
        std::string pokemonMove4;
        std::string* pokemonMoves[4] = {
            &pokemonMove1,
            &pokemonMove2,
            &pokemonMove3,
            &pokemonMove4
        };
        
        std::string pokemonCondition;

        int speciesHitPoints;
        int speciesAttack;
        int speciesDefense;
        int speciesSpecialAttack;
        int speciesSpecialDefense;
        int speciesSpeed;
        int* speciesStats[6] = {
            &speciesHitPoints,
            &speciesAttack,
            &speciesDefense,
            &speciesSpecialAttack,
            &speciesSpecialDefense,
            &speciesSpeed
        };
        
        int pokemonHitPointsIndividualValue;
        int pokemonAttackIndividualValue;
        int pokemonDefenseIndividualValue;
        int pokemonSpecialAttackIndividualValue;
        int pokemonSpecialDefenseIndividualValue;
        int pokemonSpeedIndividualValue;
        int* pokemonIndividualValues[6] = {
            &pokemonHitPointsIndividualValue,
            &pokemonAttackIndividualValue,
            &pokemonDefenseIndividualValue,
            &pokemonSpecialAttackIndividualValue,
            &pokemonSpecialDefenseIndividualValue,
            &pokemonSpeedIndividualValue
        };

        int pokemonHitPointsEffortValue;
        int pokemonAttackEffortValue;
        int pokemonDefenseEffortValue;
        int pokemonSpecialAttackEffortValue;
        int pokemonSpecialDefenseEffortValue;
        int pokemonSpeedEffortValue;
        int* pokemonEffortValues[6] = {
            &pokemonHitPointsEffortValue,
            &pokemonAttackEffortValue,
            &pokemonDefenseEffortValue,
            &pokemonSpecialAttackEffortValue,
            &pokemonSpecialDefenseEffortValue,
            &pokemonSpeedEffortValue
        };

        int pokemonHitPoints;
        int pokemonAttack;
        int pokemonDefense;
        int pokemonSpecialAttack;
        int pokemonSpecialDefense;
        int pokemonSpeed;
        int* pokemonStats[6] = {
            &pokemonHitPoints,
            &pokemonAttack,
            &pokemonDefense,
            &pokemonSpecialAttack,
            &pokemonSpecialDefense,
            &pokemonSpeed
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
            &currentSpeed
        };

        void setSpeciesStats(int speciesStats[6]);
        void setPokemonIndividualValues(int IndividualValues[6]);
        void setPokemonEffortValues(int EffortValues[6]);
        void setPokemonNature(std::string pokemonNatureName);
        void calculatePokemonStats();

        
        Pokemon(std::string pokemonInputSpecies, std::string pokemonInputName, std::string pokemonInputNature, std::string pokemonInputAbility, int speciesInputStats[6], int pokemonInputIndividualValues[6]);
        Pokemon(
            std::string pokemonInputSpecies, std::string pokemonInputName, std::string pokemonInputNature, int pokemonInputLevel, int pokemonInputExperience, std::string pokemonInputAbility,
            std::string pokemonInputType1, std::string pokemonInputType2,
            std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4, 
            std::string pokemonInputCondition,
            int speciesStats[6], int pokemonInputIndividualValues[6], int pokemonInputEffortValues[6]
        );
        virtual ~Pokemon() = 0;
};

#endif