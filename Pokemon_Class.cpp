#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Type.h"
#include "Move.h"

void Pokemon::setSpeciesStats(const Species* pokemonInputSpecies) {
    speciesHitPoints = pokemonInputSpecies->speciesStats[0];
    speciesAttack = pokemonInputSpecies->speciesStats[1];
    speciesDefense = pokemonInputSpecies->speciesStats[2];
    speciesSpecialAttack = pokemonInputSpecies->speciesStats[3];
    speciesSpecialDefense = pokemonInputSpecies->speciesStats[4];
    speciesSpeed = pokemonInputSpecies->speciesStats[5];
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

void Pokemon::setPokemonTypes(const Species* pokemonInputSpecies) {
    pokemonType1 = &typeMap.find(pokemonInputSpecies->speciesType1)->second;
    pokemonType2 = &typeMap.find(pokemonInputSpecies->speciesType2)->second;
}

void Pokemon::setPokemonMoves(std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4) {
    pokemonMove1 = &moveMap.find(pokemonInputMove1)->second;
    pokemonMove2 = &moveMap.find(pokemonInputMove2)->second;
    pokemonMove3 = &moveMap.find(pokemonInputMove3)->second;
    pokemonMove4 = &moveMap.find(pokemonInputMove4)->second;
}

void Pokemon::calculatePokemonStats() {
    pokemonHitPoints = std::max(floor(((2*speciesHitPoints+pokemonHitPointsIndividualValue+floor(pokemonHitPointsEffortValue/4.0))*pokemonLevel)/100)+pokemonLevel+10, 1.0);
    pokemonAttack = std::max(floor(((2*speciesAttack+pokemonAttackIndividualValue+floor(pokemonAttackEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureAttack, 1.0);
    pokemonDefense = std::max(floor(((2*speciesDefense+pokemonDefenseIndividualValue+floor(pokemonDefenseEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureDefense, 1.0);
    pokemonSpecialAttack = std::max(floor(((2*speciesSpecialAttack+pokemonSpecialAttackIndividualValue+floor(pokemonSpecialAttackEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureSpecialAttack, 1.0);
    pokemonSpecialDefense = std::max(floor(((2*speciesSpecialDefense+pokemonSpecialDefenseIndividualValue+floor(pokemonSpecialDefenseEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureSpecialDefense, 1.0);
    pokemonSpeed = std::max(floor(((2*speciesSpeed+pokemonSpeedIndividualValue+floor(pokemonSpeedEffortValue/4.0))*pokemonLevel)/100+5) * pokemonNature->natureSpeed, 1.0);
}

void Pokemon::pokemonEvolve() {
    int abilityIndex = std::find(pokemonSpecies->speciesAbilities, pokemonSpecies->speciesAbilities + (sizeof(pokemonSpecies->speciesAbilities) / sizeof(pokemonSpecies->speciesAbilities[0])), pokemonAbility) - pokemonSpecies->speciesAbilities;
    pokemonSpecies = &(speciesMap[pokemonSpecies->speciesEvolution]);
    pokemonAbility = pokemonSpecies->speciesAbilities[abilityIndex];
    setPokemonTypes(pokemonSpecies);
    setSpeciesStats(pokemonSpecies);
    calculatePokemonStats();
}

void Pokemon::setPokemonCurrentStats() {
    for (int i = 0; i < 6; i++) {
        *currentStats[i] = *pokemonStats[i];
    }
}

void Pokemon::calculateStageChanges() {
    double stageMultiplier;
    for (int i = 1; i < 6; i++) {
        if (*currentStages[i] >= 0) {
            stageMultiplier = (*currentStages[i]+2)/2.0;
        } else if (*currentStages[i] < 0) {
            stageMultiplier = 2.0/(std::abs(*currentStages[i])+2);
        }
        *currentStats[i] = *pokemonStats[i] * stageMultiplier;
    }
    if (currentAccuracyStage >= 0) {
        stageMultiplier = (currentAccuracyStage+3)/3.0;
    } else if (currentAccuracyStage < 0) {
        stageMultiplier = 3.0/(std::abs(currentAccuracyStage)+3);
    }
    currentAccuracy = 1 * stageMultiplier;
    if (currentEvasionStage < 0) {
        stageMultiplier = (currentEvasionStage+3)/3.0;
    } else if (currentEvasionStage >= 0) {
        stageMultiplier = 3.0/(std::abs(currentEvasionStage)+3);
    }
    currentEvasion = 1 * stageMultiplier;        
}

Pokemon::Pokemon(std::string pokemonInputName, const Species* pokemonInputSpecies, std::string pokemonInputNature, std::string pokemonInputAbility, int pokemonInputIndividualValues[6]) {
    pokemonName = pokemonInputName;
    pokemonSpecies = pokemonInputSpecies;
    setPokemonNature(pokemonInputNature);
    pokemonLevel = 1;
    pokemonExperience = 0;
    pokemonAbility = pokemonInputAbility;
    
    setPokemonTypes(pokemonInputSpecies);
    setSpeciesStats(pokemonInputSpecies);
    setPokemonIndividualValues(pokemonInputIndividualValues);
    int zeroEffortValues[6] = {};
    setPokemonEffortValues(zeroEffortValues);
    calculatePokemonStats();
    setPokemonCurrentStats();
}

Pokemon::Pokemon(
    std::string pokemonInputName, const Species* pokemonInputSpecies, std::string pokemonInputNature, int pokemonInputLevel, int pokemonInputExperience, std::string pokemonInputAbility,
    std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4, 
    std::string pokemonInputCondition,
    int pokemonInputIndividualValues[6], int pokemonInputEffortValues[6]
) {
    pokemonName = pokemonInputName;
    pokemonSpecies = pokemonInputSpecies;
    setPokemonNature(pokemonInputNature);
    pokemonLevel = pokemonInputLevel;
    pokemonExperience = pokemonInputExperience;
    pokemonAbility = pokemonInputAbility;
    
    setPokemonTypes(pokemonInputSpecies);
    
    setPokemonMoves(pokemonInputMove1, pokemonInputMove2, pokemonInputMove3, pokemonInputMove4);
    
    pokemonCondition = pokemonInputCondition;
    
    setSpeciesStats(pokemonInputSpecies);
    setPokemonIndividualValues(pokemonInputIndividualValues);
    setPokemonEffortValues(pokemonInputEffortValues);
    calculatePokemonStats();
    setPokemonCurrentStats();
}

Pokemon::~Pokemon() {
    
}