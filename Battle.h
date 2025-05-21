#ifndef BATTLE_H
#define BATTLE_h
#include "Pokemon_Class.h"
#include "Move.h"

class Battle {
    public:
        int battleTurn;
        bool battlePlayersTurn;
        Move* battlePlayer1Move;
        Move* battlePlayer2Move;
        Pokemon* battleFasterPokemon;
        Pokemon* battleSlowerPokemon;
        void battleDamageCalculation(Pokemon* attackingInputPokemon, Move* battleInputPokemonMove, Pokemon* defendingInputPokemon);
        Move* battleGetMove(Pokemon* attackingInputPokemon, int battleInputMove);
        void battleGetFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2);
        double Battle::battleStabMultiplier(Pokemon* attackingInputPokemon, Move* battleInputPokemonMove);
        Battle(Pokemon* inputPokemon1, Pokemon* inputPokemon2);
};

#endif