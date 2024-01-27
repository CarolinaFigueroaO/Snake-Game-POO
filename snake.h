#include <iostream>
using namespace std;

#include "tile.h"

#pragma once 

class Snake : public Tile {
    public:
        Snake () : Tile('S') {} // Constructor to data initialization                                                             
        Snake(const char &type) : Tile(type) {} // Constructor with const data initialization
        ~Snake() {}
};