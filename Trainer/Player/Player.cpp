#include <random>
#include <string>
#include <map>
#include "Player.h"
#include "Utils.hpp"

const std::map<std::string, int> bagLookupMap = {
    {"Items", 0},
    {"Medicine", 1},
    {"TMs & HMs", 2},
    {"Berries", 3},
    {"Key Items", 4},
    {"Free Space", 5}
};

int Player::generateTrainerID() {
    return generateRandom(0, 65535);
}

Player::Player(std::string inputName) : Trainer(inputName, Player::generateTrainerID()) {
    _pokeDollars = 0;
}
