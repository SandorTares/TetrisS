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
        temp = temp && !currentGrid.getCellState(currentPiece.getBlockPos(i).x + deltaX, currentPiece.getBlockPos(i).y + deltaY).solid;
    }
    return temp;
}

void TetrisLogicController::move(int deltaX, int deltaY) {
    if (canMove(deltaX, deltaY))
    {
        removeTetramino();
        currentPiece.changePos(deltaX, deltaY);
        putTetramino();
    }
}

void TetrisLogicController::moveDown() {
    if (canMove(VECTOR_DOWN))
    {
        move(VECTOR_DOWN);
    } else
    {
        solidifyTetramino();
        tetraminoPlaced();
        gameOver = isGameOver();
    }
}

void TetrisLogicController::tetraminoPlaced() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.incrementRowFilledCount(currentPiece.getBlockPos(i).y);
    }
    int filledLines = currentGrid.emptyFilledRows(); // Score
    completedLines+=filledLines;
    score+= filledLines * filledLines * SCORE_SINGLE_LINE;
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
        currentGrid.setCellState(currentPiece.getBlockPos(i).x ,currentPiece.getBlockPos(i).y, true, false);
    }
}

void TetrisLogicController::removeTetramino() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.setCellState(currentPiece.getBlockPos(i).x ,currentPiece.getBlockPos(i).y, false, false);
    }
}

void TetrisLogicController::solidifyTetramino() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.setCellState(currentPiece.getBlockPos(i).x ,currentPiece.getBlockPos(i).y, true, true);
    }
}

bool TetrisLogicController::canRotate(bool clockwise) {

    bool temp;
        currentPiece.rotateBlocks(clockwise);
        temp = canMove(VECTOR_ZERO);
        currentPiece.rotateBlocks(!clockwise);
    return temp;
}

void TetrisLogicController::gameFrame() {

        char c = getch();

        switch (c) {
            case 'a':
            case 'A':
                move(VECTOR_LEFT);
                break;
            case 'd':
            case 'D':
                move(VECTOR_RIGHT);
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
