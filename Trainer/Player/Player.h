#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <array>
#include <vector>
#include <map>
#include "Trainer.h"
using Container = std::pair<std::string, std::vector<std::pair<std::string, int>>>;

class Player : public Trainer {
    private:
        int _pokeDollars;
        std::array<Container, 6> _Bag = {
            Container("Items", {}),
            Container("Medicine", {}),
            Container("TMs & HMs", {}),
            Container("Berries", {}),
            Container("Key Items", {}),
            Container("Free Space", {})
        };
    public:
        const int pokeDollars() const {return _pokeDollars;}
        const std::array<Container, 6>& Bag() const {return _Bag;}

        Player& pokeDollars(int inputMoney) {_pokeDollars += inputMoney; return *this;}

        int generateTrainerID();

        Player(std::string inputName);
};

#endif