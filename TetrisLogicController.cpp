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

coordinates zeroVector(){
    coordinates temp{0,0};
    return temp;
}
coordinates rightVector()
{
    coordinates temp{1,0};
    return temp;
}
coordinates leftVector()
{
    coordinates temp{-1,0};
    return temp;
}
coordinates downVector()
{
    coordinates temp{0,1};
    return temp;
}
coordinates upVector()
{
    coordinates temp{0,-1};
    return temp;
}
coordinates oneVector()
{
    coordinates temp{1,1};
    return temp;
}

tetraminoSet shuffleSet(tetraminoSet _set){
    for (int i = 0; i < TETRAMINO_VARIATIONS; ++i) {
        std::swap(_set.setEntry[i], _set.setEntry[(i+rand())%TETRAMINO_VARIATIONS]);
    }
    return _set;
}

bool TetrisLogicController::canMove(coordinates newPositionDelta) {

    bool temp = true;

    for (auto & block : currentPiece.blocks) {
        temp = temp && !getGridCellState(addCoordinates(block.position, addCoordinates(currentPiece.position, newPositionDelta))).solid;
    }
    return temp;
}

grid_cell TetrisLogicController::getGridCellState(coordinates cellPos) {
    return currentGrid.getCellState(cellPos.x,cellPos.y);
}

void TetrisLogicController::setGridCellState(coordinates cellPos, bool filled, bool solid, int color) {
    currentGrid.setCellState(cellPos.x,cellPos.y, filled, solid, color);
}

void TetrisLogicController::setGridCellStateEmpty(coordinates cellPos) {
    setGridCellState(cellPos, false, false, 0);
}

void TetrisLogicController::setGridCellStateFilled(coordinates cellPos) {
    setGridCellState(cellPos, true, false, currentPiece.color);
}

void TetrisLogicController::setGridCellStateSolid(coordinates cellPos) {
    setGridCellState(cellPos, true, true, currentPiece.color);
}

void TetrisLogicController::move(coordinates newPositionDelta) {
    if (canMove(newPositionDelta))
    {
        removeTetramino();
        currentPiece.position = addCoordinates(currentPiece.position, newPositionDelta);
        putTetramino();
    }
}

void TetrisLogicController::moveDown() {
    if (canMove(downVector()))
    {
        move(downVector());
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
        currentGrid.incrementRowFilledCount(block.position.y+currentPiece.position.y);
    }
    scoreMultiplier = currentGrid.emptyFilledRows(); // Score
    completedLines+=scoreMultiplier;
    score+= scoreMultiplier*scoreMultiplier*SINGLE_LINE_SCORE;
    currentPiece = randomTetramino();
}


void TetrisLogicController::rotateClockwise() {
    if(canRotate(true))
    {
        removeTetramino();
        currentPiece.rotateBlocksClockwise();
        putTetramino();
    }
}

void TetrisLogicController::rotateAnticlockwise() {
    if(canRotate(false))
    {
        removeTetramino();
        currentPiece.rotateBlocksAnticlockwise();
        putTetramino();
    }
}

bool TetrisLogicController::isGameOver() {
    return !canMove(zeroVector());
}

void TetrisLogicController::putTetramino() {
    for (auto & block : currentPiece.blocks) {
        setGridCellStateFilled(addCoordinates(block.position, currentPiece.position));
    }
}

void TetrisLogicController::removeTetramino() {
    for (auto & block : currentPiece.blocks) {
        setGridCellStateEmpty(addCoordinates(block.position, currentPiece.position));
    }
}

void TetrisLogicController::solidifyTetramino() {
    for (auto & block : currentPiece.blocks) {
        setGridCellStateSolid(addCoordinates(block.position, currentPiece.position));
    }
}

bool TetrisLogicController::canRotate(bool clockwise) {

    bool temp;
    if (clockwise)
    {
        currentPiece.rotateBlocksClockwise();
        temp = canMove(zeroVector());
        currentPiece.rotateBlocksAnticlockwise();
    }
    else {
        currentPiece.rotateBlocksAnticlockwise();
        temp = canMove(zeroVector());
        currentPiece.rotateBlocksClockwise();
    }

    return temp;
}

tetraminoType TetrisLogicController::chooseNextElementSet() {
    if (positionInSet < TETRAMINO_VARIATIONS) {
        positionInSet++;
        return set1.setEntry[positionInSet - 1];
    } else {
        std::swap(set1, set2);
        positionInSet = (positionInSet % TETRAMINO_VARIATIONS) + 1;
        set2 = shuffleSet(set2);
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
                move(leftVector());
                break;
            case 'd':
            case 'D':
                move(rightVector());
                break;
            case 'w':
            case 'W':
                rotateClockwise();
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
