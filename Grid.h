//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_GRID_H
#define TETRISS_GRID_H
#define GRID_WIDTH 10
#define GRID_HEIGHT 20
struct grid_cell{
    bool filled, solid;
    int color;
};

struct grid_row{
    grid_cell gridX[GRID_WIDTH];
    int filled;
};

grid_cell emptyCell();
grid_cell solidCell();

class Grid {
    grid_row gridY[GRID_HEIGHT]{};
    void setCellEmpty(int _x, int _y);
    void setRowEmpty(int _y);
    void setGridEmpty();
    void copyRow(int _from, int _to);
    void shiftRowsDown(int _starting_y);
    public:Grid()
    {
        setGridEmpty();
    }
    grid_cell getCellState(int _x, int _y);
    void setCellState(int _x, int _y, bool _filled, bool _solid, int _color);
    void incrementRowFilledCount(int row);
    int emptyFilledRows();
};


#endif //TETRISS_GRID_H
