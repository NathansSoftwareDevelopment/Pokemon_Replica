#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <map>
#include "Battle.h"
#include "Pokemon_Class.h"
#include "Type.h"
#include "Move.h"
#include "Utils.hpp"

Move* Battle::getMove(Pokemon* attackingInputPokemon, int InputMove) {
    return attackingInputPokemon->moves().at(InputMove);
}

double Battle::stabMultiplier(Pokemon* attackingInputPokemon, Move* InputPokemonMove) {
    if ((InputPokemonMove->type() == attackingInputPokemon->type1() || InputPokemonMove->type() == attackingInputPokemon->type2()) && InputPokemonMove->type()->name() != "None") {
        return 1.5;
    } else {
        return 1;
    }
}

double Battle::effectivenessMultiplier(Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    double type1Effectiveness = InputPokemonMove->type()->attackingTypeMap().find(defendingInputPokemon->type1()->name())->second;
    double type2Effectiveness = InputPokemonMove->type()->attackingTypeMap().find(defendingInputPokemon->type2()->name())->second;
    double totalEffectiveness = type1Effectiveness * type2Effectiveness;
    return totalEffectiveness;
}

void Battle::damageCalculation(Pokemon* attackingInputPokemon, Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    double stab = stabMultiplier(attackingInputPokemon, InputPokemonMove);
    double effectiveness = effectivenessMultiplier(InputPokemonMove, defendingInputPokemon);
    double randomDamageMultiplier = generateRandom(85, 100)/100.0;
    double attackingCategory;
    double defendingCategory;
    if (InputPokemonMove->damageCategory() == "Physical") {
        attackingCategory = attackingInputPokemon->currentStats().at("Attack");
        defendingCategory = attackingInputPokemon->currentStats().at("Defense");
    } else if (InputPokemonMove->damageCategory() == "Special") {
        attackingCategory = attackingInputPokemon->currentStats().at("SpecialAttack");
        defendingCategory = attackingInputPokemon->currentStats().at("SpecialDefense");
    } else {
        std::cout << "Check damage Category of Move: " << InputPokemonMove->name() << std::endl;
    }
    int rawDamage = ((2*attackingInputPokemon->level()/5+2)*InputPokemonMove->power()*attackingCategory/defendingCategory/50+2);
    int totalDamage = rawDamage * stab * effectiveness * randomDamageMultiplier;
    defendingInputPokemon->currentStat("HitPoints", std::max(defendingInputPokemon->currentStats().at("HitPoints") - totalDamage, 0));
    // std::cout << "Level: " << attackingInputPokemon->level() << std::endl;
    // std::cout << "Power: " << InputPokemonMove->power << std::endl;
    // std::cout << "attackingCategory: " << attackingCategory << std::endl;
    // std::cout << "defendingCategory: " << defendingCategory << std::endl;
    // std::cout << "Raw damage: " << rawDamage << std::endl;
    // std::cout << "stab: " << stab << std::endl;
    // std::cout << "effectiveness: " << effectiveness << std::endl;
    // std::cout << "Random: " << randomDamageMultiplier << std::endl;
    std::cout << attackingInputPokemon->name() << " dealt: " << totalDamage << " damage" << std::endl;
}

void Battle::getFasterPokemon(Pokemon* inputPokemon1, Trainer* inputTrainer1, Pokemon* inputPokemon2, Trainer* inputTrainer2) {
    if (inputPokemon1->currentStats().at("Speed") > inputPokemon2->currentStats().at("Speed")) {
        fasterPokemon = inputPokemon1;
        slowerPokemon = inputPokemon2;
    } else if (inputPokemon1->currentStats().at("Speed") < inputPokemon2->currentStats().at("Speed")) {
        fasterPokemon = inputPokemon2;
        slowerPokemon = inputPokemon1;
    } else {
        int randomPokemon = generateRandom(1, 2);
        if (randomPokemon == 1) {
            fasterPokemon = inputPokemon1;
            slowerPokemon = inputPokemon2;
        } else {
            fasterPokemon = inputPokemon2;
            slowerPokemon = inputPokemon1;
        }
    }

    if (fasterPokemon == inputPokemon1) {
        fasterPokemonOwner = inputTrainer1;
        slowerPokemonOwner = inputTrainer2;
    } else if (fasterPokemon == inputPokemon2) {
        fasterPokemonOwner = inputTrainer2;
        slowerPokemonOwner = inputTrainer1;
    }
}

