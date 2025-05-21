#include <string>
#include <map>
#include "Move.h"
std::map<std::string, int> emptyMap;


std::map<std::string, Move> moveMap = {
    {"Growl", Move("Growl", "Normal", "Status", 0, 100, 40, emptyMap, 0, false)},
    {"Scratch", Move("Scratch", "Normal", "Physical", 40, 100, 40, emptyMap, 0, false)},
    {"Ember", Move("Ember", "Fire", "Special", 40, 100, 40, {{"Burn", 10}}, 0, false)},
    {"Smokescreen", Move("Smokescreen", "Normal", "Status", 0, 100, 20, emptyMap, 0, true)},
    {"Dragon Rage", Move("Scratch", "Normal", "Special", 0, 100, 10, emptyMap, 0, true)},
    {"Scary Face", Move("Scary Face", "Normal", "Status", 40, 100, 10, emptyMap, 0, true)},
    {"Fire Fang", Move("Fire Fang", "Fire", "Physical", 65, 95, 15, {{"Burn", 10}}, 10, false)},
    {"Flame Burst", Move("Flame Burst", "Fire", "Special", 70, 100, 15, emptyMap, 0, true)},
    {"Slash", Move("Slash", "Normal", "Physical", 70, 100, 20, emptyMap, 0, true)},
    {"Flamethrower", Move("Flamethrower", "Fire", "Special", 95, 100, 15, {{"Burn", 10}}, 0, false)},
    {"Fire Spin", Move("Fire Spin", "Fire", "Special", 35, 85, 15, emptyMap, 0, true)},
    {"Inferno", Move("Inferno", "Fire", "Special", 100, 50, 5, {{"Burn", 10}}, 0, true)}
};