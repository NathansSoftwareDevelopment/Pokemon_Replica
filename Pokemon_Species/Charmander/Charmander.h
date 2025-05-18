#ifndef CHARMANDER_H
#define CHARMANDER_H

#include <string>

class Charmander : public Pokemon {
public:
    Charmander(std::string pokemonInputName, std::string pokemonInputNature, std::string pokemonInputAbility, int pokemonIndividualValues[6]);
    Charmander(
        std::string pokemonInputName, std::string pokemonInputNature, int pokemonInputLevel, int pokemonInputExperience, std::string pokemonInputAbility,
        std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4, 
        std::string pokemonInputCondition,
        int pokemonInputIndividualValues[6], int pokemonInputEffortValues[6]
    );
    virtual ~Charmander() override {};
};

#endif