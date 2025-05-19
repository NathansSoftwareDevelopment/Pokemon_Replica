#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H

#include <string>
#include "Nature.h"
#include "Type.h"
#include "Move.h"
#include "Species.h"

class Pokemon {
    public:
        const Species* pokemonSpecies;
        std::string pokemonName;

        int pokemonLevel;
        int pokemonExperience;

        Nature* pokemonNature;
        
        std::string pokemonAbility;
        
        std::string pokemonItem;

        Type* pokemonType1;
        Type* pokemonType2;

        Move* pokemonMove1;
        Move* pokemonMove2;
        Move* pokemonMove3;
        Move* pokemonMove4;
        Move** pokemonMoves[4] = {
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

        void setSpeciesStats(const Species*);
        void setPokemonIndividualValues(int IndividualValues[6]);
        void setPokemonEffortValues(int EffortValues[6]);
        void setPokemonNature(std::string pokemonNatureName);
        void setPokemonTypes(const Species*);
        void calculatePokemonStats();
        void setPokemonMoves(std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4);

        
        Pokemon(std::string pokemonInputName, Species* pokemonInputSpecies, std::string pokemonInputNature, std::string pokemonInputAbility,int pokemonInputIndividualValues[6]);
        Pokemon(
            std::string pokemonInputName, const Species* pokemonInputSpecies, std::string pokemonInputNature, int pokemonInputLevel, int pokemonInputExperience, std::string pokemonInputAbility,
            std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4, 
            std::string pokemonInputCondition,
            int pokemonInputIndividualValues[6], int pokemonInputEffortValues[6]
        );
        ~Pokemon();
};

#endif