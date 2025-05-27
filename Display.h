#ifndef DISPLAY_H
#define DISPLAY_H
#include "Move.h"
#include "Nature.h"
#include "Species.h"
#include "Type.h"
#include "Pokemon_Class.h"

class display {
    private:
        static int displayID;
        void idCounter(bool stackCall);
    public:
        void all(Pokemon* inputPokemon, bool stackCall = false);
        void pokemonName(Pokemon* inputPokemon, bool stackCall = false);
        void pokemonSpecies(Pokemon* inputPokemon, bool stackCall = false);
        void nature(Pokemon* inputPokemon, bool stackCall = false);
        void pokemonStats(Pokemon* inputPokemon, bool stackCall = false);
        void speciesStats(Pokemon* inputPokemon, bool stackCall = false);
        void pokemonType(Pokemon* inputPokemon, bool stackCall = false);
        void pokemonMovesAll(Pokemon* inputPokemon, bool stackCall = false);
        void pokemonMoveNames(Pokemon* inputPokemon, bool stackCall = false);
        void pokemonMoveAll(Pokemon* inputPokemon, int moveIndex, bool stackCall = false);
};

#endif