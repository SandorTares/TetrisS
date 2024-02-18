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
                wattron(gridWindow,COLOR_PAIR(logicController.currentGrid.getCellState(x,y).color));
                mvwaddstr(gridWindow, y + 1, x * BLOCK_GRAPHIC_WIDTH + 1, GRAPHICS_FILLED);
                wattroff(gridWindow,COLOR_PAIR(logicController.currentGrid.getCellState(x,y).color));
            }
            else{
                mvwaddstr(gridWindow, y + 1, x * BLOCK_GRAPHIC_WIDTH + 1, GRAPHICS_EMPTY);
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
        renderNextPiece();
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

void TetrisGameRenderer::renderNextPiece() {
    box(nextPieceWindow, 0, 0);
    mvwaddstr(nextPieceWindow,1, 1, "Next:");
    for (int i = 0; i < NUMBER_PREDICTIONS; ++i) {
        switch (logicController.readNextElementSet(i)) {
            case OTetramino:
                mvwprintw(nextPieceWindow,3+i*3  , 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                mvwprintw(nextPieceWindow,3+i*3+1, 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                break;
            case ITetramino:
                mvwprintw(nextPieceWindow,3+i*3  , 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_FILLED);
                mvwprintw(nextPieceWindow,3+i*3+1, 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_CLEAR);
                break;
            case STetramino:
                mvwprintw(nextPieceWindow,3+i*3  , 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR, GRAPHICS_CLEAR);
                mvwprintw(nextPieceWindow,3+i*3+1, 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                break;
            case ZTetramino:
                mvwprintw(nextPieceWindow,3+i*3  , 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                mvwprintw(nextPieceWindow,3+i*3+1, 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR, GRAPHICS_CLEAR);
                break;
            case LTetramino:
                mvwprintw(nextPieceWindow,3+i*3  , 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                mvwprintw(nextPieceWindow,3+i*3+1, 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_CLEAR);
                break;
            case lTetramino:
                mvwprintw(nextPieceWindow,3+i*3  , 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                mvwprintw(nextPieceWindow,3+i*3+1, 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                break;
            case TTetramino:
                mvwprintw(nextPieceWindow,3+i*3  , 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_FILLED, GRAPHICS_CLEAR);
                mvwprintw(nextPieceWindow,3+i*3+1, 1, "%s%s%s%s%s", GRAPHICS_CLEAR, GRAPHICS_CLEAR, GRAPHICS_FILLED, GRAPHICS_CLEAR, GRAPHICS_CLEAR);
                break;
            default:
                break;
        }
    }
    wrefresh(nextPieceWindow);
}

void TetrisGameRenderer::destroyWindows() {
        wclear(gridWindow);
        wrefresh(gridWindow);
        delwin(gridWindow);
        wclear(scoreWindow);
        wrefresh(scoreWindow);
        delwin(scoreWindow);
        wclear(nextPieceWindow);
        wrefresh(nextPieceWindow);
        delwin(nextPieceWindow);
}
