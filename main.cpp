#include <iostream>
#include "Pokemon_Class.h"
#include "Nature.h"

int main() {
    int charmanderSpeciesStats[6] = {39, 52, 43, 60, 50, 65};
    int zeroIndividualValues[6] = {};
    Pokemon myPokemon = Pokemon("Charmander", "FireBoi", "Modest", "Blaze", charmanderSpeciesStats, zeroIndividualValues);
    std::cout << myPokemon.pokemonName << std::endl;
    std::cout << myPokemon.pokemonSpecies << std::endl;
    std::cout << "\nPokemon Nature\n";
    for (float* i : myPokemon.pokemonNature->natureStats) {
        std::cout << *i << std::endl;
    };
    std::cout << "\nPokemon Stats\n";
    for (int* i : myPokemon.pokemonStats) {
        std::cout << *i << std::endl;
    };
    std::cout << "\nSpecies Stats\n";
    for (int* i: myPokemon.speciesStats) {
        std::cout << *i << std::endl;
    };

    return 0;
}