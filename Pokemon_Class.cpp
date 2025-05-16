#include <cmath>
#include "Pokemon_Class.h"

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

void Pokemon::calculatePokemonStats() {
    pokemonHitPoints = floor((2*speciesHitPoints+pokemonHitPointsIndividualValue+floor(0.25*pokemonHitPointsEffortValue/1)*pokemonLevel)/100)+pokemonLevel+10;
    pokemonAttack = floor((2*speciesAttack+pokemonAttackIndividualValue+floor(0.25*pokemonAttackEffortValue/1)*pokemonLevel)/100+5) * 1;
}