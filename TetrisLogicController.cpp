//
// Created by onitn on 11/14/2023.
//

#include "TetrisLogicController.h"

Tetramino TetrisLogicController::randomTetramino() {
    int spawnX = GRID_WIDTH / 2, spawnY = -1;
    switch (chooseNextElementSet()) {

        case OTetramino:
            return TetraminoO(spawnX, spawnY);
        case ITetramino:
            return TetraminoI(spawnX, spawnY);
        case STetramino:
            return TetraminoS(spawnX, spawnY);
        case ZTetramino:
            return TetraminoZ(spawnX, spawnY);
        case LTetramino:
            return TetraminoL(spawnX, spawnY);
        case lTetramino:
            return Tetraminol(spawnX, spawnY);
        case TTetramino:
            return TetraminoT(spawnX, spawnY);
        default:
            return TetraminoO(spawnX, spawnY);

    }
}

tetraminoSet shuffledSet(tetraminoSet _set){
    for (int i = 0; i < TETRAMINO_VARIATIONS; ++i) {
        std::swap(_set.setEntry[i], _set.setEntry[(i+rand())%TETRAMINO_VARIATIONS]);
    }
    return _set;
}

bool TetrisLogicController::canMove(int deltaX, int deltaY) {
    bool temp = true;

    for (auto & block : currentPiece.blocks) {
        temp = temp && !getGridCellState(currentPiece.x + deltaX + block.x, currentPiece.y + deltaY + block.y).solid;
    }
    return temp;
}

grid_cell TetrisLogicController::getGridCellState(int x, int y) {
    return currentGrid.getCellState(x, y);
}

void TetrisLogicController::setGridCellState(int x, int y, bool filled, bool solid, int color = 0) {
    currentGrid.setCellState(x, y, filled, solid, color);
}

void TetrisLogicController::move(int deltaX, int deltaY) {
    if (canMove(deltaX, deltaY))
    {
        removeTetramino();
        currentPiece.x += deltaX;
        currentPiece.y += deltaY;
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
    for (auto & block : currentPiece.blocks) {
        currentGrid.incrementRowFilledCount(block.y+currentPiece.y);
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
    for (auto & block : currentPiece.blocks) {
        setGridCellState(currentPiece.x + block.x , currentPiece.y + block.y, true, false, currentPiece.color);
    }
}

void TetrisLogicController::removeTetramino() {
    for (auto & block : currentPiece.blocks) {
        setGridCellState(currentPiece.x + block.x , currentPiece.y + block.y, false, false);
    }
}

void TetrisLogicController::solidifyTetramino() {
    for (auto & block : currentPiece.blocks) {
        setGridCellState(currentPiece.x + block.x , currentPiece.y + block.y, true, true, currentPiece.color);
    }
}

bool TetrisLogicController::canRotate(bool clockwise) {

    bool temp;
        currentPiece.rotateBlocks(clockwise);
        temp = canMove(ZERO_VECTOR);
        currentPiece.rotateBlocks(!clockwise);
    return temp;
}

tetraminoType TetrisLogicController::chooseNextElementSet() {
    if (positionInSet < TETRAMINO_VARIATIONS) {
        positionInSet++;
        return set1.setEntry[positionInSet - 1];
    } else {
        std::swap(set1, set2);
        positionInSet = (positionInSet % TETRAMINO_VARIATIONS) + 1;
        set2 = shuffledSet(set2);
        return set1.setEntry[positionInSet - 1];
    }
}

tetraminoType TetrisLogicController::readNextElementSet(int offset) {
    offset = offset%(TETRAMINO_VARIATIONS*2);
    if (positionInSet+offset < TETRAMINO_VARIATIONS) {
        return set1.setEntry[positionInSet+offset];
    } else {
        return set2.setEntry[ (positionInSet+offset)%TETRAMINO_VARIATIONS];
    }
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
