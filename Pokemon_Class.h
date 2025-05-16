#include <string>

class Pokemon {
    public:
        std::string pokemonSpecies;
        std::string pokemonName;

        int pokemonLevel;
        int pokemonExperience;

        std::string pokemonNature;
        
        std::string pokemonAbility;
        
        std::string pokemonItem;

        std::string pokemonType1;
        std::string pokemonType2;

        std::string pokemonMove1;
        std::string pokemonMove2;
        std::string pokemonMove3;
        std::string pokemonMove4;
        
        std::string pokemonCondition;

        int speciesHitPoints;
        int speciesAttack;
        int speciesDefense;
        int speciesSpecialAttack;
        int speciesSpecialDefense;
        int speciesSpeed;
        
        int pokemonHitPointsIndividualValue;
        int pokemonAttackIndividualValue;
        int pokemonDefenseIndividualValue;
        int pokemonSpecialAttackIndividualValue;
        int pokemonSpecialDefenseIndividualValue;
        int pokemonSpeedIndividualValue;

        int pokemonHitPointsEffortValue;
        int pokemonAttackEffortValue;
        int pokemonDefenseEffortValue;
        int pokemonSpecialAttackEffortValue;
        int pokemonSpecialDefenseEffortValue;
        int pokemonSpeedEffortValue;

        int pokemonHitPoints;
        int pokemonAttack;
        int pokemonDefense;
        int pokemonSpecialAttack;
        int pokemonSpecialDefense;
        int pokemonSpeed;

        int currentHitPoints;
        int currentAttack;
        int currentDefense;
        int currentSpecialAttack;
        int currentSpecialDefense;
        int currentSpeed;

        void setSpeciesStats(int speciesStats[6]);
        void setPokemonIndividualValues(int IndividualValues[6]);
        void setPokemonEffortValues(int EffortValues[6]);
        void calculatePokemonStats();
        
        Pokemon(std::string pokemonSpecies, std::string pokemonName, std::string pokemonNature, std::string pokemonAbility, int speciesStats[6], int pokemonIndividualValues[6]);
        Pokemon(
            std::string pokemonSpecies, std::string pokemonName, std::string pokemonNature, int pokemonLevel, int pokemonExperience, std::string pokemonAbility,
            std::string pokemonType1, std::string pokemonType2,
            std::string pokemonMove1, std::string pokemonMove2, std::string pokemonMove3, std::string pokemonMove4, 
            std::string pokemonCondition,
            int speciesStats[6], int pokemonIndividualValues[6], int pokemonEffortValues[6]
        );
        ~Pokemon();
};

