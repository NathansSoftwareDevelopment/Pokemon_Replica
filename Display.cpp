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


void display::all(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    pokemonAll(inputPokemon, true);
}

void display::pokemonAll(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on " << inputPokemon->name << endl;
    cout << "Name: " << inputPokemon->name << endl;
    cout << "Species Name: " << inputPokemon->species->name << endl;
    cout << "Level: " << inputPokemon->level << endl;
    cout << "Experience: " << inputPokemon->experience << endl;
    cout << "Nature: " << inputPokemon->nature->name << endl;
    cout << "Ability: " << inputPokemon->ability << endl;
    cout << "Types" << endl;
    cout << "\t" << inputPokemon->type1->name << endl;
    cout << "\t" << inputPokemon->type2->name << endl;
    cout << "Moves" << endl;
    for (std::pair<int, Move*> i : inputPokemon->moves) {
        cout << "\t" << i.first << ": " << i.second->name << endl;
    }
    cout << "IVs" << endl;
    for (std::pair<std::string, int> i : inputPokemon->individualValues) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
    cout << "EVs" << endl;
    for (std::pair<std::string, int> i : inputPokemon->effortValues) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
    cout << "Natural Stats" << endl;
    cout << "\tHitPoints: " << inputPokemon->maxHitPoints << endl;
    cout << "\tAttack: " << inputPokemon->maxAttack << endl;
    cout << "\tDefense: " << inputPokemon->maxDefense << endl;
    cout << "\tSpecial Attack: " << inputPokemon->maxSpecialAttack << endl;
    cout << "\tSpecial Defense: " << inputPokemon->maxSpecialDefense << endl;
    cout << "\tSpeed: " << inputPokemon->maxSpeed << endl;
}

void display::pokemonMovesAll(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on All Moves";
    for (int i = 1; i < 5; i++) {
        pokemonMoveAll(inputPokemon, i, true);
    }
}
void display::pokemonMoveAll(Pokemon* inputPokemon, int moveIndex, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Move " << moveIndex << endl;
    cout << "Name: " << inputPokemon->moves[moveIndex]->name << endl;
    cout << "Type: " << inputPokemon->moves[moveIndex]->type->name << endl;
    cout << "Damage Category: " << inputPokemon->moves[moveIndex]->damageCategory << endl;
    cout << "Power: " << inputPokemon->moves[moveIndex]->power << endl;
    cout << "Accuracy: " << inputPokemon->moves[moveIndex]->accuracy << endl;
    cout << "PP: " << inputPokemon->moves[moveIndex]->PP << endl;
    cout << "Flinch Chance: " << inputPokemon->moves[moveIndex]->flinchChance << endl;
    if (!inputPokemon->moves[moveIndex]->conditionChances.empty()) {
        for (std::pair i : inputPokemon->moves[moveIndex]->conditionChances) {
            cout << i.first << " Chance: " << i.second << endl;
        }
    }
    if (!inputPokemon->moves[moveIndex]->userStageChances.empty()) {
        cout << "\nStat Changes to Self" << endl;
        for (std::pair i : inputPokemon->moves[moveIndex]->userStageChances) {
            cout << i.first << ": " << i.second.back() << "% Chance of " << i.second.front() << endl;
        }
    }
    if (!inputPokemon->moves[moveIndex]->opponentStageChances.empty()) {
        cout << "\nStat Changes to Opponent" << endl;
        for (std::pair i : inputPokemon->moves[moveIndex]->opponentStageChances) {
            cout << i.first << ": " << i.second.back() << "% Chance of " << i.second.front() << endl;
        }
    }
    cout << "\nUniqueness: " << inputPokemon->moves[moveIndex]->uniqueness << endl;
}

void display::speciesAll(Species* inputSpecies, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Species " << inputSpecies->name << endl;
    cout << "Name: " << inputSpecies->name << endl;
    cout << "Evolution: " << inputSpecies->evolution << endl;
    cout << "Stats " << endl;
    for (std::pair<std::string, int> i : inputSpecies->stats) {
        cout << "\t" << i.first << ": " << i.second << endl;
    }
    cout << "Types" << endl;
    cout << "\t" << inputSpecies->type1 << endl;
    cout << "\t" << inputSpecies->type2 << endl;
    cout << "Abilities" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\t" << i+1 << ": " << inputSpecies->abilities[i] << endl;
    }
}