void Battle::useMove(Pokemon* attackingInputPokemon, Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    std::cout << attackingInputPokemon->name() << " used " << InputPokemonMove->name() << std::endl;
    if (!hitCheck(attackingInputPokemon, InputPokemonMove, defendingInputPokemon)) {
        std::cout << attackingInputPokemon->name() << " Missed!" << std::endl;
        return;
    }
    if (InputPokemonMove->damageCategory() != "Status") {
        damageCalculation(attackingInputPokemon, InputPokemonMove, defendingInputPokemon);
    }
}

bool Battle::hitCheck(Pokemon* attackingInputPokemon, Move* InputPokemonMove, Pokemon* defendingInputPokemon) {
    int hitStage = std::clamp(attackingInputPokemon->currentStages().at("Accuracy") - defendingInputPokemon->currentStages().at("Evasion"), -6, 6);
    double stageMultiplier;
    if (hitStage >= 0) {
        stageMultiplier = (hitStage+3)/3.0;
    } else if (hitStage < 0) {
        stageMultiplier = 3.0/(std::abs(hitStage)+3);
    }
    int finalAccuracy = InputPokemonMove->accuracy() * stageMultiplier;
    int randomAccuracy = generateRandom(1, 100);
    if (randomAccuracy > finalAccuracy) {
        return false;
    } else {
        return true;
    }
}

bool Battle::flinchCheck(Move* inputPokemonMove) {
    int randomFlinch = generateRandom(1, 100);
    if (randomFlinch <= inputPokemonMove->flinchChance()) {
        return true;
    } else {
        return false;
    }
}

