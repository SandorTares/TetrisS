#ifndef TETRISS_GLOBALVARIABLES_H
#define TETRISS_GLOBALVARIABLES_H


/*Game*/
#define GAME_FRAMERATE 300
#define GAME_SAVE_NAME "save.tto"

/*Grid*/
#define GRID_WIDTH 10
#define GRID_HEIGHT 20

/*Menu*/
#define MENU_OPTIONS_NUMBER 3
#define MENU_TITLE "  [##][##][##][##]    [##][##][##][##]    [##][##][##][##]    [##][##][##][##]    [##][##][##][##]    [##][##][##][##]\n" \
                   "  [##][##][##][##]    [##][##][##][##]    [##][##][##][##]    [##][##][##][##]    [##][##][##][##]    [##][##][##][##]\n" \
                   "        [##]          [##]                      [##]          [##]        [##]          [##]          [##]            \n" \
                   "        [##]          [##]                      [##]          [##]        [##]          [##]          [##]            \n" \
                   "        [##]          [##][##][##][##]          [##]          [##][##][##][##]          [##]          [##][##][##][##]\n" \
                   "        [##]          [##][##][##][##]          [##]          [##][##][##][##]          [##]          [##][##][##][##]\n" \
                   "        [##]          [##]                      [##]          [##]    [##]              [##]                      [##]\n" \
                   "        [##]          [##]                      [##]          [##]    [##]              [##]                      [##]\n" \
                   "        [##]          [##][##][##][##]          [##]          [##]        [##]    [##][##][##][##]    [##][##][##][##]\n" \
                   "        [##]          [##][##][##][##]          [##]          [##]        [##]    [##][##][##][##]    [##][##][##][##]"

#define MENU_NEWGAME "  Start Game"
#define MENU_SCORES " View  Scores"
#define MENU_EXIT "  End  Game"
#define MENU_EXIT_SELECTED "-Press enter to return to menu-"

/*Scoreboard*/
#define SCORE_MAX_NAME 10
#define SCORE_MAX_ENTRIES 10
#define SCORE_SINGLE_LINE 10

/*Graphics*/
#define GRAPHICS_BLOCK_WIDTH 3
#define GRAPHICS_EMPTY " . "
#define GRAPHICS_FILLED "[#]"
#define GRAPHICS_BORDERS_SIZE 2
#define GRAPHICS_RED 1
#define GRAPHICS_WHITE 2
#define GRAPHICS_YELLOW 3
#define GRAPHICS_GREEN 4
#define GRAPHICS_CYAN 5
#define GRAPHICS_BLUE 6
#define GRAPHICS_MAGENTA 7
/*Tetramino*/
#define TETRAMINO_BLOCKS 4
#define TETRAMINO_VARIATIONS 7
#define TETRAMINO_TYPE_O 0
#define TETRAMINO_TYPE_I 1
#define TETRAMINO_TYPE_S 2
#define TETRAMINO_TYPE_Z 3
#define TETRAMINO_TYPE_L 4
#define TETRAMINO_TYPE_l 5
#define TETRAMINO_TYPE_T 6

/*Vector*/
#define VECTOR_LEFT -1,0
#define VECTOR_RIGHT 1,0
#define VECTOR_DOWN 0,1
#define VECTOR_ZERO 0,0

#endif //TETRISS_GLOBALVARIABLES_H
