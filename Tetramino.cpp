//
// Created by onitn on 11/14/2023.
//

#include "Tetramino.h"
coordinates rotateCoordinates(coordinates _coordinates, bool clockwise)
{
    if (clockwise)
    {
        return {_coordinates.y,-_coordinates.x};
    }
    else
    {
        return {-_coordinates.y,_coordinates.x};
    }
}

coordinates addCoordinates(coordinates c1, coordinates c2)
{
    return {c1.x+c2.x,c1.y+c2.y};
}
void Tetramino::rotateBlocksClockwise() {
    for (auto & block : blocks) {
        block.position = rotateCoordinates(block.position, true);
    }
}

void Tetramino::rotateBlocksAnticlockwise() {
    for (auto & block : blocks) {
        block.position = rotateCoordinates(block.position, false);
    }
}