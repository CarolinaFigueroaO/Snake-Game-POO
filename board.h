#include <iostream>
#include <vector>
#include <random>
using namespace std;

#include "tile.h"
#include "snake.h"
#include "ladder.h"

#pragma once

class Board 
{
    int sizeBoard; 
    vector<Tile> board;

    public:
        Board(const int &sizeBoard);
        Board(const vector<Tile> &t) : sizeBoard(t.size()), board(t), randomEngine(random_device{}()) {}
        Board(const Board &other) : sizeBoard(other.sizeBoard), board(other.board), randomEngine(random_device{}()){}
        ~Board(){}

    void setSize(int sizeBoard) { this -> sizeBoard = sizeBoard; }
    int getSize(){ return sizeBoard; }
    void setRandomTiles(int, int);
    void printBoard () const;

    private:
        default_random_engine randomEngine;
        int randomPositions()
        {
            uniform_int_distribution<int> distribution(0, getSize() - 1);
            return distribution(randomEngine);
        }
};

Board::Board(const int &sizeBoard) : sizeBoard(sizeBoard), board(sizeBoard)
{
    for (int i = 0; i < sizeBoard; i++)
    {
        board.push_back(Tile());
    }
    
}


void Board::setRandomTiles(int numSnakes, int numLadders)
{
    for (int i = 0; i < numSnakes; ++i) 
    {
        int position = randomPositions();

        // Verificar si la posición está ocupada
        while (board[position].getType() != 'N') 
        {
            position = randomPositions();
        }

        board[position] = Snake();
    }

    for (int i = 0; i < numLadders; ++i) 
    {
        int position = randomPositions();

        // Verificar si la posición está ocupada
        while (board[position].getType() != 'N') 
        {
            position = randomPositions();
        }

        board[position] = Ladder();
    }
}



void Board::printBoard() const
{
    for (const auto& tile : board) 
    {
        cout << tile.getType() << " ";
    }
    cout << endl;
}