//
// Created by onitn on 11/15/2023.
//

#include "Menu.h"

void Menu::drawMenuEntries(int startX, int startY, const char entry1[], const char entry2[], const char entry3[]) {
    mvprintw(1+startY,startX,entry1); //Draws the entries frow firt to last, top to bottom
    mvprintw(3+startY,startX,entry2);
    mvprintw(5+startY,startX,entry3);
}

void Menu::menuLoop() {
    int selected = 0; // The selected option of the menu
    const int options = 3; //The number of options of the menu
    char ch =' '; //Char used to get input in the menu
    int startX, startY; //The coordinates used to decide the starting point of the menu text
    getmaxyx(stdscr, startY, startX);
    startX = startX / 2.3;
    startY = startY / 3;
    while (ch!='\n') //Wait for the enter key to be pressed and then control the selected option
    {
        box(stdscr, 0,0);
        switch (selected) {
            case 0:
                drawMenuEntries(startX, startY, MENU_NEWGAME_SELECTED, MENU_SCORES, MENU_EXIT);
                break;
            case 1:
                drawMenuEntries(startX, startY, MENU_NEWGAME, MENU_SCORES_SELECTED, MENU_EXIT);
                break;
            case 2:
                drawMenuEntries(startX, startY, MENU_NEWGAME, MENU_SCORES, MENU_EXIT_SELECTED);
                break;
            default:
                drawMenuEntries(startX, startY, MENU_NEWGAME, MENU_SCORES, MENU_EXIT);
                break;
        }
        refresh();
        ch = getch(); //Get the input and move in the menu in case of 'S' or 'W'
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

    ScoreBoard scoreBoard = ScoreBoard(); //Prepare the scoreboard class that handles score and drawing them
    switch (selected) {
        case 0:
            clear();
            refresh();
            doGameLoop(); //Start game
            break;
        case 1:
            scoreBoard.renderScores();//Show Scores
            menuLoop(); // After we exit scores, return to menu
            break;
        case 2:
            return;
        default:
            break;
    }
}
void Menu::doGameLoop()
{
    TetrisGameRenderer gameRenderer = TetrisGameRenderer(); //Create the game renderer
    gameRenderer.renderGrid(); //Render the initial grid
    gameRenderer.renderScore(); //Render the initial game score
    gameRenderer.gameLoop(); //Start game loop
    gameRenderer.destroyWindows(); //After game loop destroy the game windows
    updateScores(gameRenderer.logicController.score); //Update the scores
}
void Menu::updateScores(int newScore){
    ScoreBoard scoreBoard = ScoreBoard(); //Create a new scoreboard class
    scoreBoard.updateScoreBoardFile(newScore); //Update the file with the actual highest scores
    scoreBoard.deleteWindows(); //Delete the windows that the scoreboard created
    menuLoop(); //Return to the menu after game over
}
