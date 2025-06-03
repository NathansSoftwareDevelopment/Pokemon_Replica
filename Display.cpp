#include <iostream>
#include <string>
#include "Display.h"
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


void display::all(Pokemon* inputPokemon, std::string inputSpecies, std::string inputMove, bool stackCall) {
    idCounter(stackCall);
    pokemonAll(inputPokemon, true);
    speciesAll(&speciesMap.find(inputSpecies)->second, true);
    moveAll(&moveMap.find(inputMove)->second, true);
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
        cout << "\t" << i.first << ": " << i.second->name << endl;
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
    cout << "\nAll Information on Move " << inputMove->name << endl;
    cout << "Name: " << inputMove->name << endl;
    cout << "Type: " << inputMove->type->name() << endl;
    cout << "Damage Category: " << inputMove->damageCategory << endl;
    cout << "Power: " << inputMove->power << endl;
    cout << "Accuracy: " << inputMove->accuracy << endl;
    cout << "PP: " << inputMove->PP << endl;
    cout << "Flinch Chance: " << inputMove->flinchChance << endl;
    if (!inputMove->conditionChances.empty()) {
        for (std::pair i : inputMove->conditionChances) {
            cout << i.first << " Chance: " << i.second << endl;
        }
    }
    if (!inputMove->userStageChances.empty()) {
        cout << "Stat Changes to Self" << endl;
        for (std::pair i : inputMove->userStageChances) {
            cout << "\t" << i.second.front() << " " << i.first << ": " << i.second.back() << "% Chance " << endl;
        }
    }
    if (!inputMove->opponentStageChances.empty()) {
        cout << "Stat Changes to Opponent" << endl;
        for (std::pair i : inputMove->opponentStageChances) {
            cout << "\t" << i.second.front() << " " << i.first << ": " << i.second.back() << "% Chance" << endl;
        }
    }
    cout << "Uniqueness: " << inputMove->uniqueness << endl;
}