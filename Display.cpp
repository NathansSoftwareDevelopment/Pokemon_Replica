#include <iostream>
#include <string>
#include "Display.h"


display Display;

int display::displayID = 1;

void display::idCounter(bool stackCall) {
    if (!stackCall) {
        std::cout << "\nDisplay ID: " << displayID;
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
    std::cout << "\nPokemon Name\n";
    std::cout << inputPokemon.pokemonName << std::endl;
}
void display::PokemonSpecies(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nSpecies Name\n";
    std::cout << inputPokemon.pokemonSpecies->speciesName << std::endl;
}
void display::Nature(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nPokemon Nature\n";
    std::cout << inputPokemon.pokemonNature->natureName << std::endl;
    for (float* i : inputPokemon.pokemonNature->natureStats) {
        std::cout << *i << std::endl;
    }
}
void display::PokemonStats(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nPokemon Stats\n";
    for (int* i : inputPokemon.pokemonStats) {
        std::cout << *i << std::endl;
    }
}
void display::SpeciesStats(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nSpecies Stats\n";
    for (int* i: inputPokemon.speciesStats) {
        std::cout << *i << std::endl;
    }
}
void display::PokemonType(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nPokemon Types\n";
    std::cout << inputPokemon.pokemonType1->typeName << std::endl;
    std::cout << inputPokemon.pokemonType2->typeName << std::endl;
}


void display::PokemonMovesAll(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nAll Information on All Moves";
    for (int i = 1; i < 5; i++) {
        PokemonMoveAll(inputPokemon, i, true);
    }
}
void display::PokemonMoveNames(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nPokemon Moves";
    for (Move** i : inputPokemon.pokemonMoves) {
        std::cout << (*i)->moveName << std::endl;
    }
}
void display::PokemonMoveAll(Pokemon inputPokemon, int moveIndex, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nAll Information on Move " << moveIndex << std::endl;
    moveIndex--;
    std::cout << "Name: " << (*inputPokemon.pokemonMoves[moveIndex])->moveName << std::endl;
    std::cout << "Type: " << (*inputPokemon.pokemonMoves[moveIndex])->moveType->typeName << std::endl;
    std::cout << "Damage Category: " << (*inputPokemon.pokemonMoves[moveIndex])->moveDamageCategory << std::endl;
    std::cout << "Power: " << (*inputPokemon.pokemonMoves[moveIndex])->movePower << std::endl;
    std::cout << "Accuracy: " << (*inputPokemon.pokemonMoves[moveIndex])->moveAccuracy << std::endl;
    std::cout << "PP: " << (*inputPokemon.pokemonMoves[moveIndex])->movePP << std::endl;
    for (std::pair i : (*inputPokemon.pokemonMoves[moveIndex])->moveConditionChances) {
        std::cout << i.first << ": " << i.second << std::endl;
    }
    std::cout << "Flinch Chance: " << (*inputPokemon.pokemonMoves[moveIndex])->moveFlinchChance << std::endl;
    std::cout << "Uniqueness: " << (*inputPokemon.pokemonMoves[moveIndex])->moveUniqueness << std::endl;
}