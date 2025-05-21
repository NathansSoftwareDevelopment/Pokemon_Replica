#include <string>
#include <map>
#include "Move.h"
std::map<std::string, int> emptyConditionMap;


std::map<std::string, Move> moveMap = {
    {"Growl", Move("Growl", "Normal", "Status", 0, 100, 40)},
    {"Scratch", Move("Scratch", "Normal", "Physical", 40, 100, 40)},
    {"Ember", Move("Ember", "Fire", "Special", 40, 100, 40, 0, {{"Burn", 10}})},
    {"Smokescreen", Move("Smokescreen", "Normal", "Status", 0, 100, 20)},
    {"Dragon Rage", Move("Scratch", "Normal", "Special", 0, 100, 10, 0, emptyConditionMap, true)},
    {"Scary Face", Move("Scary Face", "Normal", "Status", 40, 100, 10)},
    {"Fire Fang", Move("Fire Fang", "Fire", "Physical", 65, 95, 15, 10, {{"Burn", 10}})},
    {"Flame Burst", Move("Flame Burst", "Fire", "Special", 70, 100, 15, 0, emptyConditionMap, true)},
    {"Slash", Move("Slash", "Normal", "Physical", 70, 100, 20, 0, emptyConditionMap, true)},
    {"Flamethrower", Move("Flamethrower", "Fire", "Special", 95, 100, 15, 0, {{"Burn", 10}})},
    {"Fire Spin", Move("Fire Spin", "Fire", "Special", 35, 85, 15, 0, emptyConditionMap, true)},
    {"Inferno", Move("Inferno", "Fire", "Special", 100, 50, 5, 0, {{"Burn", 10}}, true)}
};