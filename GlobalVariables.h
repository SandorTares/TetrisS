//
// Created by onitn on 2/20/2024.
//

#ifndef TETRISS_GLOBALVARIABLES_H
#define TETRISS_GLOBALVARIABLES_H


/*Game*/
#define GAME_FRAMERATE 300
#define GAME_SAVE_NAME "save.tto"

/*Grid*/
#define GRID_WIDTH 10
#define GRID_HEIGHT 20

/*Menu*/
#define MENU_NEWGAME "New Game"
#define MENU_NEWGAME_SELECTED "-> NEW GAME"
#define MENU_SCORES "View Scoreboard"
#define MENU_SCORES_SELECTED "-> VIEW SCOREBOARD"
#define MENU_EXIT "End Game"
#define MENU_EXIT_SELECTED "-> END GAME"

/*Scoreboard*/
#define SCORE_MAX_NAME 10
#define SCORE_MAX_ENTRIES 10
#define SCORE_SINGLE_LINE 10

/*Graphics*/
#define GRAPHICS_BLOCK_WIDTH 3
#define GRAPHICS_EMPTY " . "
#define GRAPHICS_FILLED "[#]"
#define GRAPHICS_BORDERS_SIZE 2

/*Tetramino*/
#define TETRAMINO_BLOCKS 4
#define TETRAMINO_VARIATIONS 7

/*Vector*/
#define VECTOR_LEFT -1,0
#define VECTOR_RIGHT 1,0
#define VECTOR_DOWN 0,1
#define VECTOR_ZERO 0,0

#endif //TETRISS_GLOBALVARIABLES_H
