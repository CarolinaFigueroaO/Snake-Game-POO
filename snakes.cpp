#include <iostream>
#include <string>
#include "board.h"
#include "dice.h"
#include "snake.h"
#include "ladder.h"
#include "player.h"

using namespace std;

int main() {
    Board b(10);
    b.setRandomTiles(2,3);
    b.printBoard();
    return 0;
}