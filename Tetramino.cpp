//
// Created by onitn on 11/14/2023.
//

#include "Tetramino.h"

using namespace std;
//Rotates the given x and y cordinates around (0,0) by 90 degrees
void doCoordinateRotation(int& x, int& y, bool clockwise)
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

// To rotate the blocks in the desired direction, we simply rotate each set of coordinates
void Tetramino::doBlocksRotation(bool clockwise) {
    for (auto & block : blocks) {
        doCoordinateRotation(block.x, block.y, clockwise);
    }
}

//Returns the real coordinates of the n-th block
block Tetramino::getBlockPos(int n) {
    return {blocks[n].x+x, blocks[n].y+y};
}

//Returns the coordinates relative to the tetramino origin for the n-th block
block Tetramino::getBlockPosRelative(int n) {
    return {blocks[n].x, blocks[n].y};
}

//Changes the position of the tetramino origin
void Tetramino::changePos(int deltaX, int deltaY) {
        x+=deltaX;
        y+=deltaY;
}

//Returns tetramino color
int Tetramino::getColor() {
    return color;
}
