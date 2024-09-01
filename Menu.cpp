//
// Created by onitn on 11/15/2023.
//

#include "Menu.h"

//Start the main menu execution loop
void Menu::doMenuLoop() {
    int _selected = 0; // The _selected option of the menu
    int _draw_starting_x, _draw_starting_y; //The coordinates used to decide the starting point of the menu text
    int _input =' '; //Char used to get input in the menu
    bool _gameRunning = true;
    getmaxyx(stdscr, _draw_starting_y, _draw_starting_x);
    _draw_starting_x = _draw_starting_x / 2.25;
    _draw_starting_y = _draw_starting_y / 3;
    while (_gameRunning){
    //Wait for the enter key to be pressed and then control the _selected option
        while (_input != '\n') {
            drawMenuTitle(_draw_starting_y-8);
            drawMenuCursor(_draw_starting_x-10,_draw_starting_y+5+_selected*5);
            drawMenuEntries(_draw_starting_x, _draw_starting_y+5);
            box(stdscr, 0,0);
            _input = getch(); //Get the input and doMove in the menu in case of 'S' or 'W'
            switch (_input) {
                case 's':
                case 'S':
                case KEY_DOWN:
                    _selected = (_selected + 1) % MENU_OPTIONS_NUMBER;
                    clear();
                    break;
                case 'w':
                case 'W':
                case KEY_UP:
                    _selected = (_selected - 1 + MENU_OPTIONS_NUMBER) % MENU_OPTIONS_NUMBER;
                    clear();
                    break;
                default:
                    break;
            }
        }

        switch (_selected) {
            case 0:
                doGameLoop(); //Start game
                break;
            case 1:
                scoreBoard.renderScores();//Show Scores
                break;
            case 2:
                _gameRunning = false;
            default:
                break;
        }
        _input=' '; //Remove last saved input
    }
    scoreBoard.freeMemory();
}




//Draws the menu entries frow firt to last, top to bottom using the specified text
void Menu::drawMenuEntries(int draw_starting_x, int draw_starting_y) {
    drawMenuStart(draw_starting_x,draw_starting_y);
    drawMenuScore(draw_starting_x,draw_starting_y+5);
    drawMenuExit(draw_starting_x,draw_starting_y+10);
}

void Menu::drawMenuTitle(int draw_starting_y) {
    mvprintw(draw_starting_y  , 0, MENU_TITLE);
}

void Menu::drawMenuCursor(int draw_starting_x, int draw_starting_y) {
    mvprintw(draw_starting_y  , draw_starting_x, "[#]");
    mvprintw(draw_starting_y+1, draw_starting_x, "[#][#]");
    mvprintw(draw_starting_y+2, draw_starting_x, "[#]");
}

void Menu::drawMenuStart(int draw_starting_x, int draw_starting_y) {
    mvprintw(draw_starting_y+1, draw_starting_x, MENU_NEWGAME);
    /*
    mvprintw(draw_starting_y  , draw_starting_x, "   [#][#]   [#][#][#]   [#][#][#]   [#][#][#]   [#][#][#]");
    mvprintw(draw_starting_y+1, draw_starting_x, "   [#]         [#]      [#]===[#]   [#][#]         [#]   ");
    mvprintw(draw_starting_y+2, draw_starting_x, "[#][#]         [#]      [#]   [#]   [#]   [#]      [#]   ");
*/
     }


void Menu::drawMenuScore(int draw_starting_x, int draw_starting_y) {
    mvprintw(draw_starting_y+1, draw_starting_x, MENU_SCORES);
    //(draw_starting_y  , draw_starting_x, "   [#][#]   [#][#][#]   [#][#][#]   [#][#][#]  [#][#][#]");
    //mvprintw(draw_starting_y+1, draw_starting_x, "   [#]      [#]         [#]   [#]   [#][#]     [#]==    ");
    //mvprintw(draw_starting_y+2, draw_starting_x, "[#][#]      [#][#][#]   [#][#][#]   [#]   [#]  [#][#][#]");
}
void Menu::drawMenuExit(int draw_starting_x, int draw_starting_y) {
    mvprintw(draw_starting_y+1, draw_starting_x, MENU_EXIT);
    /*
    mvprintw(draw_starting_y  , draw_starting_x, "[#][#][#]   [#]   [#]   [#][#][#]   [#][#][#]");
    mvprintw(draw_starting_y+1, draw_starting_x, "[#]==          [#]         [#]         [#]   ");
    mvprintw(draw_starting_y+2, draw_starting_x, "[#][#][#]   [#]   [#]   [#][#][#]      [#]   ");
*/
     }

//Starts the game loop by calling the TetrisGameRenderer and updates the scores at the end
void Menu::doGameLoop()
{
    TetrisGameRenderer _gameRenderer = TetrisGameRenderer(); //Create the game renderer
    int _score = _gameRenderer.doGameLoop(); //Start the game loop and at the end return the final _score
    updateScores(_score); //Update the scores
}

//Update the file with the current highest scores
void Menu::updateScores(int newScore){
    scoreBoard.updateScoreFile(newScore);
}

