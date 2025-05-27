#include <iostream>
#include <random>
#include <algorithm>
#include "Battle.h"
#include "Pokemon_Class.h"
#include "Type.h"
#include "Move.h"

std::random_device rd;
std::mt19937 gen(rd());

Move* Battle::getMove(Pokemon* attackingInputPokemon, int InputMove) {
    return attackingInputPokemon->moves[InputMove];
}

double Battle::stabMultiplier(Pokemon* attackingInputPokemon, Move* InputPokemonMove) {
    if ((InputPokemonMove->type == attackingInputPokemon->type1 || InputPokemonMove->type == attackingInputPokemon->type2) && InputPokemonMove->type->name != "None") {
        return 1.5;
    } else {
        return 1;
    }
}

double Battle::effectivenessMultiplier(Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    double type1Effectiveness = InputPokemonMove->type->attackingTypeMap.find(defendingInputPokemon->type1->name)->second;
    double type2Effectiveness = InputPokemonMove->type->attackingTypeMap.find(defendingInputPokemon->type2->name)->second;
    double totalEffectiveness = type1Effectiveness * type2Effectiveness;
    return totalEffectiveness;
}

void Battle::damageCalculation(Pokemon* attackingInputPokemon, Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    double stab = stabMultiplier(attackingInputPokemon, InputPokemonMove);
    double effectiveness = effectivenessMultiplier(InputPokemonMove, defendingInputPokemon);
    double randomDamageMultiplier = std::uniform_int_distribution<int> (85, 100)(gen)/100.0;
    double attackingCategory;
    double defendingCategory;
    if (InputPokemonMove->damageCategory == "Physical") {
        attackingCategory = attackingInputPokemon->currentAttack;
        defendingCategory = attackingInputPokemon->currentDefense;
    } else if (InputPokemonMove->damageCategory == "Special") {
        attackingCategory = attackingInputPokemon->currentSpecialAttack;
        defendingCategory = attackingInputPokemon->currentSpecialDefense;
    } else {
        std::cout << "Check damage Category of Move: " << InputPokemonMove->name << std::endl;
    }
    int rawDamage = ((2*attackingInputPokemon->level/5+2)*InputPokemonMove->power*attackingCategory/defendingCategory/50+2);
    int totalDamage = rawDamage * stab * effectiveness * randomDamageMultiplier;
    defendingInputPokemon->currentHitPoints = std::max(defendingInputPokemon->currentHitPoints - totalDamage, 0);
    // std::cout << "Level: " << attackingInputPokemon->level << std::endl;
    // std::cout << "Power: " << InputPokemonMove->power << std::endl;
    // std::cout << "attackingCategory: " << attackingCategory << std::endl;
    // std::cout << "defendingCategory: " << defendingCategory << std::endl;
    // std::cout << "Raw damage: " << rawDamage << std::endl;
    // std::cout << "stab: " << stab << std::endl;
    // std::cout << "effectiveness: " << effectiveness << std::endl;
    // std::cout << "Random: " << randomDamageMultiplier << std::endl;
    std::cout << attackingInputPokemon->name << " dealt: " << totalDamage << " damage" << std::endl;
}

void Battle::getFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2) {
    if (inputPokemon1->currentSpeed > inputPokemon2->currentSpeed) {
        fasterPokemon = inputPokemon1;
        slowerPokemon = inputPokemon2;
    } else if (inputPokemon1->currentSpeed < inputPokemon2->currentSpeed) {
        fasterPokemon = inputPokemon2;
        slowerPokemon = inputPokemon1;
    } else {
        int randomPokemon = std::uniform_int_distribution<int> (1, 2)(gen);
        if (randomPokemon == 1) {
            fasterPokemon = inputPokemon1;
            slowerPokemon = inputPokemon2;
        } else {
            fasterPokemon = inputPokemon2;
            slowerPokemon = inputPokemon1;
        }
    }
}

void Battle::useMove(Pokemon* attackingInputPokemon, Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    std::cout << attackingInputPokemon->name << " used " << InputPokemonMove->name << std::endl;
    if (!hitCheck(attackingInputPokemon, InputPokemonMove, defendingInputPokemon)) {
        std::cout << attackingInputPokemon->name << " Missed!" << std::endl;
        return;
    }
    if (InputPokemonMove->damageCategory != "Status") {
        damageCalculation(attackingInputPokemon, InputPokemonMove, defendingInputPokemon);
    }
}

bool Battle::hitCheck(Pokemon* attackingInputPokemon, Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    int hitStage = std::clamp(attackingInputPokemon->currentAccuracyStage - defendingInputPokemon->currentEvasionStage, -6, 6);
    double stageMultiplier;
    if (hitStage >= 0) {
        stageMultiplier = (hitStage+3)/3.0;
    } else if (hitStage < 0) {
        stageMultiplier = 3.0/(std::abs(hitStage)+3);
    }
    int finalAccuracy = InputPokemonMove->accuracy * stageMultiplier;
    int randomAccuracy = std::uniform_int_distribution<int> (1, 100)(gen);
    if (randomAccuracy > finalAccuracy) {
        return false;
    } else {
        return true;
    }
}

Battle::Battle(Pokemon* inputPokemon1, Pokemon* inputPokemon2) {
    std::cout << "\n\n\n";
    turn = 0;
    while (inputPokemon1->currentHitPoints > 0 && inputPokemon2->currentHitPoints > 0) {
        turn++;
        getFasterPokemon(inputPokemon1, inputPokemon2);
        std::cout << "\n\nTurn " << turn << std::endl;
        std::cout << "first: " << fasterPokemon->name << std::endl;
        int moveSlot;
        std::cout << "What Move slot to use? ";
        std::cin >> moveSlot;
        Move* fasterPokemonMove = getMove(fasterPokemon, moveSlot);
        std::cout << "second: " << slowerPokemon->name << std::endl;
        std::cout << "What Move slot to use? ";
        std::cin >> moveSlot;
        std::cout << std::endl;
        Move* slowerPokemonMove = getMove(slowerPokemon, moveSlot);
        useMove(fasterPokemon, fasterPokemonMove, slowerPokemon);
        std::cout << slowerPokemon->currentHitPoints << std::endl;
        if (slowerPokemon->currentHitPoints > 0) {
            useMove(slowerPokemon, slowerPokemonMove, fasterPokemon);
        }
        std::cout << fasterPokemon->currentHitPoints << std::endl;
    }
    std::cout << "Battle Over" << std::endl;
    std::cout << inputPokemon1->currentHitPoints << std::endl;
    std::cout << inputPokemon2->currentHitPoints << std::endl;
}