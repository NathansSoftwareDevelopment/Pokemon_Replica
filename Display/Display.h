#ifndef DISPLAY_H
#define DISPLAY_H
#include "Pokemon_Class.h"
#include "Species.h"
#include "Move.h"
#include "Type.h"
#include "Nature.h"
#include "Growth_Rate.h"
#include "Trainer.h"

class display {
    private:
        static int displayID;
        void idCounter(bool stackCall);
    public:
        void all(Pokemon* inputPokemon, std::string inputSpecies, std::string inputMove, std::string inputType, std::string inputNature, std::string inputGrowthRate, Trainer* inputTrainer, bool stackCall = false);

        void pokemonAll(Pokemon* inputPokemon, bool stackCall = false);
        
        void speciesAll(Species* inputSpecies, bool stackCall = false);

        void moveAll(Move* inputMove, bool stackCall = false);

        void typeAll(Type* inputType, bool stackCall = false);

        void natureAll(Nature* inputNature, bool stackCall = false);

        void growthRateAll(GrowthRate* inputGrowthRate, bool stackCall = false);

        void trainerAll(Trainer* inputTrainer, bool stackCall=false);
};

#endif