//
// Created by onitn on 11/15/2023.
//

#include "Menu.h"

void Menu::menuLoop() {
    int selected = 0;
    const int options = 3;
    char ch =' ';
    int middleX=0, middleY=0;
    getmaxyx(stdscr, middleY, middleX);
    middleX = middleX/2.3;
    middleY = middleY/3;
    while (ch!='\n')
    {
        box(stdscr, 0,0);
        switch (selected) {
            case 0:
                attron(COLOR_PAIR(4));
                mvprintw(1+middleY,middleX,"-NEW GAME");
                attroff(COLOR_PAIR(4));
                mvprintw(3+middleY,middleX,"View Scores");
                mvprintw(5+middleY,middleX,"Exit");
                break;
            case 1:
                mvprintw(1+middleY,middleX,"New Game");
                attron(COLOR_PAIR(3));
                mvprintw(3+middleY,middleX,"-VIEW SCORES");
                attroff(COLOR_PAIR(3));
                mvprintw(5+middleY,middleX,"Exit");
                break;
            case 2:
                mvprintw(1+middleY,middleX,"New Game");
                mvprintw(3+middleY,middleX,"View Scores");
                attron(COLOR_PAIR(1));
                mvprintw(5+middleY,middleX,"-EXIT");
                attroff(COLOR_PAIR(1));
                break;
            default:
                mvprintw(1+middleY,middleX,"New Game");
                mvprintw(3+middleY,middleX,"View Scores");
                mvprintw(5+middleY,middleX,"Exit");
                break;
        }
        refresh();
        ch = getch();
        switch (ch) {
            case 's':
            case 'S':
                selected = (selected+=1)%options;
                clear();
                break;
            case 'w':
            case 'W':
                selected = (selected=selected-1+options)%options;
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