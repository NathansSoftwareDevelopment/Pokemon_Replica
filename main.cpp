#include <iostream>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Pokemon_Species/Charmander/Charmander.h"
#include "Type.h"

int main() {
    int zeroValues[6] = {};
    Charmander myPokemon = Charmander("FireBoi", "Modest", "Blaze", zeroValues);
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
    for (auto i : zeroValues) {
        std::cout << i << std::endl;
    };

    Charmander mySecondPokemon = Charmander("FireBoi2", "Modest", 100, 0, "Blaze", "None", "None", "None", "None", "None", zeroValues, zeroValues);
    std::cout << "Object Created" << std::endl;
    std::cout << mySecondPokemon.pokemonName << std::endl;
    std::cout << mySecondPokemon.pokemonSpecies << std::endl;
    std::cout << "\nPokemon Nature\n";
    for (float* i : mySecondPokemon.pokemonNature->natureStats) {
        std::cout << *i << std::endl;
    };
    std::cout << "\nPokemon Stats\n";
    for (int* i : mySecondPokemon.pokemonStats) {
        std::cout << *i << std::endl;
    };
    std::cout << "\nSpecies Stats\n";
    for (int* i: mySecondPokemon.speciesStats) {
        std::cout << *i << std::endl;
    };

    return 0;
}