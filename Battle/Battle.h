#ifndef BATTLE_H
#define BATTLE_h
#include <string>
#include "Pokemon_Class.h"
#include "Move.h"
#include "Trainer.h"

class Battle {
    public:
        bool autoBattle;
        int turn;
        bool playersTurn;
        Move* player1Move;
        Move* player2Move;
        Pokemon* fasterPokemon;
        Pokemon* slowerPokemon;
        void damageCalculation(Pokemon* inputAttackingPokemon, Move* inputPokemonMove, Pokemon* inputDefendingPokemon);
        Move* getMove(Pokemon* inputAttackingPokemon);
        void getFasterPokemon(Pokemon* inputPokemon1, Pokemon* inputPokemon2);
        double stabMultiplier(Pokemon* inputAttackingPokemon, Move* inputPokemonMove);
        double effectivenessMultiplier(Move* inputPokemonMove, Pokemon* inputDefendingPokemon);
        void useMove(Pokemon* inputAttackingPokemon, Move* inputPokemonMove, Pokemon* inputDefendingPokemon);
        bool hitCheck(Pokemon* inputAttackingPokemon, Move* inputPokemonMove, Pokemon* inputDefendingPokemon);
        bool flinchCheck(Move* inputPokemonMove);
        void distributeExperience(Pokemon* inputVictoriousPokemon, Pokemon* inputDefeatedPokemon);
        void addEVs(Pokemon* inputVictoriousPokemon, Pokemon* defeatedInputPokemon);
        void faintPokemon(Pokemon* inputPokemon);
        void sendOutPokemon(Trainer* inputTrainer);
        Battle(Trainer* inputTrainer1, Trainer* inputTrainer2, bool inputAutoBattle = false);
};

#endif