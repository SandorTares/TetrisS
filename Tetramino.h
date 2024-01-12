//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRAMINO_H
#define TETRISS_TETRAMINO_H
#define TETRAMINO_BLOCKS 4
struct coordinates{
    int x,y;
};
struct coordinatesDouble{
    double x,y;
};

struct block{
    coordinates position;
};

coordinates addCoordinates(coordinates c1, coordinates c2);
coordinates zeroVector();
coordinates oneVector();
coordinates upVector();
coordinates downVector();
coordinates rightVector();
coordinates leftVector();

class Tetramino {

    protected:
    //coordinatesDouble precisePosition{}; ///Continue here
    Tetramino(int x, int y)
    {
        position.x = x;
        position.y = y;
        color = 0;
    }
public:
    void rotateBlocksClockwise();
    void rotateBlocksAnticlockwise();
    int color;

public:
    coordinates position{};
    Tetramino()
    {
        position.x = 0;
        position.y = 0;
        center.x=0;
        center.y=0;
        color = 0;
    }
    coordinatesDouble center{};
    block blocks[TETRAMINO_BLOCKS]{};
};

class TetraminoI:public Tetramino
{
    public:TetraminoI(int x, int y) : Tetramino(x, y) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {2, 0};
        center.x = 0.5;
        center.y = 0.5;
        color = 5;
    }
};

class TetraminoO:public Tetramino
{
    public:TetraminoO(int x, int y) : Tetramino(x, y) {
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
        center.x = 0.5;
        center.y = 0.5;
        color = 3;
    }
};
class TetraminoS:public Tetramino
{
public:TetraminoS(int x, int y) : Tetramino(x, y) {
        blocks[0] = {0, 0};
        blocks[1] = {1,0};
        blocks[2] = {0, 1};
        blocks[3] = {-1, 1};
        center.x = 0;
        center.y = 1;
        color = 4;
    }

};

class TetraminoZ:public Tetramino
{
public:TetraminoZ(int x, int y) : Tetramino(x, y) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {0, 1};
        blocks[3] = {1, 1};
        center.x = 0;
        center.y = 1;
        color = 1;
    }

};

class TetraminoL:public Tetramino
{
public:TetraminoL(int x, int y) : Tetramino(x, y) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {-1, 1};
        center.x = 0;
        center.y = 0;
        color = 2;
    }
};
class Tetraminol:public Tetramino
{
public:Tetraminol(int x, int y) : Tetramino(x, y) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {1, 1};
        center.x = 0;
        center.y = 0;
        color = 6;
    }
};

class TetraminoT:public Tetramino
{
public:TetraminoT(int x, int y) : Tetramino(x, y) {
        blocks[0] = {-1, 0};
        blocks[1] = {0,0};
        blocks[2] = {1, 0};
        blocks[3] = {0, 1};
        center.x = 0;
        center.y = 0;
        color = 7;
    }
};
#endif //TETRISS_TETRAMINO_H
