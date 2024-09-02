#include "TetrisLogicController.h"

//Chooses the next tetramino that will be used
void TetrisLogicController::chooseNextTetramino() {

    int spawnX = GRID_WIDTH / 2, spawnY = -1;
    int temp = rand()%TETRAMINO_VARIATIONS;
    switch (temp) {

        case TETRAMINO_TYPE_O:
            nextPiece = TetraminoO(spawnX, spawnY);
            break;
        case TETRAMINO_TYPE_I:
            nextPiece = TetraminoI(spawnX, spawnY);
            break;
        case TETRAMINO_TYPE_S:
            nextPiece = TetraminoS(spawnX, spawnY);
            break;
        case TETRAMINO_TYPE_Z:
            nextPiece = TetraminoZ(spawnX, spawnY);
            break;
        case TETRAMINO_TYPE_L:
            nextPiece = TetraminoL(spawnX, spawnY);
            break;
        case TETRAMINO_TYPE_l:
            nextPiece = Tetraminol(spawnX, spawnY);
            break;
        case TETRAMINO_TYPE_T:
            nextPiece = TetraminoT(spawnX, spawnY);
            break;
        default:
            nextPiece = TetraminoO(spawnX, spawnY);
            break;
    }
}

//Changes the current tetramino to the next one and chooses a new tetramino for the further selections
void TetrisLogicController::changeTetramino() {
    currentPiece = nextPiece;
    chooseNextTetramino();
}

//Checks if move is possible
bool TetrisLogicController::canMove(int deltaX, int deltaY) {
    bool temp = true;

    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        temp = temp && !currentGrid.getCellState(currentPiece.getBlockPos(i).x + deltaX,
                                                 currentPiece.getBlockPos(i).y + deltaY).solid;
    }
    return temp;
}

//Makes movement after verifying that it is possible
void TetrisLogicController::doMove(int deltaX, int deltaY) {
    if (canMove(deltaX, deltaY))
    {
        eraseTetramino();
        currentPiece.changePos(deltaX, deltaY);
        makeTetraminoVisible();
    }
}

//Does a downward movement
void TetrisLogicController::moveDown() {
    if (canMove(VECTOR_DOWN))
    {
        doMove(VECTOR_DOWN);
    } else
    {
        makeTetraminoStatic();
        doTetraminoPlacement();
        gameOver = !canMove(VECTOR_ZERO);
    }
}

//Places a tetramino after touching the bottom of the game grid,
//checks for completed lines and changes to the next tetramino
void TetrisLogicController::doTetraminoPlacement() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.incrementRowFilledCount(currentPiece.getBlockPos(i).y);
    }
    int filledLines = currentGrid.emptyFilledRows(); // Score
    completedRows+=filledLines;
    score+= filledLines * filledLines * SCORE_SINGLE_LINE;
    changeTetramino();
}

//Checks if a rotation is valid and does not overlap with anything else
bool TetrisLogicController::canRotate(bool clockwise) {

    bool temp;
    currentPiece.doBlocksRotation(clockwise);
    temp = canMove(VECTOR_ZERO);
    currentPiece.doBlocksRotation(!clockwise);
    return temp;
}

//Rotates a tetramino after checking if it is a valid rotation
void TetrisLogicController::doRotation(bool clockwise) {
    if(canRotate(clockwise))
    {
        eraseTetramino();
        currentPiece.doBlocksRotation(clockwise);
        makeTetraminoVisible();
    }
}

//Returns whether the game is over after inability to spawn new one
bool TetrisLogicController::isGameOver() {
    return gameOver;
}

//Makes the player controlled tetramino visible on the grid without it having collisions
void TetrisLogicController::makeTetraminoVisible() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.setCellState(currentPiece.getBlockPos(i).x , currentPiece.getBlockPos(i).y, true, false, currentPiece.getColor());
    }
}

//Erases the player controlled tetramino, used during movement to delete the tetramino from the old position
void TetrisLogicController::eraseTetramino() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.setCellState(currentPiece.getBlockPos(i).x , currentPiece.getBlockPos(i).y, false, false, GRAPHICS_WHITE);
    }
}

//Makes a tetramino static activating collision, used after a tetramino touches the bottom of the game grid
//and is no longer controlled by the player
void TetrisLogicController::makeTetraminoStatic() {
    for (int i = 0; i < TETRAMINO_BLOCKS; i++) {
        currentGrid.setCellState(currentPiece.getBlockPos(i).x , currentPiece.getBlockPos(i).y, true, true,currentPiece.getColor());
    }
}

//Reads player inputs (press "a" or "A" to doMove left, etc...)
void TetrisLogicController::gameFrame() {

        int _input = getch();
        if (_input != ERR) napms(GAME_FRAMERATE/3);
        switch (_input) {
            case 'a':
            case 'A':
            case KEY_LEFT:
                doMove(VECTOR_LEFT);
                break;
            case 'd':
            case 'D':
            case KEY_RIGHT:
                doMove(VECTOR_RIGHT);
                break;
            case 'w':
            case 'W':
            case KEY_UP:
                doRotation(true);
                break;
            case 's':
            case 'S':
            case KEY_DOWN:
                moveDown();
                break;
            default:
                break;
        }
            moveDown();
}

//Returns the actual game score
int TetrisLogicController::getScore() {
    return score;
}

//Returns the next tetramino to be used
Tetramino TetrisLogicController::getPrediction() {
    return nextPiece;
}

//Returns the number of completed rows/lines during the game
int TetrisLogicController::getCompletedRows() {
    return completedRows;
}
