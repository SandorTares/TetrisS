//
// Created by onitn on 11/15/2023.
//

#ifndef TETRISS_MENU_H
#define TETRISS_MENU_H
#include "ScoreBoard.h"
#include "TetrisGameRenderer.h"

class Menu {

    void doGameLoop();
    void updateScores(int newScore);
public:
    void menuLoop();
};


#endif //TETRISS_MENU_H
