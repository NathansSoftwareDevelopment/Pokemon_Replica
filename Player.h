#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>
#include "Trainer.h"

class Player : public Trainer {
    private:
        int _pokeDollars;
    public:
        const int pokeDollars() const {return _pokeDollars;}

        Player& pokeDollars(int inputMoney) {_pokeDollars += inputMoney; return *this;}

        int generateTrainerID();

        Player(std::string inputName);
};

#endif