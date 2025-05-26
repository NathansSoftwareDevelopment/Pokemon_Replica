#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Type.h"
#include "Move.h"

void Pokemon::setSpeciesStats(const Species* inputSpecies) {
    speciesStats = inputSpecies->stats;
}

void Pokemon::setPokemonIndividualValues(int individualValues[6]) {
    HitPointsIndividualValue = individualValues[0];
    AttackIndividualValue = individualValues[1];
    DefenseIndividualValue = individualValues[2];
    SpecialAttackIndividualValue = individualValues[3];
    SpecialDefenseIndividualValue = individualValues[4];
    SpeedIndividualValue = individualValues[5];
}

void Pokemon::setPokemonEffortValues(int EffortValues[6]) {
    HitPointsEffortValue = EffortValues[0];
    AttackEffortValue = EffortValues[1];
    DefenseEffortValue = EffortValues[2];
    SpecialAttackEffortValue = EffortValues[3];
    SpecialDefenseEffortValue = EffortValues[4];
    SpeedEffortValue = EffortValues[5];
}

void Pokemon::setPokemonNature(std::string inputNature) {
    for (Nature& i : natureArray) {
        if (i.name == inputNature) {
            nature = &i;
        }
    }
}

void Pokemon::setPokemonTypes(const Species* inputSpecies) {
    type1 = &typeMap.find(inputSpecies->type1)->second;
    type2 = &typeMap.find(inputSpecies->type2)->second;
}

void Pokemon::setPokemonMoves(std::string inputMove1, std::string inputMove2, std::string inputMove3, std::string inputMove4) {
    move1 = &moveMap.find(inputMove1)->second;
    move2 = &moveMap.find(inputMove2)->second;
    move3 = &moveMap.find(inputMove3)->second;
    move4 = &moveMap.find(inputMove4)->second;
}

void Pokemon::calculatePokemonStats() {
    maxHitPoints = std::max(floor(((2*speciesStats["HitPoints"]+HitPointsIndividualValue+floor(HitPointsEffortValue/4.0))*level)/100)+level+10, 1.0);
    maxAttack = std::max(floor(((2*speciesStats["Attack"]+AttackIndividualValue+floor(AttackEffortValue/4.0))*level)/100+5) * nature->attack, 1.0);
    maxDefense = std::max(floor(((2*speciesStats["Defense"]+DefenseIndividualValue+floor(DefenseEffortValue/4.0))*level)/100+5) * nature->defense, 1.0);
    maxSpecialAttack = std::max(floor(((2*speciesStats["SpecialAttack"]+SpecialAttackIndividualValue+floor(SpecialAttackEffortValue/4.0))*level)/100+5) * nature->specialAttack, 1.0);
    maxSpecialDefense = std::max(floor(((2*speciesStats["SpecialDefense"]+SpecialDefenseIndividualValue+floor(SpecialDefenseEffortValue/4.0))*level)/100+5) * nature->specialDefense, 1.0);
    maxSpeed = std::max(floor(((2*speciesStats["Speed"]+SpeedIndividualValue+floor(SpeedEffortValue/4.0))*level)/100+5) * nature->speed, 1.0);
}

void Pokemon::evolve() {
    int abilityIndex = std::find(species->abilities, species->abilities + (sizeof(species->abilities) / sizeof(species->abilities[0])), ability) - species->abilities;
    species = &(speciesMap[species->evolution]);
    ability = species->abilities[abilityIndex];
    setPokemonTypes(species);
    setSpeciesStats(species);
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
    
    setPokemonTypes(inputSpecies);
    setSpeciesStats(inputSpecies);
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
    
    setPokemonTypes(inputSpecies);
    
    setPokemonMoves(inputMove1, inputMove2, inputMove3, inputMove4);
    
    condition = inputCondition;
    
    setSpeciesStats(inputSpecies);
    setPokemonIndividualValues(inputIndividualValues);
    setPokemonEffortValues(inputEffortValues);
    calculatePokemonStats();
    setPokemonCurrentStats();
}

Pokemon::~Pokemon() {
    
}