#include <iostream>
#include <string>
#include "Display.h"
#include "Species.h"
#include "Move.h"
#include "Type.h"
#include "Nature.h"
#include "Growth_Rate.h"
#include "Trainer.h"
#include "Item.h"
using std::cout;
using std::endl;

display Display;

int display::displayID = 1;

void display::idCounter(bool stackCall) {
    if (!stackCall) {
        cout << "\nDisplay ID: " << displayID;
        displayID++;
    }
}


void display::all(Pokemon* inputPokemon, std::string inputSpecies, std::string inputMove, std::string inputType, std::string inputNature, std::string inputGrowthRate, Trainer* inputTrainer, Item* inputItem, bool stackCall) {
    idCounter(stackCall);
    pokemonAll(inputPokemon, true);
    speciesAll(&speciesMap.find(inputSpecies)->second, true);
    moveAll(&moveMap.find(inputMove)->second, true);
    typeAll(&typeMap.find(inputType)->second, true);
    natureAll(&natureMap.find(inputNature)->second, true);
    growthRateAll(&growthRateMap.find(inputGrowthRate)->second, true);
    trainerAll(inputTrainer, true);
    itemAll(inputItem, true);
}

void display::pokemonAll(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on " << inputPokemon->name() << endl;
    cout << "Name: " << inputPokemon->name() << endl;
    cout << "Species Name: " << inputPokemon->species()->name() << endl;
    cout << "Level: " << inputPokemon->level() << endl;
    cout << "Experience: " << inputPokemon->experience() << endl;
    cout << "Nature: " << inputPokemon->nature()->name() << endl;
    cout << "Ability: " << inputPokemon->ability() << endl;
    cout << "Types" << endl;
    cout << "\t" << inputPokemon->type1()->name() << endl;
    cout << "\t" << inputPokemon->type2()->name() << endl;
    cout << "Moves" << endl;
    for (std::pair<int, Move*> i : inputPokemon->moves()) {
        cout << "\t" << i.first << ": " << i.second->name() << endl;
    }
    cout << "IVs" << endl;
    for (std::pair<std::string, int> i : inputPokemon->individualValues()) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
    cout << "EVs" << endl;
    for (std::pair<std::string, int> i : inputPokemon->effortValues()) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
    cout << "Natural Stats" << endl;
    cout << "\tHitPoints: " << inputPokemon->maxStats().at("HitPoints") << endl;
    cout << "\tAttack: " << inputPokemon->maxStats().at("Attack") << endl;
    cout << "\tDefense: " << inputPokemon->maxStats().at("Defense") << endl;
    cout << "\tSpecial Attack: " << inputPokemon->maxStats().at("SpecialAttack") << endl;
    cout << "\tSpecial Defense: " << inputPokemon->maxStats().at("SpecialDefense") << endl;
    cout << "\tSpeed: " << inputPokemon->maxStats().at("Speed") << endl;
}


void display::speciesAll(Species* inputSpecies, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Species " << inputSpecies->name() << endl;
    cout << "Name: " << inputSpecies->name() << endl;
    cout << "Evolution: " << inputSpecies->evolution() << endl;
    cout << "Stats " << endl;
    for (std::pair<std::string, int> i : inputSpecies->stats()) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
    cout << "Types" << endl;
    cout << "\t" << inputSpecies->type1()->name() << endl;
    cout << "\t" << inputSpecies->type2()->name() << endl;
    cout << "Abilities" << endl;
    for (int i = 1; i < 4; i++) {
        cout << "\t" << i << ": " << inputSpecies->abilities().at(i) << endl;
    }
}

