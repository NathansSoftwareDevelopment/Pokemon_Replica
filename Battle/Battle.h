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
        void damageCalculation(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        Move* getMove(Pokemon* attackingInputPokemon);
        void getFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2);
        double stabMultiplier(Pokemon* attackingInputPokemon, Move* inputPokemonMove);
        double effectivenessMultiplier(Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        void useMove(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        bool hitCheck(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        bool flinchCheck(Move* inputPokemonMove);
        void distributeExperience(Pokemon* victoriousInputPokemon, Pokemon* defeatedInputPokemon);
        void addEVs(Pokemon* victoriousInputPokemon, Pokemon* defeatedInputPokemon);
        void faintPokemon(Pokemon* inputPokemon);
        void sendOutPokemon(Trainer* inputTrainer);
        Battle(Trainer* inputTrainer1, Trainer* inputTrainer2);
};

#endif