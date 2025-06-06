#include <string>
#include <map>
#include "Item.h"

const std::map<std::string, int> bagLookupMap = {
    {"Items", 0},
    {"Medicine", 1},
    {"TMs & HMs", 2},
    {"Berries", 3},
    {"Key Items", 4},
    {"Free Space", 5}
};

Item::Item(std::string inputName, bool inputHoldable, std::string inputPocket) {
    _name = inputName;
    _holdable = inputHoldable;
    _pocket = {inputPocket, bagLookupMap.at(inputPocket)};
}