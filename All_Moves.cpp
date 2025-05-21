#include <string>
#include <array>
#include <map>
#include "Move.h"
using Stages = std::map<std::string, std::array<int, 2>>;

std::map<std::string, int> emptyConditionMap;
std::map<std::string, std::array<int, 2>> emptyStageMap;


std::map<std::string, Move> moveMap = {
    {"Growl", Move("Growl", "Normal", "Status", 0, 100, 40, 0, emptyConditionMap, emptyStageMap, Stages{{"Attack", {-1, 100}}})},
    {"Scratch", Move("Scratch", "Normal", "Physical", 40, 100, 40)},
    {"Ember", Move("Ember", "Fire", "Special", 40, 100, 40, 0, {{"Burn", 10}})},
    {"Smokescreen", Move("Smokescreen", "Normal", "Status", 0, 100, 20, 0, emptyConditionMap, emptyStageMap, Stages{{"Accuracy", {-1, 100}}})},
    {"Dragon Rage", Move("Scratch", "Normal", "Special", 0, 100, 10, 0, emptyConditionMap, emptyStageMap, emptyStageMap, true)},
    {"Scary Face", Move("Scary Face", "Normal", "Status", 40, 100, 10, 0, emptyConditionMap, emptyStageMap, Stages{{"Speed", {-2, 100}}})},
    {"Fire Fang", Move("Fire Fang", "Fire", "Physical", 65, 95, 15, 10, {{"Burn", 10}})},
    {"Flame Burst", Move("Flame Burst", "Fire", "Special", 70, 100, 15, 0, emptyConditionMap, emptyStageMap, emptyStageMap, true)},
    {"Slash", Move("Slash", "Normal", "Physical", 70, 100, 20, 0, emptyConditionMap, emptyStageMap, emptyStageMap, true)},
    {"Flamethrower", Move("Flamethrower", "Fire", "Special", 95, 100, 15, 0, {{"Burn", 10}})},
    {"Fire Spin", Move("Fire Spin", "Fire", "Special", 35, 85, 15, 0, emptyConditionMap, emptyStageMap, emptyStageMap, true)},
    {"Inferno", Move("Inferno", "Fire", "Special", 100, 50, 5, 0, {{"Burn", 10}}, emptyStageMap, emptyStageMap, true)}
};