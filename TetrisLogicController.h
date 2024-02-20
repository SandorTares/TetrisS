//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRISLOGICCONTROLLER_H
#define TETRISS_TETRISLOGICCONTROLLER_H
#define TETRAMINO_VARIATIONS 7
#define SINGLE_LINE_SCORE 10
#define LEFT_VECTOR -1,0
#define RIGHT_VECTOR 1,0
#define DOWN_VECTOR 0,1
#define ZERO_VECTOR 0,0
#include "Tetramino.h"
#include "Grid.h"
#include "iostream"
#include "ncurses/ncurses.h"
#include "cmath"

class TetrisLogicController {
protected:
    Tetramino currentPiece;
    Tetramino randomTetramino();
    bool canMove(int deltaX, int deltaY);
    bool canRotate(bool clockwise);
    void move(int deltaX, int deltaY);
    void moveDown();
    void rotate(bool clockwise);
    void setGridCellState(int x, int y, bool filled, bool solid, int color);
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
