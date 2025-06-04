#include <string>
#include <map>
#include "Trainer.h"
#include "Pokemon_Class.h"

int Trainer::_totalTrainers = 0;

Trainer::Trainer(std::string inputName, int inputTrainerID) {
    _name = inputName;
    _ID = inputTrainerID;
}

Trainer::Trainer(std::string inputName, Pokemon* inputPokemon) {
    _name = inputName;
    _pokemon[1] = inputPokemon;
    _totalTrainers++;
    _ID = _totalTrainers;
}

Trainer::Trainer(std::string inputName, std::map<int, Pokemon*> inputPokemon) {
    _name = inputName;
    _pokemon = inputPokemon;
    _totalTrainers++;
    _ID = _totalTrainers;
}