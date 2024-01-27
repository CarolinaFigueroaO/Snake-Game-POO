#include <iostream>
using namespace std;

#pragma once 

class Tile {
    protected:
        char type;
    public:
        Tile () : type('N') {} // Constructor to data initialization                                                             
        Tile(const char &type) : type(type) {} // Constructor with const data initialization
        Tile(const Tile& other) : type(other.type) {} //Copy constructor
        virtual ~Tile() {} //Destructor

        char getType() const { return type; } //Getter
        void setType(const char &type) { this -> type = type; } //Setter
        void printTile() { cout << getType() << endl; }
};

