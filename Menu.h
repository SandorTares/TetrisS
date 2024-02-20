//
// Created by onitn on 11/15/2023.
//

#ifndef TETRISS_MENU_H
#define TETRISS_MENU_H
#include "ScoreBoard.h"
#include "TetrisGameRenderer.h"
#define MENU_NEWGAME "New Game"
#define MENU_NEWGAME_SELECTED "-> NEW GAME"
#define MENU_SCORES "View Scoreboard"
#define MENU_SCORES_SELECTED "-> VIEW SCOREBOARD"
#define MENU_EXIT "End Game"
#define MENU_EXIT_SELECTED "-> END GAME"

class Menu {
protected:
    void doGameLoop();
    void updateScores(int newScore);
    void drawMenuEntries(int startX, int startY, const char entry1[], const char entry2[], const char entry3[]);
public:
    void menuLoop();
};


#endif //TETRISS_MENU_H