void display::moveAll(Move* inputMove, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Move " << inputMove->name() << endl;
    cout << "Name: " << inputMove->name() << endl;
    cout << "Type: " << inputMove->type()->name() << endl;
    cout << "Damage Category: " << inputMove->damageCategory() << endl;
    cout << "Power: " << inputMove->power() << endl;
    cout << "Accuracy: " << inputMove->accuracy() << endl;
    cout << "PP: " << inputMove->PP() << endl;
    cout << "Flinch Chance: " << inputMove->flinchChance() << endl;
    if (!inputMove->conditionChances().empty()) {
        for (std::pair i : inputMove->conditionChances()) {
            cout << i.first << " Chance: " << i.second << endl;
        }
    }
    if (!inputMove->userStageChances().empty()) {
        cout << "Stat Changes to Self" << endl;
        for (std::pair i : inputMove->userStageChances()) {
            cout << "\t" << i.second.front() << " " << i.first << ": " << i.second.back() << "% Chance " << endl;
        }
    }
    if (!inputMove->opponentStageChances().empty()) {
        cout << "Stat Changes to Opponent" << endl;
        for (std::pair i : inputMove->opponentStageChances()) {
            cout << "\t" << i.second.front() << " " << i.first << ": " << i.second.back() << "% Chance" << endl;
        }
    }
    cout << "Uniqueness: " << inputMove->uniqueness() << endl;
}

void display::typeAll(Type* inputType, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Type " << inputType->name() << endl;
    cout << "Name: " << inputType->name() << endl;
    cout << "Attacking Type Effectiveness" << endl;
    for (std::pair<std::string, double> i : inputType->attackingTypeMap()) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
    cout << "Defending Type Effectiveness" << endl;
    for (std::pair<std::string, Type> i : typeMap) {
        cout << "\t" << i.first << ": " << i.second.attackingTypeMap().at(inputType->name()) << endl;
    }
}

void display::natureAll(Nature* inputNature, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Nature " << inputNature->name() << endl;
    cout << "Name: " << inputNature->name() << endl;
    cout << "Stat Multipliers" << endl;
    for (std::pair<std::string, double> i : inputNature->stats()) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
}

void display::growthRateAll(GrowthRate* inputGrowthRate, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Growth Rate " << inputGrowthRate->name() << endl;
    cout << "Name: " << inputGrowthRate->name() << endl;
    cout << "Total Experience to Level" << endl;
    for (std::pair<int, int> i : inputGrowthRate->toLevel()) {
        printf("\t%3d: %d\n", i.first, i.second);
    }
    cout << "Total Experience to Next Level" << endl;
    for (std::pair<int, int> i : inputGrowthRate->toNextLevel()) {
        printf("\t%2d -> %3d: %d\n", i.first, i.first+1, i.second);
    }
}

void display::trainerAll(Trainer* inputTrainer, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Trainer " << inputTrainer->name() << endl;
    cout << "Name: " << inputTrainer->name() << endl;
    cout << "ID: " << inputTrainer->ID() << endl;
    cout << "Pokemon" << endl;
    for (std::pair<int, Pokemon*> i : inputTrainer->pokemon()) {
        cout << "\tSlot " << i.first << endl;
        cout << "\t\tName: " << i.second->name() << endl;
        cout << "\t\tSpecies: " << i.second->species()->name() << endl;
        cout << "\t\tLevel: " << i.second->level() << endl;
        cout << "\t\tNatural Stats" << endl;
        cout << "\t\t\tHitPoints: " << i.second->maxStats().at("HitPoints") << endl;
        cout << "\t\t\tAttack: " << i.second->maxStats().at("Attack") << endl;
        cout << "\t\t\tDefense: " << i.second->maxStats().at("Defense") << endl;
        cout << "\t\t\tSpecial Attack: " << i.second->maxStats().at("SpecialAttack") << endl;
        cout << "\t\t\tSpecial Defense: " << i.second->maxStats().at("SpecialDefense") << endl;
        cout << "\t\t\tSpeed: " << i.second->maxStats().at("Speed") << endl;
    }
    cout << "Living Pokemon" << endl;
    trainerLivingParty(inputTrainer, true);
}

void display::trainerLivingParty(Trainer* inputTrainer, bool stackCall) {
    idCounter(stackCall);
    for (std::pair<int, Pokemon*> i : inputTrainer->livingParty()) {
        printf("\t%i: %s %i/%i\n", i.first, i.second->name().c_str(), i.second->currentStats().at("HitPoints"), i.second->maxStats().at("HitPoints"));
    }
}

void display::itemAll(Item* inputItem, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Item " << inputItem->name() << endl;
    cout << "Name: " << inputItem->name() << endl;
    cout << "Holdable: " << inputItem->holdable() << endl;
    cout << "Pocket: " << inputItem->pocket().first << endl;
}