#include <iostream>
#include <string>
#include "Machine.h"
#include "Pokemon_Class.h"
#include "Player.h"
#include "Move.h"

void Machine::use(ItemUse inputParameters) {
    // Verify Parameters
    if (inputParameters.player == NULL || inputParameters.pokemonSlot == -1 || inputParameters.moveSlot == -1) {
        std::cout << "MACHINE USE ERROR" << std::endl;
        return;
    }

    // Simplify variable names
    Player* targetPlayer = inputParameters.player;
    Pokemon* targetPokemon = inputParameters.player->pokemon().at(inputParameters.pokemonSlot);
    int moveSlot = inputParameters.moveSlot;

    // Attempt to use item
    if (targetPokemon->species()->moves().machine.count(_move->name()) != 0) {
        targetPokemon->move(moveSlot, _move);
        std::cout << "Successfully taught " << targetPokemon->name() << " " << _move->name() << " In slot " << moveSlot << std::endl;
    } else {
        std::cout << targetPokemon->species()->name() << " Can't learn that move!" << std::endl;
    }
}

Machine::Machine(Move* inputMove, bool inputIsHM, int inputID) : Item(inputMove->name(), false, "TMs & HMs") {
    _move = inputMove;
    _isHM = inputIsHM;
    _ID = inputID;
}