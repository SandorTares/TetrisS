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

enum tetraminoType {TTetramino, ITetramino, OTetramino, LTetramino, lTetramino, STetramino, ZTetramino};
struct tetraminoSet{
    tetraminoType setEntry[TETRAMINO_VARIATIONS];
};

tetraminoSet shuffledSet(tetraminoSet _set);

class TetrisLogicController {

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
    grid_cell getGridCellState(int x, int y);
    void putTetramino();
    void solidifyTetramino();
    void removeTetramino();
public:
    TetrisLogicController(){
        set1 = shuffledSet(set1);
        set2 = shuffledSet(set2);
        currentPiece = randomTetramino();
    }
    void gameFrame();
    Grid currentGrid;
    bool gameOver{false};
    int score{0};
    int completedLines{0};
    tetraminoSet set1{TTetramino, ITetramino, OTetramino, LTetramino, lTetramino, STetramino, ZTetramino};
    tetraminoSet set2{TTetramino, ITetramino, OTetramino, LTetramino, lTetramino, STetramino, ZTetramino};
    int positionInSet{0};
    tetraminoType chooseNextElementSet();
    tetraminoType readNextElementSet(int offset);
};


#endif //TETRISS_TETRISLOGICCONTROLLER_H
