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
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap.find("charmander")->second), "Modest", "Blaze", zeroValues);
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap.find("charmander")->second), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Pokemon myThirdPokemon = Pokemon("FireBoi3", &(speciesMap.find("charmander")->second), "Modest", 5, 750000, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Display.all(&mySecondPokemon, "zekrom", "Ember");
    Display.moveAll(&moveMap.find("Growl")->second);
    Display.speciesAll(&(speciesMap.find("charmander")->second));
    Display.speciesAll(&(speciesMap.find("haxorus")->second));
    mySecondPokemon.addExperience(1000);
    myThirdPokemon.addExperience(1000);
    Pokemon myVenusaur = Pokemon("Venu", &(speciesMap.find("venusaur")->second), "Modest", 55, 0, "Blaze", "Frenzy Plant", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    Pokemon myZekrom = Pokemon("zekky", &(speciesMap.find("zekrom")->second), "Modest", 62, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", zeroValues, zeroValues);
    // std::cout << mySecondPokemon.level << " | " << mySecondPokemon.experience << std::endl;
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    // Battle(&mySecondPokemon, &myThirdPokemon);
    std::cout << "Zekrom Experience: " << myZekrom.species->experienceValue() << std::endl;
    std::cout << "zekky Nature" << std::endl;
    for (std::pair<std::string, double> i : myZekrom.nature->stats) {
        std::cout << "\t" << i.first << ": " << i.second << std::endl;
    }
    Battle(&myVenusaur, &myZekrom);
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    std::cout << "\n\nEnd Main";
    return 0;
}