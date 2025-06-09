#ifndef BATTLE_H
#define BATTLE_h
#include <string>
#include "Pokemon_Class.h"
#include "Move.h"
#include "Trainer.h"

class Battle {
    private:
        bool _autoBattle;
        int _turn;
        bool _playersTurn;
        Move* _player1Move;
        Move* _player2Move;
        Pokemon* _fasterPokemon;
        Pokemon* _slowerPokemon;

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
    public:
        Battle(Trainer* inputTrainer1, Trainer* inputTrainer2, bool inputAutoBattle = false);
};

#endif