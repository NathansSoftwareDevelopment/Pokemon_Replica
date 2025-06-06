#ifndef ITEMS_H
#define ITEMS_H
#include <string>
#include <map>

class Item {
    private:
        std::string _name;
        bool _holdable;
        std::pair<std::string, int> _pocket;
    public:
        const std::string name() const {return _name;}
        const bool holdable() const {return _holdable;}
        const std::pair<std::string, int> pocket() const {return _pocket;}

        Item(std::string inputName, bool inputHoldable, std::string inputPocket);
};

extern const std::map<std::string, int> bagLookupMap;

#endif