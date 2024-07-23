//
// Created by onitn on 11/14/2023.
//

#include "TetrisGameRenderer.h"

void TetrisGameRenderer::renderGrid() {
    box(gridWindow, 0, 0);

    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (logicController.currentGrid.getCellState(x,y).filled)
            {
                mvwaddstr(gridWindow, y + 1, x * GRAPHICS_BLOCK_WIDTH + 1, GRAPHICS_FILLED);
            }
            else{
                mvwaddstr(gridWindow, y + 1, x * GRAPHICS_BLOCK_WIDTH + 1, GRAPHICS_EMPTY);
            }
        }
    }
    wrefresh(gridWindow);
}

void TetrisGameRenderer::gameLoop() {
    while (!logicController.gameOver)
    {
        logicController.gameFrame();
        refresh();
        renderGrid();
        renderScore();
    }
}

void TetrisGameRenderer::renderScore() {
    box(scoreWindow, 0, 0);
    mvwaddstr(scoreWindow,1, 1, "Score:");
    mvwprintw(scoreWindow,2, 1, "%d", logicController.score);
    mvwaddstr(scoreWindow,4, 1, "Rows:");
    mvwprintw(scoreWindow,5, 1, "%d", logicController.completedLines);
    wrefresh(scoreWindow);
}

void TetrisGameRenderer::destroyWindows() {
        wclear(gridWindow);
        wrefresh(gridWindow);
        delwin(gridWindow);
        wclear(scoreWindow);
        wrefresh(scoreWindow);
        delwin(scoreWindow);
}
