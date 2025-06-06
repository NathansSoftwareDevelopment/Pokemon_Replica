#ifndef ITEMS_H
#define ITEMS_H
#include <string>
#include <map>
#include "Pokemon_class.h"
#include "Player.h"

struct ItemUse {
    Player* player = NULL;
    int pokemonSlot = -1;
    int moveSlot = -1;
    
    ItemUse& Player(Player* inputPlayer) {player = inputPlayer; return *this;}
    ItemUse& PokemonSlot(int inputPokemonSlot) {pokemonSlot = inputPokemonSlot; return *this;}
    ItemUse& MoveSlot(int inputMoveSlot) {moveSlot = inputMoveSlot; return *this;}
};

class Item {
    protected:
        std::string _name;
        bool _holdable;
        std::pair<std::string, int> _pocket;

        Item(std::string inputName, bool inputHoldable, std::string inputPocket);
    public:
        const std::string name() const {return _name;}
        const bool holdable() const {return _holdable;}
        const std::pair<std::string, int> pocket() const {return _pocket;}
    
        virtual void use(ItemUse inputParameters) = 0;
};

extern const std::map<std::string, int> bagLookupMap;

#endif