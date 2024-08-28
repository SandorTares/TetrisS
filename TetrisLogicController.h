//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRISLOGICCONTROLLER_H
#define TETRISS_TETRISLOGICCONTROLLER_H
#include "ncurses/ncurses.h"
#include "GlobalVariables.h"
#include "Grid.h"
#include "Tetramino.h"

class TetrisLogicController {
protected:
    Tetramino currentPiece;
    Tetramino nextPiece;
    int score{0};
    int completedRows{0};
    bool gameOver{false};
    void chooseNextTetramino();
    void changeTetramino();
    bool canMove(int deltaX, int deltaY);
    bool canRotate(bool clockwise);
    void doMove(int deltaX, int deltaY);
    void moveDown();
    void doRotation(bool clockwise);
    void doTetraminoPlacement();
    void makeTetraminoVisible();
    void makeTetraminoStatic();
    void eraseTetramino();

public:
    TetrisLogicController(){
        chooseNextTetramino();
        changeTetramino();
    }
    void gameFrame();
    Grid currentGrid;
    int getScore();
    Tetramino getPrediction();
    int getCompletedRows();
    bool isGameOver();
};


#endif //TETRISS_TETRISLOGICCONTROLLER_H
