//
// Created by onitn on 11/14/2023.
//

#include "TetrisLogicController.h"

Tetramino TetrisLogicController::randomTetramino() {
    int spawnX = GRID_WIDTH / 2, spawnY = -1;
    switch (rand()%TETRAMINO_VARIATIONS) {

        case 0:
            return TetraminoO(spawnX, spawnY);
        case 1:
            return TetraminoI(spawnX, spawnY);
        case 2:
            return TetraminoS(spawnX, spawnY);
        case 3:
            return TetraminoZ(spawnX, spawnY);
        case 4:
            return TetraminoL(spawnX, spawnY);
        case 5:
            return Tetraminol(spawnX, spawnY);
        case 6:
            return TetraminoT(spawnX, spawnY);
        default:
            return TetraminoO(spawnX, spawnY);

    }
}

bool TetrisLogicController::canMove(int deltaX, int deltaY) {
    bool temp = true;

    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        temp = temp && !currentGrid.getCellState(currentPiece.getX() + deltaX + currentPiece.getBlock(i).x, currentPiece.getY() + deltaY + currentPiece.getBlock(i).y).solid;
    }
    return temp;
}

void TetrisLogicController::setGridCellState(int x, int y, bool filled, bool solid, int color = 0) {
    currentGrid.setCellState(x, y, filled, solid, color);
}

void TetrisLogicController::move(int deltaX, int deltaY) {
    if (canMove(deltaX, deltaY))
    {
        removeTetramino();
        currentPiece.setXY(deltaX, deltaY, true);
        putTetramino();
    }
}

void TetrisLogicController::moveDown() {
    if (canMove(DOWN_VECTOR))
    {
        move(DOWN_VECTOR);
    } else
    {
        solidifyTetramino();
        tetraminoPlaced();
        gameOver = isGameOver();
    }
}

void TetrisLogicController::tetraminoPlaced() {
    int scoreMultiplier;
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.incrementRowFilledCount(currentPiece.getBlock(i).y+currentPiece.getY());
    }
    scoreMultiplier = currentGrid.emptyFilledRows(); // Score
    completedLines+=scoreMultiplier;
    score+= scoreMultiplier*scoreMultiplier*SINGLE_LINE_SCORE;
    currentPiece = randomTetramino();
}


void TetrisLogicController::rotate(bool clockwise) {
    if(canRotate(clockwise))
    {
        removeTetramino();
        currentPiece.rotateBlocks(clockwise);
        putTetramino();
    }
}

bool TetrisLogicController::isGameOver() {
    return !canMove(0,0);
}

void TetrisLogicController::putTetramino() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        setGridCellState(currentPiece.getX() + currentPiece.getBlock(i).x , currentPiece.getY() + currentPiece.getBlock(i).y, true, false, currentPiece.getColor());
    }
}

void TetrisLogicController::removeTetramino() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        setGridCellState(currentPiece.getX() + currentPiece.getBlock(i).x , currentPiece.getY() + currentPiece.getBlock(i).y, false, false);
    }
}

void TetrisLogicController::solidifyTetramino() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        setGridCellState(currentPiece.getX() + currentPiece.getBlock(i).x , currentPiece.getY() + currentPiece.getBlock(i).y, true, true, currentPiece.getColor());
    }
}

bool TetrisLogicController::canRotate(bool clockwise) {

    bool temp;
        currentPiece.rotateBlocks(clockwise);
        temp = canMove(ZERO_VECTOR);
        currentPiece.rotateBlocks(!clockwise);
    return temp;
}

void TetrisLogicController::gameFrame() {

        char c = getch();

        switch (c) {
            case 'a':
            case 'A':
                move(LEFT_VECTOR);
                break;
            case 'd':
            case 'D':
                move(RIGHT_VECTOR);
                break;
            case 'w':
            case 'W':
                rotate(true);
                break;
            case 's':
            case 'S':
                moveDown();
                break;
            default:
                break;
        }
            moveDown();
}
