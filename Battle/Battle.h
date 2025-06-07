#ifndef BATTLE_H
#define BATTLE_h
#include <string>
#include "Pokemon_Class.h"
#include "Move.h"
#include "Trainer.h"

class Battle {
    public:
        int turn;
        bool playersTurn;
        Move* player1Move;
        Move* player2Move;
        Pokemon* fasterPokemon;
        Pokemon* slowerPokemon;
        Pokemon* trainer1ActivePokemon;
        Pokemon* trainer2ActivePokemon;
        void damageCalculation(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        Move* getMove(Pokemon* attackingInputPokemon, int inputMove);
        void getFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2);
        double stabMultiplier(Pokemon* attackingInputPokemon, Move* inputPokemonMove);
        double effectivenessMultiplier(Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        void useMove(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        bool hitCheck(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        bool flinchCheck(Move* inputPokemonMove);
        void distributeExperience(Pokemon* victoriousInputPokemon, Pokemon* defeatedInputPokemon);
        void addEVs(Pokemon* victoriousInputPokemon, Pokemon* defeatedInputPokemon);
        void faintPokemon(Pokemon*& inputActivePokemon, std::map<int, Pokemon*>& inputTrainerParty);
        std::map<int, Pokemon*> makePartyMap(Trainer* inputTrainer);
        void sendOutPokemon(Pokemon*& inputActivePokemon, std::map<int, Pokemon*>& inputTrainerParty);
        Battle(Trainer* inputTrainer1, Trainer* inputTrainer2);
};

#endif