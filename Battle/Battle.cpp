#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include "Battle.h"
#include "Pokemon_Class.h"
#include "Type.h"
#include "Move.h"
#include "Utils.hpp"

Move* Battle::getMove(Pokemon* inputAttackingPokemon) {
    std::string userInput;
    if (_autoBattle) {
        userInput = std::to_string(generateRandom(1, inputAttackingPokemon->moves().size()));
    } else {
        std::cout << "What Move slot to use? ";
        std::cin >> userInput;
    }
    std::cout << "\n";
    
    Move* returnMove;
    // If input is invalid -> Print an error message and get a new input;
    try {
        int moveSlot = std::stoi(userInput);
        returnMove = inputAttackingPokemon->moves().at(moveSlot);
    } catch (std::exception) {
        std::cout << "Error: \"" << userInput << "\" is an invalid move slot." << std::endl;
        returnMove = getMove(inputAttackingPokemon);
    }

    return returnMove;
}

double Battle::stabMultiplier(Pokemon* inputAttackingPokemon, Move* inputPokemonMove) {
    if ((inputPokemonMove->type() == inputAttackingPokemon->type1() || inputPokemonMove->type() == inputAttackingPokemon->type2()) && inputPokemonMove->type()->name() != "None") {
        return 1.5;
    } else {
        return 1;
    }
}

double Battle::effectivenessMultiplier(Move* inputPokemonMove, Pokemon* inputDefendingPokemon) {
    double type1Effectiveness = inputPokemonMove->type()->attackingTypeMap().find(inputDefendingPokemon->type1()->name())->second;
    double type2Effectiveness = inputPokemonMove->type()->attackingTypeMap().find(inputDefendingPokemon->type2()->name())->second;
    double totalEffectiveness = type1Effectiveness * type2Effectiveness;
    return totalEffectiveness;
}

void Battle::damageCalculation(Pokemon* inputAttackingPokemon, Move* inputPokemonMove, Pokemon* inputDefendingPokemon) {
    double stab = stabMultiplier(inputAttackingPokemon, inputPokemonMove);
    double effectiveness = effectivenessMultiplier(inputPokemonMove, inputDefendingPokemon);
    double randomDamageMultiplier = generateRandom(85, 100)/100.0;
    double attackingCategory;
    double defendingCategory;
    if (inputPokemonMove->damageCategory() == "Physical") {
        attackingCategory = inputAttackingPokemon->currentStats().at("Attack");
        defendingCategory = inputAttackingPokemon->currentStats().at("Defense");
    } else if (inputPokemonMove->damageCategory() == "Special") {
        attackingCategory = inputAttackingPokemon->currentStats().at("SpecialAttack");
        defendingCategory = inputAttackingPokemon->currentStats().at("SpecialDefense");
    } else {
        std::cout << "Check damage Category of Move: " << inputPokemonMove->name() << std::endl;
    }
    int rawDamage = ((2*inputAttackingPokemon->level()/5+2)*inputPokemonMove->power()*attackingCategory/defendingCategory/50+2);
    int totalDamage = rawDamage * stab * effectiveness * randomDamageMultiplier;
    inputDefendingPokemon->currentStat("HitPoints", std::max(inputDefendingPokemon->currentStats().at("HitPoints") - totalDamage, 0));
    // std::cout << "Level: " << inputAttackingPokemon->level() << std::endl;
    // std::cout << "Power: " << inputPokemonMove->power << std::endl;
    // std::cout << "attackingCategory: " << attackingCategory << std::endl;
    // std::cout << "defendingCategory: " << defendingCategory << std::endl;
    // std::cout << "Raw damage: " << rawDamage << std::endl;
    // std::cout << "stab: " << stab << std::endl;
    // std::cout << "effectiveness: " << effectiveness << std::endl;
    // std::cout << "Random: " << randomDamageMultiplier << std::endl;
    std::cout << inputAttackingPokemon->name() << " dealt: " << totalDamage << " damage" << std::endl;
}

