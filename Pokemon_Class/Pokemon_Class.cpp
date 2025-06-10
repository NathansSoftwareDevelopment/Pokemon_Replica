#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Type.h"
#include "Move.h"
#include "Growth_Rate.h"
#include "Utils.hpp"

Pokemon& Pokemon::trainer(Trainer* inputTrainer) {
    _trainer = inputTrainer;
    return *this;
}

void Pokemon::setSpeciesStats() {
    _speciesStats = _species->stats();
}

void Pokemon::setPokemonIndividualValues(int inputValues[6]) {
    _individualValues["HitPoints"] = inputValues[0];
    _individualValues["Attack"] = inputValues[1];
    _individualValues["Defense"] = inputValues[2];
    _individualValues["SpecialAttack"] = inputValues[3];
    _individualValues["SpecialDefense"] = inputValues[4];
    _individualValues["Speed"] = inputValues[5];
}

Pokemon& Pokemon::effortValues(int inputValues[6]) {
    _effortValues["HitPoints"] = inputValues[0];
    _effortValues["Attack"] = inputValues[1];
    _effortValues["Defense"] = inputValues[2];
    _effortValues["SpecialAttack"] = inputValues[3];
    _effortValues["SpecialDefense"] = inputValues[4];
    _effortValues["Speed"] = inputValues[5];
    return *this;
}

void Pokemon::setPokemonNature(std::string inputNature) {
    _nature = &natureMap.find(inputNature)->second;
}

Pokemon& Pokemon::pokemonTypes() {
    /* Types and the Types of a given Species need to be const as they are meant to be immutable
       However a given Pokemon's Types need to be mutable as they *can* be changed */
    _type1 = const_cast<Type*>(_species->type1());
    _type2 = const_cast<Type*>(_species->type2());
    return *this;
}

void Pokemon::setPokemonMoves(std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4) {
    _moves[1] = &moveMap.find(inputMove1)->second;
    _moves[2] = &moveMap.find(inputMove2)->second;
    _moves[3] = &moveMap.find(inputMove3)->second;
    _moves[4] = &moveMap.find(inputMove4)->second;
}

void Pokemon::calculatePokemonStats() {
    _maxStats["HitPoints"] = std::max(floor(((2*_speciesStats["HitPoints"]+_individualValues["HitPoints"]+floor(_effortValues["HitPoints"]/4.0))*_level)/100)+_level+10, 1.0);
    // Use the same formula to calculate all non-HitPoints stats;
    for (std::map<std::string, int>::iterator i = _maxStats.begin(); i != _maxStats.end(); i++) {
        std::string statName = i->first;
        if (statName == "HitPoints") {
            continue;
        }
        _maxStats[statName] = std::max(floor(((2*_speciesStats[statName]+_individualValues[statName]+floor(_effortValues[statName]/4.0))*_level)/100+5) * _nature->stats().at(statName), 1.0);
    }
    pokemonCurrentStats();
}

void Pokemon::evolve() {
    int currentAbilityIndex;
    for (std::pair<int, std::string> speciesAbility : _species->abilities()) {
        if (speciesAbility.second == _ability) {
            currentAbilityIndex = speciesAbility.first;
        }
    }
    _species = &(speciesMap.find(_species->evolution())->second);
    _ability = _species->abilities().find(currentAbilityIndex)->second;
    pokemonTypes();
    setSpeciesStats();
    calculatePokemonStats();
}

Pokemon& Pokemon::pokemonCurrentStats() {
    for (std::map<std::string, int>::iterator i = _maxStats.begin(); i != _maxStats.end(); i++) {
        _currentStats[i->first] = i->second;
    }
    return *this;
}

void Pokemon::calculateStageChanges() {
    double stageMultiplier;
    std::string stageName;
    for (std::map<std::string, int>::iterator i = _currentStages.begin(); i != _currentStages.end(); i++) {
        stageName = i->first;
        if (stageName == "Accuracy" || stageName == "Evasion") {
            continue;
        }
        if (_currentStages[stageName] >= 0) {
            stageMultiplier = (_currentStages[stageName]+2)/2.0;
        } else if (_currentStages[stageName] < 0) {
            stageMultiplier = 2.0/(std::abs(_currentStages[stageName]) + 2);
        }
    }
}

void Pokemon::addExperience(int inputExperience) {
    while (_experience+inputExperience >= growthRateMap.find(_species->growthRate())->second.toNextLevel().at(_level)) {
        inputExperience -= (growthRateMap.find(_species->growthRate())->second.toNextLevel().at(_level) - _experience);
        _experience = 0;
        _level += 1;
    }
    _experience += inputExperience;
    calculatePokemonStats();
}

Pokemon::Pokemon(
    std::string inputName, Species* inputSpecies, std::string inputNature, int inputLevel, int inputExperience, std::string inputAbility,
    std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4, 
    std::string inputCondition,
    int inputIndividualValues[6], int inputEffortValues[6]
) {
    _name = inputName;
    _species = inputSpecies;
    setPokemonNature(inputNature);
    _level = inputLevel;
    _experience = inputExperience;
    _ability = inputAbility;
    
    pokemonTypes();
    
    setPokemonMoves(inputMove1, inputMove2, inputMove3, inputMove4);
    
    _condition = inputCondition;
    
    setSpeciesStats();
    setPokemonIndividualValues(inputIndividualValues);
    effortValues(inputEffortValues);
    calculatePokemonStats();
    _personalityValue = generateRandom(0, 4294967295);
}

Pokemon::~Pokemon() {
    
}