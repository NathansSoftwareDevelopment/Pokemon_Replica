#ifndef MACHINE_H
#define MACHINE_H
#include "Item.h"
#include "Move.h"

class Machine : public Item {
    private:
        Move* _move;
        bool _isHM;
        int _ID;
    public:
        const Move* move() const {return _move;}
        const bool isHM() const {return _isHM;}
        const int ID() const {return _ID;}
        Machine(Move* inputMove, bool inputIsHM, int inputID);
};


#endif