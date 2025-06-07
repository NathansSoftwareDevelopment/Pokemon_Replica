#include <string>
#include <map>
#include "Trainer.h"
#include "Pokemon_Class.h"

int Trainer::_totalTrainers = 0;

Trainer& Trainer::pokemon(int inputSlot, Pokemon* inputPokemon) {
    _pokemon[inputSlot]=inputPokemon;
    inputPokemon->trainer(this);
    return *this;
}

Trainer::Trainer(std::string inputName, int inputTrainerID) {
    _name = inputName;
    _ID = inputTrainerID;
}

Trainer::Trainer(std::string inputName, Pokemon* inputPokemon) {
    _name = inputName;
    _pokemon[1] = inputPokemon;
    inputPokemon->trainer(this);
    _totalTrainers++;
    _ID = _totalTrainers;
}

Trainer::Trainer(std::string inputName, std::map<int, Pokemon*> inputPokemon) {
    _name = inputName;
    _pokemon = inputPokemon;
    for (std::pair<int, Pokemon*> i : inputPokemon) {
        i.second->trainer(this);
    }
    _totalTrainers++;
    _ID = _totalTrainers;
}