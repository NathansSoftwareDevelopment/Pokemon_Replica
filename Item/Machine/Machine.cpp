#include <string>
#include "Machine.h"
#include "Move.h"

Machine::Machine(Move* inputMove, bool inputIsHM, int inputID) : Item(inputMove->name(), false, "TMs & HMs") {
    _move = inputMove;
    _isHM = inputIsHM;
    _ID = inputID;
}