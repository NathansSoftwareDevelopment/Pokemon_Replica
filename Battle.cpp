#include <iostream>
#include <random>
#include <algorithm>
#include "Battle.h"
#include "Pokemon_Class.h"
#include "Type.h"
#include "Move.h"

std::random_device rd;
std::mt19937 gen(rd());

Move* Battle::battleGetMove(Pokemon* attackingInputPokemon, int battleInputMove) {
    return *(attackingInputPokemon->pokemonMoves[battleInputMove-1]);
}

double Battle::battleStabMultiplier(Pokemon* attackingInputPokemon, Move* battleInputPokemonMove) {
    if ((battleInputPokemonMove->moveType == attackingInputPokemon->pokemonType1 || battleInputPokemonMove->moveType == attackingInputPokemon->pokemonType2) && battleInputPokemonMove->moveType->typeName != "None") {
        return 1.5;
    } else {
        return 1;
    }
}

double Battle::battleEffectivenessMultiplier(Move* battleInputPokemonMove, Pokemon* defendingInputPokemon) {
    double type1Effectiveness = battleInputPokemonMove->moveType->attackingTypeMap.find(defendingInputPokemon->pokemonType1->typeName)->second;
    double type2Effectiveness = battleInputPokemonMove->moveType->attackingTypeMap.find(defendingInputPokemon->pokemonType2->typeName)->second;
    double totalEffectiveness = type1Effectiveness * type2Effectiveness;
    return totalEffectiveness;
}

void Battle::battleDamageCalculation(Pokemon* attackingInputPokemon, Move* battleInputPokemonMove, Pokemon* defendingInputPokemon) {
    int randomAccuracy = std::uniform_int_distribution<int> (1, 100)(gen);
    if (randomAccuracy > battleInputPokemonMove->moveAccuracy) {
        return;
    }
    double stab = battleStabMultiplier(attackingInputPokemon, battleInputPokemonMove);
    double effectiveness = battleEffectivenessMultiplier(battleInputPokemonMove, defendingInputPokemon);
    double randomDamageMultiplier = std::uniform_int_distribution<int> (85, 100)(gen)/100.0;
    double attackingCategory;
    double defendingCategory;
    if (battleInputPokemonMove->moveDamageCategory == "Physical") {
        attackingCategory = attackingInputPokemon->currentAttack;
        defendingCategory = attackingInputPokemon->currentDefense;
    } else if (battleInputPokemonMove->moveDamageCategory == "Special") {
        attackingCategory = attackingInputPokemon->currentSpecialAttack;
        defendingCategory = attackingInputPokemon->currentSpecialDefense;
    } else {
        std::cout << "Check Damage Category of Move: " << battleInputPokemonMove->moveName << std::endl;
    }
    int rawDamage = ((2*attackingInputPokemon->pokemonLevel/5+2)*battleInputPokemonMove->movePower*attackingCategory/defendingCategory/50+2);
    int totalDamage = rawDamage * stab * effectiveness * randomDamageMultiplier;
    defendingInputPokemon->currentHitPoints = std::max(defendingInputPokemon->currentHitPoints - totalDamage, 0);
    // std::cout << "Raw Damage: " << rawDamage << std::endl;
    // std::cout << "Stab: " << stab << std::endl;
    // std::cout << "Effectiveness: " << effectiveness << std::endl;
    // std::cout << "Random: " << randomDamageMultiplier << std::endl;
    std::cout << attackingInputPokemon->pokemonName << " Dealt: " << totalDamage << " Damage" << std::endl;
}

void Battle::battleGetFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2) {
    if (inputPokemon1->currentSpeed > inputPokemon2->currentSpeed) {
        battleFasterPokemon = inputPokemon1;
        battleSlowerPokemon = inputPokemon2;
    } else if (inputPokemon1->currentSpeed < inputPokemon2->currentSpeed) {
        battleFasterPokemon = inputPokemon2;
        battleSlowerPokemon = inputPokemon1;
    } else {
        int randomPokemon = std::uniform_int_distribution<int> (1, 2)(gen);
        if (randomPokemon == 1) {
            battleFasterPokemon = inputPokemon1;
            battleSlowerPokemon = inputPokemon2;
        } else {
            battleFasterPokemon = inputPokemon2;
            battleSlowerPokemon = inputPokemon1;
        }
    }
}

void Battle::battleUseMove(Pokemon* attackingInputPokemon, Move* battleInputPokemonMove, Pokemon* defendingInputPokemon) {
    std::cout << attackingInputPokemon->pokemonName << " Used " << battleInputPokemonMove->moveName << std::endl;
    if (battleInputPokemonMove->moveDamageCategory != "Status") {
        battleDamageCalculation(attackingInputPokemon, battleInputPokemonMove, defendingInputPokemon);
    }
}

Battle::Battle(Pokemon* inputPokemon1, Pokemon* inputPokemon2) {
    std::cout << "\n\n\n";
    battleTurn = 0;
    while (inputPokemon1->currentHitPoints > 0 && inputPokemon2->currentHitPoints > 0) {
        battleTurn++;
        battleGetFasterPokemon(inputPokemon1, inputPokemon2);
        std::cout << "Turn " << battleTurn << std::endl;
        std::cout << "First: " << battleFasterPokemon->pokemonName << std::endl;
        int moveSlot;
        std::cout << "What Move Slot to Use? ";
        std::cin >> moveSlot;
        std::cout << std::endl;
        Move* battleFasterPokemonMove = battleGetMove(battleFasterPokemon, moveSlot);
        std::cout << "Second: " << battleSlowerPokemon->pokemonName << std::endl;
        std::cout << "What Move Slot to Use? ";
        std::cin >> moveSlot;
        std::cout << std::endl;
        Move* battleSlowerPokemonMove = battleGetMove(battleSlowerPokemon, moveSlot);
        battleUseMove(battleFasterPokemon, battleFasterPokemonMove, battleSlowerPokemon);
        std::cout << battleSlowerPokemon->currentHitPoints << std::endl;
        if (battleSlowerPokemon->currentHitPoints > 0) {
            battleUseMove(battleSlowerPokemon, battleSlowerPokemonMove, battleFasterPokemon);
        }
        std::cout << battleFasterPokemon->currentHitPoints << std::endl;
    }
    std::cout << "Battle Over" << std::endl;
    std::cout << inputPokemon1->currentHitPoints << std::endl;
    std::cout << inputPokemon2->currentHitPoints << std::endl;
}