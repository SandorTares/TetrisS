//
// Created by onitn on 11/14/2023.
//

#include "Grid.h"

grid_cell emptyCell()
{
    grid_cell temp{false, false};
    return temp;
}
grid_cell solidCell()
{
    grid_cell temp{false, true};
    return temp;
}

void Grid::setCellState(int _x, int _y, bool _filled, bool _solid, int _color) {
    if (_y>=GRID_HEIGHT || _y<0 || _x<0 || _x >= GRID_WIDTH) return;
    grid_cell *gridCell = &(gridY[_y].gridX[_x]);
    gridCell->filled = _filled;
    gridCell->solid = _solid;
    gridCell->color = _color;
}
void Grid::setCellEmpty(int _x, int _y) {
    setCellState(_x,_y, false, false, 0);
}
void Grid::setRowEmpty(int _y) {
    for (int _x = 0; _x < GRID_WIDTH; ++_x) {
        setCellEmpty(_x,_y);
    }
}
void Grid::setGridEmpty() {
    for (int _y = 0; _y < GRID_HEIGHT; ++_y) {
        setRowEmpty(_y);
    }
}
void Grid::shiftRowsDown(int _starting_y) {

    for (int _y = _starting_y; _y > 0; --_y) {
        copyRow(_y-1, _y);
    }
    setRowEmpty(0);
}
grid_cell Grid::getCellState(int _x, int _y) {
    if (_y>=GRID_HEIGHT || _x<0 || _x >= GRID_WIDTH) return solidCell();
    if (_y<0) return emptyCell();
    return gridY[_y].gridX[_x];
}
void Grid::copyRow(int _from, int _to) {
    gridY[_to] = gridY[_from];
}

void Grid::incrementRowFilledCount(int row) {
    gridY[row].filled+=1;
}

int Grid::emptyFilledRows() {
    int count = 0;
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        if (gridY[i].filled >= GRID_WIDTH) {shiftRowsDown(i);
        count+=1;
        }
    }
    return count;
}
