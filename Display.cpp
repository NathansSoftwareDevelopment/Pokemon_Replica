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
    PokemonMoves(inputPokemon, true);
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
void display::PokemonMoves(Pokemon inputPokemon, bool stackCall) {
    idCounter(stackCall);
    std::cout << "\nPokemon Moves\n";
    for (Move** i : inputPokemon.pokemonMoves) {
        std::cout << (*i)->moveName << std::endl;
    }
}