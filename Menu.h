//
// Created by onitn on 11/15/2023.
//

#ifndef TETRISS_MENU_H
#define TETRISS_MENU_H
#include "GlobalVariables.h"
#include "ScoreBoard.h"
#include "TetrisGameRenderer.h"

class Menu {
protected:
    void doGameLoop();
    void drawMenuEntries(int draw_starting_x, int draw_starting_y);
    void drawMenuTitle(int draw_starting_y);
    void drawMenuCursor(int draw_starting_x, int draw_starting_y);
    void drawMenuStart(int draw_starting_x, int draw_starting_y);
    void drawMenuScore(int draw_starting_x, int draw_starting_y);
    void drawMenuExit(int draw_starting_x, int draw_starting_y);
    void drawMenuDecoration(int draw_starting_y);
    void updateScores(int newScore);
    ScoreBoard scoreBoard; //Prepare the scoreboard class that handles score and drawing them
public:
    void doMenuLoop();
};


#endif //TETRISS_MENU_H
