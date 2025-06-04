#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>
#include "Trainer.h"

class Player : Trainer {
    private:
        int _trainerID;
    public:
        const int trainerID() const {return _trainerID;}

        Player(std::string inputName);
};

#endif