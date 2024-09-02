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
    int color;
    block blocks[TETRAMINO_BLOCKS]{}; //The array of blocks that make a tetramino, usually 4
public:
    block getBlockPos(int n);
    block getBlockPosRelative(int n);
    int getColor();
    void changePos(int deltaX, int deltaY);
    void doBlocksRotation(bool clockwise); //Function to doRotation the tetramino
    Tetramino()
    {
        x = 0;
        y = 0;
        color = GRAPHICS_WHITE;
    }
    Tetramino(int _x, int _y)
    {
        x = _x;
        y = _y;
        color = GRAPHICS_WHITE;
    }

};

class TetraminoI:public Tetramino
{
    public:TetraminoI(int x, int y) : Tetramino(x, y) {
        color = GRAPHICS_BLUE;
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {2, 0};
    }
};

class TetraminoO:public Tetramino
{
    public:TetraminoO(int x, int y) : Tetramino(x, y) {
        color = GRAPHICS_YELLOW;
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
    }
};
class TetraminoS:public Tetramino
{
public:TetraminoS(int x, int y) : Tetramino(x, y) {
        color = GRAPHICS_RED;
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {-1, 1};
    }

};

class TetraminoZ:public Tetramino
{
public:TetraminoZ(int x, int y) : Tetramino(x, y) {
        color = GRAPHICS_CYAN;
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
    }

};

class TetraminoL:public Tetramino
{
public:TetraminoL(int x, int y) : Tetramino(x, y) {
        color = GRAPHICS_GREEN;
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {-1, 1};
    }
};
class Tetraminol:public Tetramino
{
public:Tetraminol(int x, int y) : Tetramino(x, y) {
        color = GRAPHICS_MAGENTA;
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {1, 1};
    }
};

class TetraminoT:public Tetramino
{
public:TetraminoT(int x, int y) : Tetramino(x, y) {
        color = GRAPHICS_WHITE;
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {0, 1};
    }
};
#endif //TETRISS_TETRAMINO_H
