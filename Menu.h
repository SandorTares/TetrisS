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
    void drawMenuEntries(int startX, int draw_starting_y, const char draw_entry1_text[], const char draw_entry2_text[], const char draw_entry3_text[]);
    void updateScores(int newScore);
    ScoreBoard scoreBoard; //Prepare the scoreboard class that handles score and drawing them
public:
    void doMenuLoop();
};


#endif //TETRISS_MENU_H
