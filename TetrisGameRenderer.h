//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRISGAMERENDERER_H
#define TETRISS_TETRISGAMERENDERER_H
#define BLOCK_GRAPHIC_WIDTH 3
#define NUMBER_PREDICTIONS 3
#define BORDERS_SIZE 2
#define GRAPHICS_EMPTY " . "
#define GRAPHICS_CLEAR "   "
#define GRAPHICS_FILLED "[#]"
#include "TetrisLogicController.h"

class TetrisGameRenderer {
    WINDOW *gridWindow;
    WINDOW *scoreWindow;
    WINDOW *nextPieceWindow;
    int posX{0}, posY{0};
public:TetrisGameRenderer(){
        int gameWindowsWidth, gameWindowsHeight,scoreWindowsWidth,scoreWindowsHeight, predictionWindowsHeight, predictionWindowsWidth;
        gameWindowsWidth = GRID_WIDTH * BLOCK_GRAPHIC_WIDTH + BORDERS_SIZE;
        gameWindowsHeight = GRID_HEIGHT + BORDERS_SIZE;
        scoreWindowsWidth = (TETRAMINO_BLOCKS+2) * BLOCK_GRAPHIC_WIDTH + BORDERS_SIZE;;
        scoreWindowsHeight = 5 + BORDERS_SIZE;
        predictionWindowsWidth = scoreWindowsWidth;
        predictionWindowsHeight = BORDERS_SIZE + NUMBER_PREDICTIONS * 3 + 2;//2 Row:\n
        gridWindow = newwin(gameWindowsHeight, gameWindowsWidth, posY, posX+scoreWindowsWidth+4);
        scoreWindow = newwin(scoreWindowsHeight, scoreWindowsWidth, posY,posX);
        nextPieceWindow = newwin(predictionWindowsHeight, predictionWindowsWidth, posY + scoreWindowsHeight+BORDERS_SIZE,posX);
    }
    TetrisLogicController logicController;
    void gameLoop();

    void renderGrid();
    void renderScore();
    void renderNextPiece();
    void destroyWindows();

};


#endif //TETRISS_TETRISGAMERENDERER_H
