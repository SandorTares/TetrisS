#ifndef TETRISS_GRID_H
#define TETRISS_GRID_H
#include "GlobalVariables.h"


struct cell{
    bool filled{false}, solid{false};
    int color = GRAPHICS_WHITE;
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
    void setCellState(int cellX, int cellY, bool cellFilled, bool cellSolid, int cellColor);
    void incrementRowFilledCount(int rowY);
    int emptyFilledRows();
    Grid() = default;
};


#endif //TETRISS_GRID_H
