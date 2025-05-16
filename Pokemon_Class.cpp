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

void Pokemon::setPokemonNature(std::string pokemonNatureName) {
    for (Nature nature : natureArray) {
        if (nature.natureName == pokemonNatureName) {
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