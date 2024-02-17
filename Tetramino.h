//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRAMINO_H
#define TETRISS_TETRAMINO_H
#define TETRAMINO_BLOCKS 4
#define RED 1
#define WHITE 2
#define YELLOW 3
#define GREEN 4
#define CYAN 5
#define BLUE 6
#define MAGENTA 7

struct block{
    int x;
    int y;
};

class Tetramino {

public:
    int x,y;
    int color;
    block blocks[TETRAMINO_BLOCKS]{};
    void rotateBlocks(bool clockwise);
    explicit Tetramino(int _x = 0, int _y = 0, int _color = WHITE)
    {
        x = _x;
        y = _y;
        color = _color;
    }

};

class TetraminoI:public Tetramino
{
    public:TetraminoI(int x, int y) : Tetramino(x, y, CYAN) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {2, 0};
    }
};

class TetraminoO:public Tetramino
{
    public:TetraminoO(int x, int y) : Tetramino(x, y,YELLOW) {
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
    }
};
class TetraminoS:public Tetramino
{
public:TetraminoS(int x, int y) : Tetramino(x, y,GREEN) {
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {-1, 1};
    }

};

class TetraminoZ:public Tetramino
{
public:TetraminoZ(int x, int y) : Tetramino(x, y,RED) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
    }

};

class TetraminoL:public Tetramino
{
public:TetraminoL(int x, int y) : Tetramino(x, y,WHITE) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {-1, 1};
    }
};
class Tetraminol:public Tetramino
{
public:Tetraminol(int x, int y) : Tetramino(x, y,BLUE) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {1, 1};
    }
};

class TetraminoT:public Tetramino
{
public:TetraminoT(int x, int y) : Tetramino(x, y,MAGENTA) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {0, 1};
    }
};
#endif //TETRISS_TETRAMINO_H