void Battle::getFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2) {
    if (inputPokemon1->currentStats().at("Speed") > inputPokemon2->currentStats().at("Speed")) {
        _fasterPokemon = inputPokemon1;
        _slowerPokemon = inputPokemon2;
    } else if (inputPokemon1->currentStats().at("Speed") < inputPokemon2->currentStats().at("Speed")) {
        _fasterPokemon = inputPokemon2;
        _slowerPokemon = inputPokemon1;
    } else {
        int randomPokemon = generateRandom(1, 2);
        if (randomPokemon == 1) {
            _fasterPokemon = inputPokemon1;
            _slowerPokemon = inputPokemon2;
        } else {
            _fasterPokemon = inputPokemon2;
            _slowerPokemon = inputPokemon1;
        }
    }
}

void Battle::useMove(Pokemon* inputAttackingPokemon, Move* inputPokemonMove, Pokemon* inputDefendingPokemon) {
    std::cout << inputAttackingPokemon->name() << " used " << inputPokemonMove->name() << std::endl;
    if (!hitCheck(inputAttackingPokemon, inputPokemonMove, inputDefendingPokemon)) {
        std::cout << inputAttackingPokemon->name() << " Missed!" << std::endl;
        return;
    }
    if (inputPokemonMove->damageCategory() != "Status") {
        damageCalculation(inputAttackingPokemon, inputPokemonMove, inputDefendingPokemon);
    }
}

