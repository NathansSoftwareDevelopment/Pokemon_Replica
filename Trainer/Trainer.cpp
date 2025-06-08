#include <string>
#include <map>
#include "Trainer.h"
#include "Pokemon_Class.h"

int Trainer::_totalTrainers = 0;

Trainer& Trainer::pokemon(int inputSlot, Pokemon* inputPokemon) {
    _pokemon[inputSlot]=inputPokemon;
    inputPokemon->trainer(this);
    if (inputPokemon->currentStats().at("HitPoints") > 0) {
        _livingParty.emplace(inputSlot, inputPokemon);
    }
    if (_activePokemon == NULL) {
        _activePokemon = inputPokemon;
    }
    return *this;
}

Trainer& Trainer::activePokemon(Pokemon* inputPokemon) {
    _activePokemon = inputPokemon;
    return *this;
}

Trainer::Trainer(std::string inputName, int inputTrainerID) {
    _name = inputName;
    _ID = inputTrainerID;
}

Trainer::Trainer(std::string inputName, Pokemon* inputPokemon) {
    _name = inputName;
    _pokemon[1] = inputPokemon;
    _activePokemon = inputPokemon;
    inputPokemon->trainer(this);
    _totalTrainers++;
    _ID = _totalTrainers;
    _livingParty = _pokemon;
}

Trainer::Trainer(std::string inputName, std::map<int, Pokemon*> inputPokemon) {
    _name = inputName;
    _pokemon = inputPokemon;
    for (std::pair<int, Pokemon*> i : inputPokemon) {
        i.second->trainer(this);
    }
    _activePokemon = inputPokemon.at(1);
    _totalTrainers++;
    _ID = _totalTrainers;
    _livingParty = _pokemon;
}