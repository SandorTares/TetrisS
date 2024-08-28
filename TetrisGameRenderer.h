//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRISGAMERENDERER_H
#define TETRISS_TETRISGAMERENDERER_H

#include "TetrisLogicController.h"
class TetrisGameRenderer {
protected:
    WINDOW *gridWindow;
    WINDOW *scoreWindow;
    WINDOW *predictionWindow;
    int posX{0}, posY{0};
public:
    TetrisLogicController logicController;
    int doGameLoop();
    TetrisGameRenderer(){
        int gridWindowWidth, gridWindowHeight,scoreWindowWidth,scoreWindowHeight, predictionWindowHeight, predictionWindowWidth;
        scoreWindowWidth = (TETRAMINO_BLOCKS + 2) * GRAPHICS_BLOCK_WIDTH + GRAPHICS_BORDERS_SIZE;
        scoreWindowHeight = 5 + GRAPHICS_BORDERS_SIZE;
        gridWindowWidth = GRID_WIDTH * GRAPHICS_BLOCK_WIDTH + GRAPHICS_BORDERS_SIZE;
        gridWindowHeight = GRID_HEIGHT + GRAPHICS_BORDERS_SIZE;
        predictionWindowWidth = (TETRAMINO_BLOCKS + 2) * GRAPHICS_BLOCK_WIDTH + GRAPHICS_BORDERS_SIZE;
        predictionWindowHeight = 5 + GRAPHICS_BORDERS_SIZE;
        scoreWindow = newwin(scoreWindowHeight, scoreWindowWidth, posY, posX);
        gridWindow = newwin(gridWindowHeight, gridWindowWidth, posY, posX + scoreWindowWidth + 4);
        predictionWindow = newwin(predictionWindowHeight, predictionWindowWidth, posY + scoreWindowHeight + 2, posX);
        logicController = TetrisLogicController();
    }



    void renderGrid();
    void renderScore();
    void renderPrediction();
    void destroyWindows();
};


#endif //TETRISS_TETRISGAMERENDERER_H
