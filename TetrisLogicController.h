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
    Tetramino randomTetramino();
    bool canMove(int deltaX, int deltaY);
    bool canRotate(bool clockwise);
    void move(int deltaX, int deltaY);
    void moveDown();
    void rotate(bool clockwise);
    void tetraminoPlaced();
    bool isGameOver();
    void putTetramino();
    void solidifyTetramino();
    void removeTetramino();
public:
    TetrisLogicController(){
        currentPiece = randomTetramino();
    }
    void gameFrame();
    Grid currentGrid;
    bool gameOver{false};
    int score{0};
    int completedLines{0};
};


#endif //TETRISS_TETRISLOGICCONTROLLER_H
