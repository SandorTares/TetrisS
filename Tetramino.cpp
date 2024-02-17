//
// Created by onitn on 11/14/2023.
//

#include "Tetramino.h"

void swap_int(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void rotateCoordinates(int& x, int& y, bool clockwise)
{
    if (clockwise)
    {
        swap_int(x,y);
        y=-y;
    }
    else
    {
        swap_int(x,y);
        x=-x;
    }
}

void Tetramino::rotateBlocks(bool clockwise) {
    for (auto & block : blocks) {
        rotateCoordinates(block.x, block.y, clockwise);
    }
}