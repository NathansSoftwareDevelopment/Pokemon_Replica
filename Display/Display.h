#ifndef DISPLAY_H
#define DISPLAY_H
#include "Pokemon_Class.h"
#include "Species.h"
#include "Move.h"
#include "Type.h"
#include "Nature.h"
#include "Growth_Rate.h"
#include "Trainer.h"
#include "Item.h"

class Display {
    private:
        static int displayID;
        static void idCounter(bool stackCall);
    public:
        static void all(Pokemon* inputPokemon, std::string inputSpecies, std::string inputMove, std::string inputType, std::string inputNature, std::string inputGrowthRate, Trainer* inputTrainer, Item* inputItem, bool stackCall = false);

        static void pokemonAll(Pokemon* inputPokemon, bool stackCall = false);
        
        static void speciesAll(Species* inputSpecies, bool stackCall = false);

        static void moveAll(Move* inputMove, bool stackCall = false);

        static void typeAll(Type* inputType, bool stackCall = false);

        static void natureAll(Nature* inputNature, bool stackCall = false);

        static void growthRateAll(GrowthRate* inputGrowthRate, bool stackCall = false);

        static void trainerAll(Trainer* inputTrainer, bool stackCall = false);
        static void trainerLivingParty(Trainer* inputTrainer, bool stackCall = false);

        static void itemAll(Item* inputItem, bool stackCall = false);
};

#endif