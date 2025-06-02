#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Type.h"
#include "Move.h"
#include "Growth_Rate.h"

void Pokemon::setSpeciesStats() {
    speciesStats = species->stats();
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
    nature = &natureMap.find(inputNature)->second;
}

void Pokemon::setPokemonTypes() {
    /* Types and the Types of a given Species need to be const as they are meant to be immutable
       However a given Pokemon's Types need to be mutable as they *can* be changed */
    type1 = const_cast<Type*>(species->type1());
    type2 = const_cast<Type*>(species->type2());
}

void Pokemon::setPokemonMoves(std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4) {
    moves[1] = &moveMap.find(inputMove1)->second;
    moves[2] = &moveMap.find(inputMove2)->second;
    moves[3] = &moveMap.find(inputMove3)->second;
    moves[4] = &moveMap.find(inputMove4)->second;
}

void Pokemon::calculatePokemonStats() {
    maxStats["HitPoints"] = std::max(floor(((2*speciesStats["HitPoints"]+individualValues["HitPoints"]+floor(effortValues["HitPoints"]/4.0))*level)/100)+level+10, 1.0);
    // Use the same formula to calculate all non-HitPoints stats;
    for (std::map<std::string, int>::iterator i = maxStats.begin(); i != maxStats.end(); i++) {
        std::string statName = i->first;
        if (statName == "HitPoints") {
            continue;
        }
        maxStats[statName] = std::max(floor(((2*speciesStats[statName]+individualValues[statName]+floor(effortValues[statName]/4.0))*level)/100+5) * nature->stats().at(statName), 1.0);
    }
    setPokemonCurrentStats();
}

void Pokemon::evolve() {
    int currentAbilityIndex;
    for (std::pair<int, std::string> speciesAbility : species->abilities()) {
        if (speciesAbility.second == ability) {
            currentAbilityIndex = speciesAbility.first;
        }
    }
    species = &(speciesMap.find(species->evolution())->second);
    ability = species->abilities().find(currentAbilityIndex)->second;
    setPokemonTypes();
    setSpeciesStats();
    calculatePokemonStats();
}

void Pokemon::setPokemonCurrentStats() {
    for (std::map<std::string, int>::iterator i = maxStats.begin(); i != maxStats.end(); i++) {
        currentStats[i->first] = i->second;
    }
}

void Pokemon::calculateStageChanges() {
    double stageMultiplier;
    std::string stageName;
    for (std::map<std::string, int>::iterator i = currentStages.begin(); i != std::prev(currentStages.end(), 2); i++) {
        stageName = i->first;
        if (currentStages[stageName] >= 0) {
            stageMultiplier = (currentStages[stageName]+2)/2.0;
        } else if (currentStages[stageName] < 0) {
            stageMultiplier = 2.0/(std::abs(currentStages[stageName]) + 2);
        }
    }
}

void Pokemon::addExperience(int inputExperience) {
    while (experience+inputExperience >= growthRateMap.find(species->growthRate())->second.toNextLevel().at(level)) {
        inputExperience -= (growthRateMap.find(species->growthRate())->second.toNextLevel().at(level) - experience);
        experience = 0;
        level += 1;
    }
    experience += inputExperience;
    calculatePokemonStats();
}

Pokemon::Pokemon(std::string inputName, Species* inputSpecies, std::string inputNature, std::string inputAbility, int inputIndividualValues[6]) {
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
}

Pokemon::Pokemon(
    std::string inputName, Species* inputSpecies, std::string inputNature, int inputLevel, int inputExperience, std::string inputAbility,
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
}

Pokemon::~Pokemon() {
    
}