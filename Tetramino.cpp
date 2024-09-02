#include "Tetramino.h"

using namespace std;
//Rotates the given x and y cordinates around (0,0) by 90 degrees
void doCoordinateRotation(int& x, int& y, bool clockwise)
{
    if (clockwise){
        int tmp=-x;
        x=y;
        y=tmp;
    }
    else {
        int tmp=-y;
        y=x;
        x=tmp;
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
    if(n>=TETRAMINO_BLOCKS || n<0){
        return blocks[0];
    }else{
        return blocks[n];
    }
}

//Returns tetramino color
int Tetramino::getColor() {
    return color;
}

//Changes the position of the tetramino origin
void Tetramino::changePos(int deltaX, int deltaY) {
        x=x+deltaX;
        y=y+deltaY;
}

