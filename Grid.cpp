//
// Created by onitn on 11/14/2023.
//

#include "Grid.h"

cell emptyCell()
{
    return {false, false};

}
cell solidCell()
{
    return {false, true};
}

void Grid::setCellState(int _x, int _y, bool _filled, bool _solid) {
    if (_y>=GRID_HEIGHT || _y<0 || _x<0 || _x >= GRID_WIDTH) return;
    gridRows[_y].gridColumns[_x] = {_filled, _solid};
}
void Grid::setCellEmpty(int _x, int _y) {
    gridRows[_y].gridColumns[_x] = emptyCell();
}
void Grid::setRowEmpty(int _y) {
    for (int _x = 0; _x < GRID_WIDTH; ++_x) {
        setCellEmpty(_x,_y);
    }
}

void Grid::shiftRowsDown(int _starting_y) {

    for (int _y = _starting_y; _y > 0; --_y) {
        gridRows[_y] = gridRows[_y - 1];
    }
    setRowEmpty(0);
}
cell Grid::getCellState(int _x, int _y) {
    if (_y>=GRID_HEIGHT || _x<0 || _x >= GRID_WIDTH) return solidCell();
    if (_y<0) return emptyCell();
    return gridRows[_y].gridColumns[_x];
}

void Grid::incrementRowFilledCount(int row) {
    gridRows[row].filled+=1;
}

int Grid::emptyFilledRows() {
    int count = 0;
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        if (gridRows[i].filled >= GRID_WIDTH) {shiftRowsDown(i);
        count+=1;
        }
    }
    return count;
}