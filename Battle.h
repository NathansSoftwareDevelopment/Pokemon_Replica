#ifndef BATTLE_H
#define BATTLE_h
#include "Pokemon_Class.h"
#include "Move.h"

class Battle {
    public:
        int turn;
        bool playersTurn;
        Move* player1Move;
        Move* player2Move;
        Pokemon* fasterPokemon;
        Pokemon* slowerPokemon;
        void damageCalculation(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        Move* getMove(Pokemon* attackingInputPokemon, int inputMove);
        void getFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2);
        double stabMultiplier(Pokemon* attackingInputPokemon, Move* inputPokemonMove);
        double effectivenessMultiplier(Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        void useMove(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        bool hitCheck(Pokemon* attackingInputPokemon, Move* inputPokemonMove, Pokemon* defendingInputPokemon);
        Battle(Pokemon* inputPokemon1, Pokemon* inputPokemon2);
};

#endif