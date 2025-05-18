#include "Pokemon_Class.h"
#include "Charmander.h"
#include <string>

Charmander::Charmander(std::string pokemonInputName, std::string pokemonInputNature, std::string pokemonInputAbility, int pokemonIndividualValues[6]) : Pokemon("Charmander", pokemonInputName, pokemonInputNature, pokemonInputAbility, (int[]){39, 52, 43, 60, 50, 65}, pokemonIndividualValues) {

}

Charmander::Charmander(
    std::string pokemonInputName, std::string pokemonInputNature, int pokemonInputLevel, int pokemonInputExperience, std::string pokemonInputAbility,
    std::string pokemonInputMove1, std::string pokemonInputMove2, std::string pokemonInputMove3, std::string pokemonInputMove4, 
    std::string pokemonInputCondition,
    int pokemonInputIndividualValues[6], int pokemonInputEffortValues[6]
) : Pokemon(
    "Charmander", pokemonInputName, pokemonInputNature, pokemonInputLevel, pokemonInputExperience, pokemonInputAbility,
    "Fire", "None",
    pokemonInputMove1, pokemonInputMove2, pokemonInputMove3, pokemonInputMove4, 
    pokemonInputCondition,
    (int[]){39, 52, 43, 60, 50, 65}, pokemonInputIndividualValues, pokemonInputEffortValues
) {

}