#include <string>
#include <map>
#include "Item.h"

Item::Item(std::string inputName, bool inputHoldable, std::string inputPocket) {
    _name = inputName;
    _holdable = inputHoldable;
    _pocket = {inputPocket, bagLookupMap.at(inputPocket)};
}