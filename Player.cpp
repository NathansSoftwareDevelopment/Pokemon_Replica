#include <random>
#include <string>
#include <map>
#include "Player.h"
#include "Utils.hpp"

int Player::generateTrainerID() {
    return generateRandom(0, 65535);
}

Player::Player(std::string inputName) : Trainer(inputName, Player::generateTrainerID()) {
    _pokeDollars = 0;
}
