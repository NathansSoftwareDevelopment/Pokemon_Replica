#include <iostream>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Species.h"
#include "Display.h"
#include "Battle.h"
#include "Growth_Rate.h"
#include "Trainer.h"
#include "Player.h"
#include "Item.h"
#include "Machine.h"
extern display Display;

int main() {
    // Populate data sets
    generateSpeciesMap();
    makeGrowthRates();
    generateMoveMap();
    
    // Make default values to use later
    int randValues[6] = {1, 2, 3, 4, 5, 6};
    
    // Make instances of custom Classes
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap.find("Charmander")->second), "Modest", "Blaze", randValues);
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap.find("Charmander")->second), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", randValues, randValues);
    Pokemon myThirdPokemon = Pokemon("FireBoi3", &(speciesMap.find("Charmander")->second), "Modest", 5, 750000, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", randValues, randValues);
    Pokemon myVenusaur = Pokemon("Venu", &(speciesMap.find("Venusaur")->second), "Modest", 55, 0, "Blaze", "Cheat", "Scratch", "Dark Pulse", "Smokescreen", "None", randValues, randValues);
    Pokemon myZekrom = Pokemon("zekky", &(speciesMap.find("Zekrom")->second), "Modest", 62, 0, "Blaze", "Growl", "Scratch", "Thunder Fang", "Cheat", "None", randValues, randValues);
    Trainer myTrainer = Trainer("NotRed", {{1, &myPokemon}, {2, &mySecondPokemon}, {3, &myThirdPokemon}, {4, &myVenusaur}, {5, &myZekrom}});
    Player ME = Player("ME");
    Machine myTM = Machine(&moveMap.find("Dragon Claw")->second, false, 2);
    
    // Use non-Getter/Setter Methods
    mySecondPokemon.addExperience(1000);
    myThirdPokemon.addExperience(1000);
    myPokemon.evolve();
    
    // Change Info / Use Setters
    myZekrom.move(1, &moveMap.find("Fusion Bolt")->second);
    
    // Displays
    std::cout << std::boolalpha;
    Display.all(&mySecondPokemon, "Zekrom", "Ember", "Steel", "Careful", "Fluctuating", &myTrainer);
    std::cout << ME.name() << std::endl;
    std::cout << ME.ID() << std::endl;
    for (std::pair<std::string, std::vector<std::pair<std::string, int>>> i : ME.Bag()) {
        std::cout << i.first << std::endl;
    }
    std::cout << "Testing Machine/Item" << std::endl;
    std::cout << "\tName: " << myTM.name() << std::endl; 
    std::cout << "\tIs HM: " << myTM.isHM() << std::endl;
    std::cout << "\tID: " << myTM.ID() << std::endl;
    std::cout << "\tHoldable: " << myTM.holdable() << std::endl;
    std::cout << "\tPocket: " << myTM.pocket().second << " -> " << myTM.pocket().first << std::endl;


    // Battle Information
    // std::cout << "Zekrom Experience: " << myZekrom.species()->experienceValue() << std::endl;
    // std::cout << mySecondPokemon.level << " | " << mySecondPokemon.experience << std::endl;
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    // Battle(&mySecondPokemon, &myThirdPokemon);
    Battle(&myVenusaur, &myZekrom);
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    std::cout << "\n\nEnd Main";
    return 0;
}