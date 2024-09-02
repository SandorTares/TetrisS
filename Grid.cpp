#include "Grid.h"

//Returns the equivalent of an empty cell
cell emptyCell() {
    return {false, false};

}

//Returns the equivalent of a solid cell, used for the grid walls and floor
cell solidCell() {
    return {false, true};
}

//Sets the state of desired grid cell
void Grid::setCellState(int cellX, int cellY, bool cellFilled, bool cellSolid, int cellColor) {
    if (cellX < GRID_WIDTH && cellX >= 0 && cellY < GRID_HEIGHT && cellY >= 0) {
        gridAxisY[cellY].gridAxisX[cellX] = {cellFilled, cellSolid, cellColor};
    }
}

//Empties the desired grid cell
void Grid::setCellEmpty(int cellX, int cellY) {
    if (cellX<GRID_WIDTH && cellX>=0 && cellY<GRID_HEIGHT && cellY>=0)
        gridAxisY[cellY].gridAxisX[cellX]= emptyCell();
}

//Empties the desired grid row
void Grid::setRowEmpty(int rowY) {
    for (int _x = 0; _x < GRID_WIDTH; ++_x) {
        setCellEmpty(_x, rowY);
    }
    gridAxisY[rowY].filled = 0;
}

//Shifts all the rows down starting from the indicated y coordinate, used when eliminating filled rows
void Grid::shiftRowsDown(int startingRowY) {

    for (int _y = startingRowY; _y > 0; --_y) {
        gridAxisY[_y] = gridAxisY[_y - 1];
    }
    setRowEmpty(0);
}

//Returns the state of the desired grid cell
cell Grid::getCellState(int cellX, int cellY) {
    if (cellY<0)
        return emptyCell();
    else if (cellY>=GRID_HEIGHT || (cellY>0 && (cellX<0 || cellX>=GRID_WIDTH)))
        return solidCell();
    else
        return gridAxisY[cellY].gridAxisX[cellX];
}

//Changes how filled a rowY is
void Grid::incrementRowFilledCount(int rowY) {
    if (rowY<GRID_HEIGHT && rowY>=0)
        gridAxisY[rowY].filled+=1;
}

//Empties all filled rows
int Grid::emptyFilledRows() {
    int num_full = 0;
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        if (gridAxisY[i].filled >= GRID_WIDTH) {
            shiftRowsDown(i);
            num_full+=1;
        }
    }
    return num_full;
}