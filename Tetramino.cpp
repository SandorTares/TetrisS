//
// Created by onitn on 11/14/2023.
//

#include "Tetramino.h"

using namespace std;

void rotateCoordinates(int& x, int& y, bool clockwise) //Rotating the given x and y cordinates around (0,0) by 90 degrees, clockwise if clockwise is true, anticlockwise otherwise
{
    if (clockwise)
    {
        swap(x,y);
        y=-y;
    }
    else
    {
        swap(x,y);
        x=-x;
    }
}

void Tetramino::rotateBlocks(bool clockwise) {// To rotate the blocks in the desired direction, we simply rotate their coordinates
    for (auto & block : blocks) {
        rotateCoordinates(block.x, block.y, clockwise);
    }
}

int Tetramino::getX() {
    return x;
}

int Tetramino::getY() {
    return y;
}

int Tetramino::getColor() {
    return color;
}

block Tetramino::getBlock(int n) {
    return blocks[n];
}

void Tetramino::setXY(int newX, int newY, bool relative) {
    if (relative){
        x+=newX;
        y+=newY;
    } else
    {
        x=newX;
        y=newY;
    }
}
