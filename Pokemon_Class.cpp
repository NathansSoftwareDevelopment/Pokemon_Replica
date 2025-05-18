#include <iostream>
#include <cmath>
#include "Pokemon_Class.h"
#include "Nature.h"

void Pokemon::setSpeciesStats(int speciesStats[6]) {
    speciesHitPoints = speciesStats[0];
    speciesAttack = speciesStats[1];
    speciesDefense = speciesStats[2];
    speciesSpecialAttack = speciesStats[3];
    speciesSpecialDefense = speciesStats[4];
    speciesSpeed = speciesStats[5];
}

void Pokemon::setPokemonIndividualValues(int pokemonIndividualValues[6]) {
    pokemonHitPointsIndividualValue = pokemonIndividualValues[0];
    pokemonAttackIndividualValue = pokemonIndividualValues[1];
    pokemonDefenseIndividualValue = pokemonIndividualValues[2];
    pokemonSpecialAttackIndividualValue = pokemonIndividualValues[3];
    pokemonSpecialDefenseIndividualValue = pokemonIndividualValues[4];
    pokemonSpeedIndividualValue = pokemonIndividualValues[5];
}

void Pokemon::setPokemonEffortValues(int pokemonEffortValues[6]) {
    pokemonHitPointsEffortValue = pokemonEffortValues[0];
    pokemonAttackEffortValue = pokemonEffortValues[1];
    pokemonDefenseEffortValue = pokemonEffortValues[2];
    pokemonSpecialAttackEffortValue = pokemonEffortValues[3];
    pokemonSpecialDefenseEffortValue = pokemonEffortValues[4];
    pokemonSpeedEffortValue = pokemonEffortValues[5];
}

void Pokemon::setPokemonNature(std::string pokemonInputNature) {
    for (Nature& nature : natureArray) {
        if (nature.natureName == pokemonInputNature) {
            pokemonNature = &nature;
        }
    }
}

void Pokemon::calculatePokemonStats() {
    pokemonHitPoints = floor(((2*speciesHitPoints+pokemonHitPointsIndividualValue+floor(pokemonHitPointsEffortValue/4.0))*pokemonLevel)/100)+pokemonLevel+10;
    pokemonAttack = floor(((2*speciesAttack+pokemonAttackIndividualValue+floor(pokemonAttackEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureAttack;
    pokemonDefense = floor(((2*speciesDefense+pokemonDefenseIndividualValue+floor(pokemonDefenseEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureDefense;
    pokemonSpecialAttack = floor(((2*speciesSpecialAttack+pokemonSpecialAttackIndividualValue+floor(pokemonSpecialAttackEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureSpecialAttack;
    pokemonSpecialDefense = floor(((2*speciesSpecialDefense+pokemonSpecialDefenseIndividualValue+floor(pokemonSpecialDefenseEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureSpecialDefense;
    pokemonSpeed = floor(((2*speciesSpeed+pokemonSpeedIndividualValue+floor(pokemonSpeedEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureSpeed;
}

Pokemon::Pokemon(std::string pokemonInputSpecies, std::string pokemonInputName, std::string pokemonInputNature, std::string pokemonInputAbility, int speciesInputStats[6], int pokemonInputIndividualValues[6]) {
    pokemonSpecies = pokemonInputSpecies;
    pokemonName = pokemonInputName;
    
    pokemonLevel = 1;
    
    setPokemonNature(pokemonInputNature);
    pokemonAbility = pokemonInputAbility;
    speciesHitPoints = speciesInputStats[0];
    speciesAttack = speciesInputStats[1];
    speciesDefense = speciesInputStats[2];
    speciesSpecialAttack = speciesInputStats[3];
    speciesSpecialDefense = speciesInputStats[4];
    speciesSpeed = speciesInputStats[5];
    setPokemonIndividualValues(pokemonInputIndividualValues);
    int zeroEffortValues[6] = {};
    setPokemonEffortValues(zeroEffortValues);
    calculatePokemonStats();
}

Pokemon::Pokemon(
    std::string pokemonInputSpecies, std::string pokemonInputName, std::string pokemonInputNature, int pokemonInputLevel, int pokemonInputExperience, std::string pokemonInputAbility,
    std::string pokemonInputType1, std::string pokemonInputType2,
    std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4, 
    std::string pokemonInputCondition,
    int speciesInputStats[6], int pokemonInputIndividualValues[6], int pokemonInputEffortValues[6]
) {
    pokemonSpecies = pokemonInputSpecies;
    pokemonName = pokemonInputName;
    setPokemonNature(pokemonInputNature);
    pokemonLevel = pokemonInputLevel;
    pokemonExperience = pokemonInputExperience;
    pokemonAbility = pokemonInputAbility;
    
    pokemonType1 = pokemonInputType1;
    pokemonType2 = pokemonInputType2;
    
    pokemonMove1 = pokemonInputMove1;
    pokemonMove2 = pokemonInputMove2;
    pokemonMove3 = pokemonInputMove3;
    pokemonMove4 = pokemonInputMove4;
    
    pokemonCondition = pokemonInputCondition;
    
    speciesHitPoints = speciesInputStats[0];
    speciesAttack = speciesInputStats[1];
    speciesDefense = speciesInputStats[2];
    speciesSpecialAttack = speciesInputStats[3];
    speciesSpecialDefense = speciesInputStats[4];
    speciesSpeed = speciesInputStats[5];
    setPokemonIndividualValues(pokemonInputIndividualValues);
    setPokemonEffortValues(pokemonInputEffortValues);
    calculatePokemonStats();
}

Pokemon::~Pokemon() {
    
}