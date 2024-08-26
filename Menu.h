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
    void updateScores(int newScore);
    void drawMenuEntries(int startX, int startY, const char entry1[], const char entry2[], const char entry3[]);
public:
    void menuLoop();
};


#endif //TETRISS_MENU_H
