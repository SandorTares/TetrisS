//
// Created by onitn on 11/14/2023.
//

#include "Tetramino.h"
coordinates rotateCoordinates(coordinates _coordinates, coordinatesDouble origin, bool clockwise)
{
    coordinates rotatedCoords{};
    if (clockwise)
    {
    rotatedCoords.x = (int) ((double)(_coordinates.y-origin.y)+origin.x);
    rotatedCoords.y = (int) ((double)-(_coordinates.x-origin.x)+origin.y);
    } else
    {
        rotatedCoords.x = (int) ((double) -(_coordinates.y-origin.y)+origin.x);
        rotatedCoords.y = (int) ((double) (_coordinates.x-origin.x)+origin.y);
    }
    return rotatedCoords;
}

coordinates addCoordinates(coordinates c1, coordinates c2)
{
    coordinates temp{c1.x+c2.x,c1.y+c2.y};
    return temp;
}
void Tetramino::rotateBlocksClockwise() {
    for (auto & block : blocks) {
        block.position = rotateCoordinates(block.position, center, true);
    }
}

void Tetramino::rotateBlocksAnticlockwise() {
    for (auto & block : blocks) {
        block.position = rotateCoordinates(block.position, center, false);
    }
}