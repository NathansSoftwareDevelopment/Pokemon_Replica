#include <iostream>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Species.h"

int main() {
    int zeroValues[6] = {};
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap["Charmander"]), "Modest", "Blaze", zeroValues);
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
    std::cout << "\nPokemon Types\n";
    std::cout << myPokemon.pokemonType1->typeName << std::endl;
    std::cout << myPokemon.pokemonType2->typeName << std::endl;
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap["Charmander"]), "Modest", 100, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    std::cout << "Object Created" << std::endl;
    std::cout << mySecondPokemon.pokemonName << std::endl;
    std::cout << mySecondPokemon.pokemonSpecies->speciesName << std::endl;
    std::cout << "\nPokemon Nature\n";
    for (float* i : mySecondPokemon.pokemonNature->natureStats) {
        std::cout << *i << std::endl;
    };
    std::cout << "\nPokemon Stats\n";
    for (int* i : mySecondPokemon.pokemonStats) {
        std::cout << *i << std::endl;
    };
    std::cout << "\nSpecies Stats\n";
    for (int* i : mySecondPokemon.speciesStats) {
        std::cout << *i << std::endl;
    };
    std::cout << "\nPokemon Types\n";
    std::cout << mySecondPokemon.pokemonType1->typeName << std::endl;
    std::cout << mySecondPokemon.pokemonType2->typeName << std::endl;
    std::cout << "\nPokemon Moves\n";
    for (Move** i : mySecondPokemon.pokemonMoves) {
        std::cout << (*i)->moveName << std::endl;
    };
    std::cout << "\n\nEnd Main";

    return 0;
}