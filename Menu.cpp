//
// Created by onitn on 11/15/2023.
//

#include "Menu.h"

void Menu::drawMenuEntries(int startX, int startY, const char entry1[], const char entry2[], const char entry3[]) {
    mvprintw(1+startY,startX,entry1);
    mvprintw(3+startY,startX,entry2);
    mvprintw(5+startY,startX,entry3);
}

void Menu::menuLoop() {
    int selected = 0;
    const int options = 3;
    char ch =' ';
    int middleX, middleY;
    getmaxyx(stdscr, middleY, middleX);
    middleX = middleX/2.3;
    middleY = middleY/3;
    while (ch!='\n')
    {
        box(stdscr, 0,0);
        switch (selected) {
            case 0:
                drawMenuEntries(middleX, middleY, MENU_NEWGAME_SELECTED, MENU_SCORES, MENU_EXIT);
                break;
            case 1:
                drawMenuEntries(middleX, middleY, MENU_NEWGAME, MENU_SCORES_SELECTED, MENU_EXIT);
                break;
            case 2:
                drawMenuEntries(middleX, middleY, MENU_NEWGAME, MENU_SCORES, MENU_EXIT_SELECTED);
                break;
            default:
                drawMenuEntries(middleX, middleY, MENU_NEWGAME, MENU_SCORES, MENU_EXIT);
                break;
        }
        refresh();
        ch = getch();
        switch (ch) {
            case 's':
            case 'S':
                selected = (selected+1)%options;
                clear();
                break;
            case 'w':
            case 'W':
                selected = (selected-1+options)%options;
                clear();
                break;
            default:
                break;

        }
    }

    ScoreBoard scoreBoard = ScoreBoard();
    switch (selected) {
        case 0:
            clear();
            refresh();
            doGameLoop();
            break;
        case 1:
            scoreBoard.renderScores();
            menuLoop();
            break;
        case 2:
            return;
        default:
            break;
    }
}
void Menu::doGameLoop()
{
    TetrisGameRenderer gameRenderer = TetrisGameRenderer();
    gameRenderer.renderGrid();
    gameRenderer.renderScore();
    gameRenderer.renderNextPiece();
    gameRenderer.gameLoop();
    gameRenderer.destroyWindows();
    updateScores(gameRenderer.logicController.score);
}
void Menu::updateScores(int newScore){
    ScoreBoard scoreBoard = ScoreBoard();
    scoreBoard.updateScoreBoard(newScore);
    scoreBoard.deleteWindows();
    menuLoop();
}
