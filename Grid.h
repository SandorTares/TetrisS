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
    cell gridColumns[GRID_WIDTH]{}; //X axis
    int filled {0};
};

cell emptyCell();
cell solidCell();

class Grid {

protected:
    cell_row gridRows[GRID_HEIGHT]{}; //Y axis
    void setCellEmpty(int _x, int _y);
    void setRowEmpty(int _y);
    void shiftRowsDown(int _starting_y);

public:
    cell getCellState(int _x, int _y);
    void setCellState(int _x, int _y, bool _filled, bool _solid);
    void incrementRowFilledCount(int row);
    int emptyFilledRows();
    Grid() = default;
};


#endif //TETRISS_GRID_H
