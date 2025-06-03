#ifndef TRAINER_H
#define TRAINER_H
#include <map>
#include <string>
#include "Pokemon_Class.h"

class Trainer {
    private:
        static int _totalTrainers;
        std::string _name;
        int _ID;
        std::map<int, Pokemon*> _pokemon;
    public:
        static int totalTrainers() {return _totalTrainers;}
        const std::string name() const {return _name;}
        const int ID() const {return _ID;}
        const std::map<int, Pokemon*>& pokemon() const {return _pokemon;}

        Trainer& pokemon(int inputSlot, Pokemon* inputPokemon) {_pokemon[inputSlot]=inputPokemon; return *this;}

        Trainer(std::string inputName, Pokemon* inputPokemon);
        Trainer(std::string inputName, std::map<int, Pokemon*> inputPokemon);
};

#endif