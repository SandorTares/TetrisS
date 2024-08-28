//
// Created by onitn on 11/14/2023.
//

#include "TetrisGameRenderer.h"

//Starts the game screen drawing and executes the game logic using TetrisLogicController
int TetrisGameRenderer::doGameLoop() {
    //Clear and refresh screen to prepare it for drawing the game
    clear();
    refresh();
    while (!logicController.isGameOver())
    {
        renderGrid(); //Render the game grid
        renderScore(); //Render the game score
        renderPrediction();//Render the next piece window
        logicController.gameFrame();
    }
    destroyWindows(); //After game loop destroy the game windows
    return logicController.getScore();
}

//Draws the game grid
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

//Draws the current game score
void TetrisGameRenderer::renderScore() {
    box(scoreWindow, 0, 0);
    mvwaddstr(scoreWindow,1, 1, "Score:");
    mvwprintw(scoreWindow,2, 1, "%d", logicController.getScore());
    mvwaddstr(scoreWindow,4, 1, "Rows:");
    mvwprintw(scoreWindow,5, 1, "%d", logicController.getCompletedRows());
    wrefresh(scoreWindow);
}

//Draws the next tetramino piece
void TetrisGameRenderer::renderPrediction() {
    wclear(predictionWindow);
    box(predictionWindow, 0, 0);
    int drawX = 1, drawY = 1;
    mvwaddstr(predictionWindow,drawY, drawX, "Next:");
    drawY+=3;
    drawX+=1;
    Tetramino prediction = logicController.getPrediction();

    for (int i = 0; i < TETRAMINO_BLOCKS; ++i) {
        block currentBlock = prediction.getBlockPosRelative(i);
        mvwaddstr(predictionWindow, drawY+currentBlock.y, (drawX+currentBlock.x)*GRAPHICS_BLOCK_WIDTH, GRAPHICS_FILLED);
    }

    wrefresh(predictionWindow);
}

//Clears memory used by the windows to avoid leaks
void TetrisGameRenderer::destroyWindows() {
        delwin(gridWindow);
        delwin(scoreWindow);
        delwin(predictionWindow);
        clear();
}
