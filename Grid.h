//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_GRID_H
#define TETRISS_GRID_H
#include "GlobalVariables.h"


struct cell{
    bool filled{false}, solid{false};
};

struct cell_row{
    cell gridAxisX[GRID_WIDTH]{}; //X axis
    int filled {0};
};

cell emptyCell();
cell solidCell();

class Grid {

protected:
    cell_row gridAxisY[GRID_HEIGHT]{}; //Y axis
    void setCellEmpty(int cellX, int cellY);
    void setRowEmpty(int rowY);
    void shiftRowsDown(int startingRowY);

public:
    cell getCellState(int cellX, int cellY);
    void setCellState(int cellX, int cellY, bool cellFilled, bool cellSolid);
    void incrementRowFilledCount(int row);
    int emptyFilledRows();
    Grid() = default;
};


#endif //TETRISS_GRID_H
