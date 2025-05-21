#include <iostream>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Species.h"
#include "Display.h"
#include "Battle.h"
extern display Display;

int main() {
    std::cout << std::boolalpha;
    int zeroValues[6] = {};
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap["Charmander"]), "Modest", "Blaze", zeroValues);
    Display.PokemonName(myPokemon);
    Display.PokemonSpecies(myPokemon);
    Display.Nature(myPokemon);
    Display.PokemonStats(myPokemon);
    Display.SpeciesStats(myPokemon);
    Display.PokemonType(myPokemon);
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap["Charmander"]), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Pokemon myThirdPokemon = Pokemon("FireBoi3", &(speciesMap["Charmander"]), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    std::cout << "\nObject Created";
    Display.All(mySecondPokemon);
    mySecondPokemon.pokemonEvolve();
    std::cout << "\nEvolved Species Stats";
    Display.SpeciesStats(mySecondPokemon);
    Display.PokemonMovesAll(mySecondPokemon, 1);
    Battle(&mySecondPokemon, &myThirdPokemon);
    std::cout << "\n\nEnd Main";

    return 0;
}