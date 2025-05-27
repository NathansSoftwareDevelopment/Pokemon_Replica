#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Type.h"
#include "Move.h"

void Pokemon::setSpeciesStats() {
    speciesStats = species->stats;
}

void Pokemon::setPokemonIndividualValues(int inputValues[6]) {
    individualValues["HitPoints"] = inputValues[0];
    individualValues["Attack"] = inputValues[1];
    individualValues["Defense"] = inputValues[2];
    individualValues["SpecialAttack"] = inputValues[3];
    individualValues["SpecialDefense"] = inputValues[4];
    individualValues["Speed"] = inputValues[5];
}

void Pokemon::setPokemonEffortValues(int inputValues[6]) {
    effortValues["HitPoints"] = inputValues[0];
    effortValues["Attack"] = inputValues[1];
    effortValues["Defense"] = inputValues[2];
    effortValues["SpecialAttack"] = inputValues[3];
    effortValues["SpecialDefense"] = inputValues[4];
    effortValues["Speed"] = inputValues[5];
}

void Pokemon::setPokemonNature(std::string inputNature) {
    for (Nature& i : natureArray) {
        if (i.name == inputNature) {
            nature = &i;
        }
    }
}

void Pokemon::setPokemonTypes() {
    type1 = &typeMap.find(species->type1)->second;
    type2 = &typeMap.find(species->type2)->second;
}

void Pokemon::setPokemonMoves(std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4) {
    moves[1] = &moveMap.find(inputMove1)->second;
    moves[2] = &moveMap.find(inputMove2)->second;
    moves[3] = &moveMap.find(inputMove3)->second;
    moves[4] = &moveMap.find(inputMove4)->second;
}

void Pokemon::calculatePokemonStats() {
    maxHitPoints = std::max(floor(((2*speciesStats["HitPoints"]+individualValues["HitPoints"]+floor(effortValues["HitPoints"]/4.0))*level)/100)+level+10, 1.0);
    maxAttack = std::max(floor(((2*speciesStats["Attack"]+individualValues["Attack"]+floor(effortValues["Attack"]/4.0))*level)/100+5) * nature->attack, 1.0);
    maxDefense = std::max(floor(((2*speciesStats["Defense"]+individualValues["Defense"]+floor(effortValues["Defense"]/4.0))*level)/100+5) * nature->defense, 1.0);
    maxSpecialAttack = std::max(floor(((2*speciesStats["SpecialAttack"]+individualValues["SpecialAttack"]+floor(effortValues["SpecialAttack"]/4.0))*level)/100+5) * nature->specialAttack, 1.0);
    maxSpecialDefense = std::max(floor(((2*speciesStats["SpecialDefense"]+individualValues["SpecialDefense"]+floor(effortValues["SpecialDefense"]/4.0))*level)/100+5) * nature->specialDefense, 1.0);
    maxSpeed = std::max(floor(((2*speciesStats["Speed"]+individualValues["Speed"]+floor(effortValues["Speed"]/4.0))*level)/100+5) * nature->speed, 1.0);
}

void Pokemon::evolve() {
    int abilityIndex = std::find(species->abilities, species->abilities + (sizeof(species->abilities) / sizeof(species->abilities[0])), ability) - species->abilities;
    species = &(speciesMap[species->evolution]);
    ability = species->abilities[abilityIndex];
    setPokemonTypes();
    setSpeciesStats();
    calculatePokemonStats();
}

void Pokemon::setPokemonCurrentStats() {
    for (int i = 0; i < 6; i++) {
        *currentStats[i] = *maxStats[i];
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
        *currentStats[i] = *maxStats[i] * stageMultiplier;
    }
}

Pokemon::Pokemon(std::string inputName, const Species* inputSpecies, std::string inputNature, std::string inputAbility, int inputIndividualValues[6]) {
    name = inputName;
    species = inputSpecies;
    setPokemonNature(inputNature);
    level = 1;
    experience = 0;
    ability = inputAbility;
    
    setPokemonTypes();
    setSpeciesStats();
    setPokemonIndividualValues(inputIndividualValues);
    int zeroEffortValues[6] = {};
    setPokemonEffortValues(zeroEffortValues);
    calculatePokemonStats();
    setPokemonCurrentStats();
}

Pokemon::Pokemon(
    std::string inputName, const Species* inputSpecies, std::string inputNature, int inputLevel, int inputExperience, std::string inputAbility,
    std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4, 
    std::string inputCondition,
    int inputIndividualValues[6], int inputEffortValues[6]
) {
    name = inputName;
    species = inputSpecies;
    setPokemonNature(inputNature);
    level = inputLevel;
    experience = inputExperience;
    ability = inputAbility;
    
    setPokemonTypes();
    
    setPokemonMoves(inputMove1, inputMove2, inputMove3, inputMove4);
    
    condition = inputCondition;
    
    setSpeciesStats();
    setPokemonIndividualValues(inputIndividualValues);
    setPokemonEffortValues(inputEffortValues);
    calculatePokemonStats();
    setPokemonCurrentStats();
}

Pokemon::~Pokemon() {
    
}