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
    if (_activePokemon == nullptr) {
        _activePokemon = inputPokemon;
    }
    return *this;
}

Trainer& Trainer::activePokemon(Pokemon* inputPokemon) {
    _activePokemon = inputPokemon;
    return *this;
}

Trainer::Trainer(std::string inputName, int inputTrainerID, std::map<int, Pokemon*> inputPokemon) {
    _name = inputName;
    _pokemon = inputPokemon;
    for (std::pair<int, Pokemon*> i : inputPokemon) {
        i.second->trainer(this);
    }
    if (!inputPokemon.empty()) {
        _activePokemon = inputPokemon.at(1);
    }
    _ID = inputTrainerID;
    _livingParty = _pokemon;
    _totalTrainers++;
}