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

void display::All(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    PokemonName(inputPokemon, true);
    PokemonSpecies(inputPokemon, true);
    Nature(inputPokemon, true);
    PokemonStats(inputPokemon, true);
    SpeciesStats(inputPokemon, true);
    PokemonType(inputPokemon, true);
    PokemonMovesAll(inputPokemon, true);
}

void display::PokemonName(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Name\n";
    cout << inputPokemon.pokemonName << endl;
}
void display::PokemonSpecies(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nSpecies Name\n";
    cout << inputPokemon.pokemonSpecies->speciesName << endl;
}
void display::Nature(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Nature\n";
    cout << inputPokemon.pokemonNature->natureName << endl;
    for (float* i : inputPokemon.pokemonNature->natureStats) {
        cout << *i << endl;
    }
}
void display::PokemonStats(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Stats\n";
    for (int* i : inputPokemon.pokemonStats) {
        cout << *i << endl;
    }
}
void display::SpeciesStats(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nSpecies Stats\n";
    for (std::pair i: inputPokemon.speciesStats) {
        cout << i.first << ": " << i.second << endl;
    }
}
void display::PokemonType(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Types\n";
    cout << inputPokemon.pokemonType1->typeName << endl;
    cout << inputPokemon.pokemonType2->typeName << endl;
}


void display::PokemonMovesAll(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on All Moves";
    for (int i = 1; i < 5; i++) {
        PokemonMoveAll(inputPokemon, i, true);
    }
}
void display::PokemonMoveNames(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    cout << "\nPokemon Moves";
    for (Move** i : inputPokemon.pokemonMoves) {
        cout << (*i)->moveName << endl;
    }
}
void display::PokemonMoveAll(Pokemon inputPokemon, int moveIndex, bool stackCall) {
    idCounter(stackCall);
    cout << "\nAll Information on Move " << moveIndex << endl;
    moveIndex--;
    cout << "Name: " << (*inputPokemon.pokemonMoves[moveIndex])->moveName << endl;
    cout << "Type: " << (*inputPokemon.pokemonMoves[moveIndex])->moveType->typeName << endl;
    cout << "Damage Category: " << (*inputPokemon.pokemonMoves[moveIndex])->moveDamageCategory << endl;
    cout << "Power: " << (*inputPokemon.pokemonMoves[moveIndex])->movePower << endl;
    cout << "Accuracy: " << (*inputPokemon.pokemonMoves[moveIndex])->moveAccuracy << endl;
    cout << "PP: " << (*inputPokemon.pokemonMoves[moveIndex])->movePP << endl;
    cout << "Flinch Chance: " << (*inputPokemon.pokemonMoves[moveIndex])->moveFlinchChance << endl;
    if (!(*inputPokemon.pokemonMoves[moveIndex])->moveConditionChances.empty()) {
        for (std::pair i : (*inputPokemon.pokemonMoves[moveIndex])->moveConditionChances) {
            cout << i.first << " Chance: " << i.second << endl;
        }
    }
    if (!(*inputPokemon.pokemonMoves[moveIndex])->moveUserStageChances.empty()) {
        cout << "\nStat Changes to Self" << endl;
        for (std::pair i : (*inputPokemon.pokemonMoves[moveIndex])->moveUserStageChances) {
            cout << i.first << ": " << i.second.back() << "% Chance of " << i.second.front() << endl;
        }
    }
    if (!(*inputPokemon.pokemonMoves[moveIndex])->moveOpponentStageChances.empty()) {
        cout << "\nStat Changes to Opponent" << endl;
        for (std::pair i : (*inputPokemon.pokemonMoves[moveIndex])->moveOpponentStageChances) {
            cout << i.first << ": " << i.second.back() << "% Chance of " << i.second.front() << endl;
        }
    }
    cout << "\nUniqueness: " << (*inputPokemon.pokemonMoves[moveIndex])->moveUniqueness << endl;
}