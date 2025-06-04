#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>
#include "Trainer.h"

class Player : Trainer {
    public:
        int generateTrainerID();

        Player(std::string inputName);
};

#endif