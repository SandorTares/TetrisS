//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRAMINO_H
#define TETRISS_TETRAMINO_H
#include "iostream"
#include "GlobalVariables.h"

struct block{ //The blocks that make a tetramino
    int x; //The x and y position of the block relative to the origin of the tetramino
    int y;
};

class Tetramino {

protected:
    int x,y; //The x and y position of the origin of the tetramino
    int color; //The color of a tetramino
    block blocks[TETRAMINO_BLOCKS]{}; //The array of blocks that make a tetramino, usually 4
public:
    int getX();
    int getY();
    int getColor();
    block getBlock(int n);
    void setXY(int newX, int newY, bool relative);
    void rotateBlocks(bool clockwise); //Function to rotate the tetramino
    explicit Tetramino(int _x = 0, int _y = 0, int _color = GRAPHICS_WHITE)
    {
        x = _x;
        y = _y;
        color = _color;
    }

};

class TetraminoI:public Tetramino
{
    public:TetraminoI(int x, int y) : Tetramino(x, y, GRAPHICS_CYAN) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {2, 0};
    }
};

class TetraminoO:public Tetramino
{
    public:TetraminoO(int x, int y) : Tetramino(x, y, GRAPHICS_YELLOW) {
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
    }
};
class TetraminoS:public Tetramino
{
public:TetraminoS(int x, int y) : Tetramino(x, y, GRAPHICS_GREEN) {
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {-1, 1};
    }

};

class TetraminoZ:public Tetramino
{
public:TetraminoZ(int x, int y) : Tetramino(x, y, GRAPHICS_RED) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
    }

};

class TetraminoL:public Tetramino
{
public:TetraminoL(int x, int y) : Tetramino(x, y, GRAPHICS_WHITE) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {-1, 1};
    }
};
class Tetraminol:public Tetramino
{
public:Tetraminol(int x, int y) : Tetramino(x, y, GRAPHICS_BLUE) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {1, 1};
    }
};

class TetraminoT:public Tetramino
{
public:TetraminoT(int x, int y) : Tetramino(x, y, GRAPHICS_MAGENTA) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {0, 1};
    }
};
#endif //TETRISS_TETRAMINO_H
