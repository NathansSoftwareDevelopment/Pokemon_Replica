#include <string>
#include <map>
#include "Move.h"

std::map<std::string, Move> moveMap = {
    {"Growl", Move("Growl", "Normal", "Status", 0, 100, 40, false)},
    {"Scratch", Move("Scratch", "Normal", "Physical", 40, 100, 40, true)},
    {"Ember", Move("Ember", "Fire", "Special", 40, 100, 40, true)},
    {"Smokescreen", Move("Smokescreen", "Normal", "Status", 40, 100, 20, true)},
    {"Dragon Rage", Move("Scratch", "Normal", "Special", 0, 100, 10, true)},
    {"Scary Face", Move("Scary Face", "Normal", "Status", 40, 100, 10, true)},
    {"Fire Fang", Move("Fire Fang", "Fire", "Physical", 65, 95, 15, true)},
    {"Flame Burst", Move("Flame Burst", "Fire", "Special", 70, 100, 15, true)},
    {"Slash", Move("Slash", "Normal", "Physical", 70, 100, 20, true)},
    {"Flamethrower", Move("Flamethrower", "Fire", "Special", 95, 100, 15, true)},
    {"Fire Spin", Move("Fire Spin", "Fire", "Special", 35, 85, 15, true)},
    {"Inferno", Move("Inferno", "Fire", "Special", 100, 50, 5, true)}
};