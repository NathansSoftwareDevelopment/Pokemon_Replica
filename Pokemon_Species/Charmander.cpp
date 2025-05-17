#ifndef CHARMANDER_CPP
#define CHARMANDER_CPP
#include "Pokemon_Class.h"
#include <string>

class Charmander : public Pokemon{
    public:
        std::string speciesName = "Charmander";
        int charmanderStats[6] = {39, 52, 43, 60, 50, 65};
        void doNothing() override;
        Charmander(std::string pokemonInputName, std::string pokemonInputNature, std::string pokemonInputAbility, int pokemonIndividualValues[6]);
};

Charmander::Charmander(std::string pokemonInputName, std::string pokemonInputNature, std::string pokemonInputAbility, int pokemonIndividualValues[6]) : Pokemon(speciesName, pokemonInputName, pokemonInputNature, pokemonInputAbility, charmanderStats, pokemonIndividualValues) {
    pokemonType1 = "Fire";
    pokemonType2 = "Null";
}

#endif