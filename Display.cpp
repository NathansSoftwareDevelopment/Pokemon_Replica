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
    pokemonName(inputPokemon, true);
    pokemonSpecies(inputPokemon, true);
    nature(inputPokemon, true);
    pokemonStats(inputPokemon, true);
    speciesStats(inputPokemon, true);
    pokemonType(inputPokemon, true);
    pokemonMovesAll(inputPokemon, true);
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
    cout << "Type: " << inputPokemon->moves[moveIndex]->type->typeName << endl;
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


void display::pokemonName(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Name\n";
    cout << inputPokemon->name << endl;
}
void display::pokemonSpecies(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nSpecies Name\n";
    cout << inputPokemon->species->name << endl;
}
void display::nature(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Nature\n";
    cout << inputPokemon->nature->name << endl;
    for (float* i : inputPokemon->nature->stats) {
        cout << *i << endl;
    }
}
void display::pokemonStats(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Stats\n";
    for (int* i : inputPokemon->maxStats) {
        cout << *i << endl;
    }
}
void display::speciesStats(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nSpecies Stats\n";
    for (std::pair i: inputPokemon->speciesStats) {
        cout << i.first << ": " << i.second << endl;
    }
}
void display::pokemonType(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Types\n";
    cout << inputPokemon->type1->typeName << endl;
    cout << inputPokemon->type2->typeName << endl;
}
void display::pokemonMoveNames(Pokemon* inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Moves";
    for (std::pair<int, Move*> i : inputPokemon->moves) {
        cout << i.second->name << endl;
    }
}