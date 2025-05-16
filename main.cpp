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
    std::cout << myPokemon.pokemonNature->natureAttack << std::endl;
    std::cout << myPokemon.pokemonNature->natureDefense << std::endl;
    std::cout << myPokemon.pokemonNature->natureSpeed << std::endl;
    std::cout << myPokemon.pokemonNature->natureSpecialAttack << std::endl;
    std::cout << myPokemon.pokemonNature->natureSpecialDefense << std::endl;
    std::cout << "\nPokemon Stats\n";
    std::cout << myPokemon.pokemonHitPoints << std::endl;
    std::cout << myPokemon.pokemonAttack << std::endl;
    std::cout << myPokemon.pokemonDefense << std::endl;
    std::cout << myPokemon.pokemonSpecialAttack << std::endl;
    std::cout << myPokemon.pokemonSpecialDefense << std::endl;
    std::cout << myPokemon.pokemonSpeed << std::endl;
    std::cout << "\nSpecies Stats\n";
    std::cout << myPokemon.speciesHitPoints << std::endl;
    std::cout << myPokemon.speciesAttack << std::endl;
    std::cout << myPokemon.speciesDefense << std::endl;
    std::cout << myPokemon.speciesSpecialAttack << std::endl;
    std::cout << myPokemon.speciesSpecialDefense << std::endl;
    std::cout << myPokemon.speciesSpeed << std::endl;
    return 0;
}