void Battle::distributeExperience(Pokemon* victoriousInputPokemon, Pokemon* defeatedInputPokemon) {
    // std::cout << "Defeated Pokemon: " << defeatedInputPokemon->name() << " | " << defeatedInputPokemon->species()->experienceValue() << std::endl;
    int experienceValue = defeatedInputPokemon->species()->experienceValue();
    int defeatedLevel = defeatedInputPokemon->level();
    double trainerBattle = 1.0; /* Trainers have not yet been implemented so this value is unchanging */
    double expShare = 1; /* EXP Share has not yet been implemented so this value is unchanging */
    double victoriousLevel = victoriousInputPokemon->level();
    double originalTrainer = 1; /* Trainers and trading have not yet been implemented so this value is unchanging */
    // std::cout << std::fixed << std::setprecision(15) << "Debug: originalTrainer (actual) = " << originalTrainer << std::endl;
    double luckyEgg = 1.0; /* Lucky Egg has not yet been implemented so this value is unchanging */
    double passPower = 1.0; /* Passes have not yet been implemented so this value is unchanging */
    double baseExperience = (
        roundHalfDown(
            (experienceValue * defeatedLevel / 5)
            *
            trainerBattle
            *
            (1.0 / expShare)
        )
    );
    // std::cout << "Debug: experienceValue * defeatedLevel / 5: " << experienceValue * defeatedLevel / 5 << std::endl;
    // std::cout << "Debug: (experienceValue * defeatedLevel / 5) * trainerBattle * (1.0 / expShare): " << (experienceValue * defeatedLevel / 5) * trainerBattle * (1.0 / expShare) << std::endl;
    // std::cout << "Debug: roundHalfDown((experienceValue * defeatedLevel / 5) * trainerBattle * (1.0 / expShare)): " << roundHalfDown((experienceValue * defeatedLevel / 5) * trainerBattle * (1.0 / expShare)) << std::endl;
    double scaleExperience = (
        std::floor(
            roundToMultipleOf4096(sqrt(2.0*defeatedLevel + 10)) * pow(
                (2.0*defeatedLevel + 10), 2
            )
        )
        /
        std::floor(
            roundToMultipleOf4096(sqrt(defeatedLevel + victoriousLevel + 10.0)) * pow(
                (defeatedLevel + victoriousLevel + 10.0), 2
            )
        )
    );
    // std::cout << "Debug: sqrt(2.0*defeatedLevel + 10): " << sqrt(2.0*defeatedLevel + 10) << std::endl;
    // std::cout << "Debug: roundToMultipleOf4096(sqrt(2.0*defeatedLevel + 10)): " << roundToMultipleOf4096(sqrt(2.0*defeatedLevel + 10)) << std::endl;
    // std::cout << "Debug: pow((2.0*defeatedLevel + 10), 2): " << pow((2.0*defeatedLevel + 10), 2) << std::endl;
    // std::cout << "Debug: Numerator: " << std::floor(roundToMultipleOf4096(sqrt(2.0*defeatedLevel + 10)) * pow((2.0*defeatedLevel + 10), 2)) << std::endl;
    // std::cout << "Debug: sqrt(defeatedLevel + victoriousLevel + 10.0): " << sqrt(defeatedLevel + victoriousLevel + 10.0) << std::endl;
    // std::cout << "Debug: roundToMultipleOf4096(sqrt(defeatedLevel + victoriousLevel + 10.0)): " << roundToMultipleOf4096(sqrt(defeatedLevel + victoriousLevel + 10.0)) << std::endl;
    // std::cout << "Debug: pow((defeatedLevel + victoriousLevel + 10.0), 2): " << pow((defeatedLevel + victoriousLevel + 10.0), 2) << std::endl;
    // std::cout << "Debug: Denominator: " << std::floor(roundToMultipleOf4096(sqrt(defeatedLevel + victoriousLevel + 10.0)) * pow((defeatedLevel + victoriousLevel + 10.0), 2)) << std::endl;
    // std::cout << "Debug: Scale Experience: " << scaleExperience << std::endl;
    double earnedExperience = (
        roundHalfDown(
            (
                (roundHalfDown(baseExperience * scaleExperience) + 1) * 
                originalTrainer * luckyEgg * passPower
            )
        )
    );
    // std::cout << "Debug: baseExperience * scaleExperience: " << baseExperience * scaleExperience << std::endl;
    // std::cout << "Debug: roundHalfDown(baseExperience * scaleExperience): " << roundHalfDown(baseExperience * scaleExperience) << std::endl;
    // std::cout << "Debug: roundHalfDown(baseExperience * scaleExperience) + 1: " << roundHalfDown(baseExperience * scaleExperience) + 1 << std::endl;
    // std::cout << "Debug: originalTrainer * luckyEgg * passPower: " << originalTrainer * luckyEgg * passPower << std::endl;
    // std::cout << "Debug: (roundHalfDown(baseExperience * scaleExperience) + 1) * originalTrainer * luckyEgg * passPower: " << (roundHalfDown(baseExperience * scaleExperience) + 1) * originalTrainer * luckyEgg * passPower << std::endl;
    // std::cout << "Debug: roundHalfDown((roundHalfDown(baseExperience * scaleExperience) + 1) * originalTrainer * luckyEgg * passPower): " << roundHalfDown((roundHalfDown(baseExperience * scaleExperience) + 1) * originalTrainer * luckyEgg * passPower) << std::endl;
    if (earnedExperience > 100000) {
        earnedExperience = 100000;
    }
    // std::cout << "Earned Experience: " << earnedExperience << std::endl;
    victoriousInputPokemon->addExperience(earnedExperience);
}

void Battle::addEVs(Pokemon* victoriousInputPokemon, Pokemon* defeatedInputPokemon) {
    for (std::pair<std::string, int> i : defeatedInputPokemon->species()->effortValues()) {
        int victorsTotalEVs = 0;
        for (std::pair<std::string, int> j : victoriousInputPokemon->effortValues()) {
            victorsTotalEVs += j.second;
        }
        int currentEV = victoriousInputPokemon->effortValues().at(i.first);
        if (victorsTotalEVs + i.second < 510) {
            victoriousInputPokemon->effortValue(i.first, currentEV+i.second);
        } else if (victorsTotalEVs < 510) {
            victoriousInputPokemon->effortValue(i.first, currentEV+510-victorsTotalEVs);
        }
    }
}

Pokemon* Battle::faintPokemon(Trainer* inputTrainer, Pokemon* inputFaintPokemon, std::map<int, Pokemon*>& inputTrainerPokemon) {
    std::cout << inputFaintPokemon->name() << " Fainted!" << std::endl;
    for (std::pair<int, Pokemon*> i : inputTrainerPokemon) {
        if (i.second == inputFaintPokemon) {
            inputTrainerPokemon.erase(i.first);
            break;
        }
    }

    std::cout << "Please choose a new pokemon, " << inputTrainer->name() << std::endl;
    for (std::pair<int, Pokemon*> i : inputTrainerPokemon) {
        std::cout << "\t" << i.first << ": " << i.second->name() << std::endl;
    }
    int inputPokemonSlot;
    std::cin >> inputPokemonSlot;
    return inputTrainerPokemon.at(inputPokemonSlot);
}

