#include <iostream>
using namespace std;

#include "tile.h"

#pragma once 

class Ladder : public Tile {
    public:
        Ladder () : Tile('L') {} // Constructor to data initialization                                                             
        Ladder(const char &type) : Tile(type) {} // Constructor with const data initialization
        ~Ladder() {}
};