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

void Pokemon::setPokemonIndividualValues(int individualValues[6]) {
    hitPointsIndividualValue = individualValues[0];
    attackIndividualValue = individualValues[1];
    defenseIndividualValue = individualValues[2];
    specialAttackIndividualValue = individualValues[3];
    specialDefenseIndividualValue = individualValues[4];
    speedIndividualValue = individualValues[5];
}

void Pokemon::setPokemonEffortValues(int EffortValues[6]) {
    hitPointsEffortValue = EffortValues[0];
    attackEffortValue = EffortValues[1];
    defenseEffortValue = EffortValues[2];
    specialAttackEffortValue = EffortValues[3];
    specialDefenseEffortValue = EffortValues[4];
    speedEffortValue = EffortValues[5];
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
    move1 = &moveMap.find(inputMove1)->second;
    move2 = &moveMap.find(inputMove2)->second;
    move3 = &moveMap.find(inputMove3)->second;
    move4 = &moveMap.find(inputMove4)->second;
}

void Pokemon::calculatePokemonStats() {
    maxHitPoints = std::max(floor(((2*speciesStats["HitPoints"]+hitPointsIndividualValue+floor(hitPointsEffortValue/4.0))*level)/100)+level+10, 1.0);
    maxAttack = std::max(floor(((2*speciesStats["Attack"]+attackIndividualValue+floor(attackEffortValue/4.0))*level)/100+5) * nature->attack, 1.0);
    maxDefense = std::max(floor(((2*speciesStats["Defense"]+defenseIndividualValue+floor(defenseEffortValue/4.0))*level)/100+5) * nature->defense, 1.0);
    maxSpecialAttack = std::max(floor(((2*speciesStats["SpecialAttack"]+specialAttackIndividualValue+floor(specialAttackEffortValue/4.0))*level)/100+5) * nature->specialAttack, 1.0);
    maxSpecialDefense = std::max(floor(((2*speciesStats["SpecialDefense"]+specialDefenseIndividualValue+floor(specialDefenseEffortValue/4.0))*level)/100+5) * nature->specialDefense, 1.0);
    maxSpeed = std::max(floor(((2*speciesStats["Speed"]+speedIndividualValue+floor(speedEffortValue/4.0))*level)/100+5) * nature->speed, 1.0);
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