std::map<int, Pokemon*> Battle::makePartyMap(Trainer* inputTrainer) {
    std::map<int, Pokemon*> partyMap;
    for (std::pair<int, Pokemon*> i : inputTrainer->pokemon()) {
        if (i.second->currentStats().at("HitPoints") > 0) {
            partyMap.emplace(i.first, i.second);
        }
    }
    return partyMap;
}

Battle::Battle(Trainer* inputTrainer1, Trainer* inputTrainer2) {
    std::cout << "\n\n\n";
    turn = 0;

    std::map<int, Pokemon*> trainer1Pokemon = makePartyMap(inputTrainer1);
    Pokemon* trainer1ActivePokemon = trainer1Pokemon.begin()->second;
    std::map<int, Pokemon*> trainer2Pokemon = makePartyMap(inputTrainer2);
    Pokemon* trainer2ActivePokemon = trainer2Pokemon.begin()->second;

    while (trainer1Pokemon.size() > 0 && trainer2Pokemon.size() > 0) {
        turn++;

        getFasterPokemon(trainer1ActivePokemon, inputTrainer1, trainer2ActivePokemon, inputTrainer2);

        std::cout << "\n\nTurn " << turn << std::endl;
        std::cout << "first: " << fasterPokemon->name() << std::endl;
        int moveSlot;
        std::cout << "What Move slot to use? ";
        std::cin >> moveSlot;
        Move* fasterPokemonMove = getMove(fasterPokemon, moveSlot);
        std::cout << "second: " << slowerPokemon->name() << std::endl;
        std::cout << "What Move slot to use? ";
        std::cin >> moveSlot;
        std::cout << std::endl;
        Move* slowerPokemonMove = getMove(slowerPokemon, moveSlot);
        
        std::cout << fasterPokemon->name() << " " << fasterPokemonMove->name() << " " << slowerPokemon->name() << std::endl;
        useMove(fasterPokemon, fasterPokemonMove, slowerPokemon);
        std::cout << slowerPokemon->name() << " Is at " << slowerPokemon->currentStats().at("HitPoints") << " HP\n" << std::endl;

        if (slowerPokemon->currentStats().at("HitPoints") <= 0) {
            if (slowerPokemonOwner->name() == inputTrainer1->name()) {
                trainer1ActivePokemon = faintPokemon(inputTrainer1, slowerPokemon, trainer1Pokemon);
            } else if (slowerPokemonOwner->name() == inputTrainer2->name()) {
                trainer2ActivePokemon = faintPokemon(inputTrainer2, slowerPokemon, trainer2Pokemon);
            }
            addEVs(fasterPokemon, slowerPokemon);
            distributeExperience(fasterPokemon, slowerPokemon);
        } else if (flinchCheck(fasterPokemonMove)) {
            std::cout << slowerPokemon->name() << " Flinched!" << std::endl;
        } else {
            std::cout << slowerPokemon->name() << " " << slowerPokemonMove->name() << " " << fasterPokemon->name() << std::endl;
            useMove(slowerPokemon, slowerPokemonMove, fasterPokemon);
            std::cout << fasterPokemon->name() << " Is at " << fasterPokemon->currentStats().at("HitPoints") << " HP\n" << std::endl;
            
            if (fasterPokemon->currentStats().at("HitPoints") <= 0) {
                if (fasterPokemonOwner->name() == inputTrainer1->name()) {
                    trainer1ActivePokemon = faintPokemon(inputTrainer1, fasterPokemon, trainer1Pokemon);
                } else if (fasterPokemonOwner->name() == inputTrainer2->name()) {
                    trainer2ActivePokemon = faintPokemon(inputTrainer2, fasterPokemon, trainer2Pokemon);
                }
                addEVs(slowerPokemon, fasterPokemon);
                distributeExperience(slowerPokemon, fasterPokemon);
            }
        }
    }
    std::cout << "Battle Over" << std::endl;
}