//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_GRID_H
#define TETRISS_GRID_H
#define GRID_WIDTH 10
#define GRID_HEIGHT 20


struct grid_cell{
    bool filled{false}, solid{false};
    int color{0};
};

struct grid_row{
    grid_cell gridX[GRID_WIDTH]{};
    int filled {false};
};

grid_cell emptyCell();
grid_cell solidCell();

class Grid {

protected:
    grid_row gridY[GRID_HEIGHT]{};
    void setCellEmpty(int _x, int _y);
    void setRowEmpty(int _y);
    void shiftRowsDown(int _starting_y);

public:
    grid_cell getCellState(int _x, int _y);
    void setCellState(int _x, int _y, bool _filled, bool _solid, int _color);
    void incrementRowFilledCount(int row);
    int emptyFilledRows();
    Grid() = default;
};


#endif //TETRISS_GRID_H
