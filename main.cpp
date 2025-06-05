#include <iostream>
#include "Pokemon_Class.h"
#include "Nature.h"
#include "Species.h"
#include "Display.h"
#include "Battle.h"
#include "Growth_Rate.h"
#include "Trainer.h"
#include "Player.h"
extern display Display;

int main() {
    std::cout << std::boolalpha;
    int randValues[6] = {1, 2, 3, 4, 5, 6};
    generateSpeciesMap();
    makeGrowthRates();
    generateMoveMap();
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap.find("Charmander")->second), "Modest", "Blaze", randValues);
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap.find("Charmander")->second), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", randValues, randValues);
    Pokemon myThirdPokemon = Pokemon("FireBoi3", &(speciesMap.find("Charmander")->second), "Modest", 5, 750000, "Blaze", "Growl", "Scratch", "Ember", "Smokescreen", "None", randValues, randValues);
    Display.moveAll(&moveMap.find("Growl")->second);
    Display.speciesAll(&(speciesMap.find("Charmander")->second));
    Display.speciesAll(&(speciesMap.find("Haxorus")->second));
    mySecondPokemon.addExperience(1000);
    myThirdPokemon.addExperience(1000);
    Pokemon myVenusaur = Pokemon("Venu", &(speciesMap.find("Venusaur")->second), "Modest", 55, 0, "Blaze", "Cheat", "Scratch", "Dark Pulse", "Smokescreen", "None", randValues, randValues);
    Pokemon myZekrom = Pokemon("zekky", &(speciesMap.find("Zekrom")->second), "Modest", 62, 0, "Blaze", "Growl", "Scratch", "Thunder Fang", "Cheat", "None", randValues, randValues);
    // std::cout << mySecondPokemon.level << " | " << mySecondPokemon.experience << std::endl;
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    // Battle(&mySecondPokemon, &myThirdPokemon);
    std::cout << "Zekrom Experience: " << myZekrom.species()->experienceValue() << std::endl;
    myPokemon.evolve();
    myZekrom.move(1, &moveMap.find("Fusion Bolt")->second);
    Display.pokemonAll(&myZekrom);
    Trainer myTrainer = Trainer("NotRed", {{1, &myPokemon}, {2, &mySecondPokemon}, {3, &myThirdPokemon}, {4, &myVenusaur}, {5, &myZekrom}});
    Display.all(&mySecondPokemon, "Zekrom", "Ember", "Steel", "Careful", "Fluctuating", &myTrainer);
    Player ME = Player("ME");
    std::cout << ME.name() << std::endl;
    std::cout << ME.ID() << std::endl;
    for (std::pair<std::string, std::vector<std::pair<std::string, int>>> i : ME.Bag()) {
        std::cout << i.first << std::endl;
    }
    Battle(&myVenusaur, &myZekrom);
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    std::cout << "\n\nEnd Main";
    return 0;
}