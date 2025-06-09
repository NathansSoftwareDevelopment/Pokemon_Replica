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

int main() {
    // Populate data sets
    generateSpeciesMap();
    makeGrowthRates();
    generateMoveMap();
    
    // Make default values to use later
    int randValues[6] = {1, 2, 3, 4, 5, 6};
    
    // Make instances of custom Classes
    Pokemon myPokemon = Pokemon("FireBoi", &(speciesMap.find("Charmander")->second), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Cheat", "None", randValues, randValues);
    Pokemon mySecondPokemon = Pokemon("FireBoi2", &(speciesMap.find("Charmander")->second), "Modest", 5, 0, "Blaze", "Growl", "Scratch", "Ember", "Cheat", "None", randValues, randValues);
    Pokemon myThirdPokemon = Pokemon("FireBoi3", &(speciesMap.find("Charmander")->second), "Modest", 5, 750000, "Blaze", "Growl", "Scratch", "Ember", "Cheat", "None", randValues, randValues);
    Pokemon myVenusaur = Pokemon("Venu", &(speciesMap.find("Venusaur")->second), "Modest", 55, 0, "Blaze", "Growl", "Scratch", "Dark Pulse", "Cheat", "None", randValues, randValues);
    Pokemon myZekrom = Pokemon("zekky", &(speciesMap.find("Zekrom")->second), "Modest", 62, 0, "Blaze", "Growl", "Scratch", "Thunder Fang", "Cheat", "None", randValues, randValues);
    Pokemon NotRedsCroagunk = Pokemon("Crocy", &(speciesMap.find("Croagunk")->second), "Adamant", 5, 0, "Poison Touch", "Poison Sting", "Mud-Slap", "Astonish", "Cheat", "None", randValues, randValues);
    Pokemon NotRedsOtherCroagunk = Pokemon("Rocky", &(speciesMap.find("Croagunk")->second), "Timid", 89, 0, "Poison Touch", "Poison Sting", "Mud-Slap", "Astonish", "Cheat", "None", randValues, randValues);
    Pokemon NotRedsEmboar = Pokemon("Emboss", &(speciesMap.find("Emboar")->second), "Hasty", 55, 0, "Blaze", "Flame Charge", "Head Smash", "Take Down", "Cheat", "None", randValues, randValues);
    Pokemon NotRedsReshiram = Pokemon("reshy", &(speciesMap.find("Reshiram")->second), "Modest", 62, 0, "Turboblaze", "Blue Flare", "Outrage", "Fusion Flare", "Cheat", "None", randValues, randValues);
    Trainer NotRed = Trainer("NotRed", {{1, &NotRedsCroagunk}, {2, &NotRedsOtherCroagunk}, {3, &NotRedsEmboar}, {4, &NotRedsReshiram}});
    Player ME = Player("ME");
    Machine myTM = Machine(&moveMap.find("Dragon Claw")->second, false, 2);
    
    // Use non-Getter/Setter Methods
    mySecondPokemon.addExperience(1000);
    myThirdPokemon.addExperience(1000);
    myPokemon.evolve();

    ME.pokemon(1, &myPokemon).pokemon(2, &mySecondPokemon).pokemon(3, &myThirdPokemon).pokemon(4, &myVenusaur).pokemon(5, &myZekrom);

    myTM.use(ItemUse().MoveSlot(1).Player(&ME).PokemonSlot(4));
    myTM.use(ItemUse().Player(&ME).PokemonSlot(5).MoveSlot(2));
    
    // Change Info / Use Setters
    myZekrom.move(1, &moveMap.find("Fusion Bolt")->second);
    
    // Displays
    std::cout << std::boolalpha;
    Display::all(&mySecondPokemon, "Zekrom", "Ember", "Steel", "Careful", "Fluctuating", &NotRed, &myTM);
    Display::trainerAll(&ME);
    std::cout << ME.livingParty().at(4)->name() << std::endl;
    std::cout << ME.activePokemon()->name() << std::endl;


    // Battle Information
    // std::cout << "Zekrom Experience: " << myZekrom.species()->experienceValue() << std::endl;
    // std::cout << mySecondPokemon.level << " | " << mySecondPokemon.experience << std::endl;
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    // Battle(&mySecondPokemon, &myThirdPokemon);
    Battle(&NotRed, &ME, true);
    // std::cout << myThirdPokemon.level << " | " << myThirdPokemon.experience << std::endl;
    std::cout << "\n\nEnd Main";
    return 0;
}