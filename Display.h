#ifndef DISPLAY_H
#define DISPLAY_H
#include "Move.h"
#include "Nature.h"
#include "Species.h"
#include "Type.h"
#include "Pokemon_Class.h"

class display {
    public:
        static int displayID;
        void idCounter(bool stackCall);
        void All(Pokemon inputPokemon, bool stackCall = false);
        void PokemonName(Pokemon inputPokemon, bool stackCall = false);
        void PokemonSpecies(Pokemon inputPokemon, bool stackCall = false);
        void Nature(Pokemon inputPokemon, bool stackCall = false);
        void PokemonStats(Pokemon inputPokemon, bool stackCall = false);
        void SpeciesStats(Pokemon inputPokemon, bool stackCall = false);
        void PokemonType(Pokemon inputPokemon, bool stackCall = false);
        void PokemonMovesAll(Pokemon inputPokemon, bool stackCall = false);
        void PokemonMoveNames(Pokemon inputPokemon, bool stackCall = false);
        void PokemonMoveAll(Pokemon inputPokemon, int moveIndex, bool stackCall = false);
};

#endif