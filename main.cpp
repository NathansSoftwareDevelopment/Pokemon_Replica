#include <iostream>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Species.h"
#include "Display.h"
#include "Battle.h"
#include "Growth_Rate.h"
extern display Display;

int main() {
    std::cout << std::boolalpha;
    int zeroValues[6] = {};
    generateSpeciesMap();
    makeGrowthRates();
    generateMoveMap();
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap["charmander"]), "Modest", "Blaze", zeroValues);
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap["charmander"]), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Pokemon myThirdPokemon = Pokemon("FireBoi3", &(speciesMap["charmander"]), "Modest", 5, 750000, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Display.all(&mySecondPokemon, "zekrom", "Ember");
    Display.moveAll(&moveMap.find("Growl")->second);
    mySecondPokemon.addExperience(1000);
    myThirdPokemon.addExperience(1000);
    Pokemon myVenusaur = Pokemon("Venu", &(speciesMap["venusaur"]), "Modest", 55, 0, "Blaze", "Flamethrower", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Pokemon myZekrom = Pokemon("zekky", &(speciesMap["zekrom"]), "Modest", 62, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    // std::cout << mySecondPokemon.level << " | " << mySecondPokemon.experience << std::endl;
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    // Battle(&mySecondPokemon, &myThirdPokemon);
    std::cout << "Zekrom Experience: " << myZekrom.species->experienceValue << std::endl;
    Battle(&myVenusaur, &myZekrom);
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    std::cout << "\n\nEnd Main";
    return 0;
}