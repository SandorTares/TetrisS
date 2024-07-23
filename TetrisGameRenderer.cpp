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
        renderPrediction();
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

void TetrisGameRenderer::renderPrediction() {
    box(predictionWindow, 0, 0);
    int drawX = 1, drawY = 1;
    mvwaddstr(predictionWindow,drawY, drawX, "Next:");
    drawY+=2;
    drawX+=5;
    switch (logicController.nextTetramino) {
        case TETRAMINO_TYPE_O:
            mvwaddstr(predictionWindow,drawY,drawX,   "   [#][#]   ");
            mvwaddstr(predictionWindow,drawY+1,drawX, "   [#][#]   ");
            break;
        case TETRAMINO_TYPE_I:
            mvwaddstr(predictionWindow,drawY,drawX,   "[#][#][#][#]");
            mvwaddstr(predictionWindow,drawY+1,drawX, "            ");
            break;
        case TETRAMINO_TYPE_S:
            mvwaddstr(predictionWindow,drawY,drawX,   "   [#][#]   ");
            mvwaddstr(predictionWindow,drawY+1,drawX, "[#][#]      ");
            break;
        case TETRAMINO_TYPE_Z:
            mvwaddstr(predictionWindow,drawY,drawX,   "[#][#]      ");
            mvwaddstr(predictionWindow,drawY+1,drawX, "   [#][#]   ");
            break;
        case TETRAMINO_TYPE_L:
            mvwaddstr(predictionWindow,drawY,drawX,   "[#][#][#]   ");
            mvwaddstr(predictionWindow,drawY+1,drawX, "[#]         ");
            break;
        case TETRAMINO_TYPE_l:
            mvwaddstr(predictionWindow,drawY,drawX,   "[#][#][#]   ");
            mvwaddstr(predictionWindow,drawY+1,drawX, "      [#]   ");
            break;
        case TETRAMINO_TYPE_T:
            mvwaddstr(predictionWindow,drawY,drawX,   "[#][#][#]   ");
            mvwaddstr(predictionWindow,drawY+1,drawX, "   [#]      ");
            break;
        default:
            mvwaddstr(predictionWindow,drawY,drawX,   "[#][#]      ");
            mvwaddstr(predictionWindow,drawY+1,drawX, "[#][#]      ");
            break;
    }

    wrefresh(predictionWindow);
}


void TetrisGameRenderer::destroyWindows() {
        wclear(gridWindow);
        wrefresh(gridWindow);
        delwin(gridWindow);
        wclear(scoreWindow);
        wrefresh(scoreWindow);
        delwin(scoreWindow);
        wclear(predictionWindow);
        wrefresh(predictionWindow);
        delwin(predictionWindow);

}
