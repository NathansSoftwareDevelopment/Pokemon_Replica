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
    generateSpeciesMap();
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap["charmander"]), "Modest", "Blaze", zeroValues);
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap["charmander"]), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Pokemon myThirdPokemon = Pokemon("FireBoi3", &(speciesMap["charmander"]), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Display.all(&mySecondPokemon, "zekrom", "Ember");
    Battle(&mySecondPokemon, &myThirdPokemon);
    std::cout << "\n\nEnd Main";
    return 0;
}