bool Battle::hitCheck(Pokemon* inputAttackingPokemon, Move* inputPokemonMove, Pokemon* inputDefendingPokemon) {
    int hitStage = std::clamp(inputAttackingPokemon->currentStages().at("Accuracy") - inputDefendingPokemon->currentStages().at("Evasion"), -6, 6);
    double stageMultiplier;
    if (hitStage >= 0) {
        stageMultiplier = (hitStage+3)/3.0;
    } else if (hitStage < 0) {
        stageMultiplier = 3.0/(std::abs(hitStage)+3);
    }
    int finalAccuracy = inputPokemonMove->accuracy() * stageMultiplier;
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

void Battle::distributeExperience(Pokemon* inputVictoriousPokemon, Pokemon* inputDefeatedPokemon) {
    // std::cout << "Defeated Pokemon: " << inputDefeatedPokemon->name() << " | " << inputDefeatedPokemon->species()->experienceValue() << std::endl;
    int experienceValue = inputDefeatedPokemon->species()->experienceValue();
    int defeatedLevel = inputDefeatedPokemon->level();
    double trainerBattle = 1.0; /* Trainers have not yet been implemented so this value is unchanging */
    double expShare = 1; /* EXP Share has not yet been implemented so this value is unchanging */
    double victoriousLevel = inputVictoriousPokemon->level();
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
    inputVictoriousPokemon->addExperience(earnedExperience);
}

void Battle::addEVs(Pokemon* inputVictoriousPokemon, Pokemon* inputDefeatedPokemon) {
    for (std::pair<std::string, int> i : inputDefeatedPokemon->species()->effortValues()) {
        int victorsTotalEVs = 0;
        for (std::pair<std::string, int> j : inputVictoriousPokemon->effortValues()) {
            victorsTotalEVs += j.second;
        }
        int currentEV = inputVictoriousPokemon->effortValues().at(i.first);
        if (victorsTotalEVs + i.second < 510) {
            inputVictoriousPokemon->effortValue(i.first, currentEV+i.second);
        } else if (victorsTotalEVs < 510) {
            inputVictoriousPokemon->effortValue(i.first, currentEV+510-victorsTotalEVs);
        }
    }
}

void Battle::faintPokemon(Pokemon* inputPokemon) {
    Pokemon* victoriousPokemon;
    if (inputPokemon == _slowerPokemon) {
        victoriousPokemon = _fasterPokemon;
    } else if (inputPokemon == _fasterPokemon) {
        victoriousPokemon = _slowerPokemon;
    }

    std::cout << inputPokemon->name() << " Fainted!" << std::endl;
    addEVs(victoriousPokemon, inputPokemon);
    distributeExperience(victoriousPokemon, inputPokemon);
    
    for (std::pair<int, Pokemon*> i : inputPokemon->trainer()->livingParty()) {
        if (i.second == inputPokemon) {
            inputPokemon->trainer()->faint(i.first);
            break;
        }
    }

    if (inputPokemon->trainer()->livingParty().size() > 0) {
        sendOutPokemon(inputPokemon->trainer());
    }
}

void Battle::sendOutPokemon(Trainer* inputTrainer) {
    std::cout << "Please choose a new pokemon, " << inputTrainer->name() << std::endl;
    for (std::pair<int, Pokemon*> i : inputTrainer->livingParty()) {
        std::cout << "\t" << i.first << ": " << i.second->name() << std::endl;
    }

    std::string userInput;
    if (_autoBattle) {
        std::map<int, Pokemon*>::const_iterator partyIterator = inputTrainer->livingParty().begin();
        std::advance(partyIterator, generateRandom(0, inputTrainer->livingParty().size()-1));
        userInput = std::to_string(partyIterator->first);
    } else {
        std::cin >> userInput;
    }
    std::cout << "\n";
    
    // If input is invalid -> Print an error message and get a new input;
    try {
        int inputPokemonSlot = std::stoi(userInput);
        inputTrainer->activePokemon(inputTrainer->livingParty().at(inputPokemonSlot));
    } catch (std::exception) {
        std::cout << "Error: \"" << userInput << "\" is an invalid pokemon slot." << std::endl;
        sendOutPokemon(inputTrainer);
    }
}

Battle::Battle(Trainer* inputTrainer1, Trainer* inputTrainer2, bool inputAutoBattle) {
    std::cout << "\n\n\n";
    _autoBattle = inputAutoBattle;
    _turn = 0;

    std::map<int, Pokemon*> trainer1Party;
    Pokemon* trainer1ActivePokemon;
    std::map<int, Pokemon*> trainer2Party;
    Pokemon* trainer2ActivePokemon;

    while (inputTrainer1->livingParty().size() > 0 && inputTrainer2->livingParty().size() > 0) {
        _turn++;
        trainer1Party = inputTrainer1->livingParty();
        trainer1ActivePokemon = const_cast<Pokemon*>(inputTrainer1->activePokemon());
        trainer2Party = inputTrainer2->livingParty();
        trainer2ActivePokemon = const_cast<Pokemon*>(inputTrainer2->activePokemon());

        getFasterPokemon(trainer1ActivePokemon, trainer2ActivePokemon);

        std::cout << "\n\nTurn " << _turn << std::endl;
        std::cout << "first: " << _fasterPokemon->name() << std::endl;
        Move* fasterPokemonMove = getMove(_fasterPokemon);
        std::cout << "second: " << _slowerPokemon->name() << std::endl;
        Move* slowerPokemonMove = getMove(_slowerPokemon);
        
        // std::cout << _fasterPokemon->name() << " " << fasterPokemonMove->name() << " " << _slowerPokemon->name() << std::endl;
        useMove(_fasterPokemon, fasterPokemonMove, _slowerPokemon);
        std::cout << _slowerPokemon->name() << " Is at " << _slowerPokemon->currentStats().at("HitPoints") << " HP\n" << std::endl;

        if (_slowerPokemon->currentStats().at("HitPoints") <= 0) {
            faintPokemon(_slowerPokemon);
        } else if (flinchCheck(fasterPokemonMove)) {
            std::cout << _slowerPokemon->name() << " Flinched!" << std::endl;
        } else {
            // std::cout << _slowerPokemon->name() << " " << slowerPokemonMove->name() << " " << _fasterPokemon->name() << std::endl;
            useMove(_slowerPokemon, slowerPokemonMove, _fasterPokemon);
            std::cout << _fasterPokemon->name() << " Is at " << _fasterPokemon->currentStats().at("HitPoints") << " HP\n" << std::endl;
            
            if (_fasterPokemon->currentStats().at("HitPoints") <= 0) {
                faintPokemon(_fasterPokemon);
            }
        }
    }
    std::cout << "Battle Over" << std::endl;
}