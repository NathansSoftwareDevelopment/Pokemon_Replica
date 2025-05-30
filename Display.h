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
        void all(Pokemon* inputPokemon, std::string inputSpecies, std::string inputMove, bool stackCall = false);

        void pokemonAll(Pokemon* inputPokemon, bool stackCall = false);
        
        void speciesAll(Species* inputSpecies, bool stackCall = false);

        void moveAll(Move* inputMove, bool stackCall = false);
};

#endif