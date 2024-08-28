#include "Menu.h"
#include "ctime"

void start_ncurses();

int main() {
    start_ncurses(); //Start Ncurses
    srand(time(nullptr)); //Random seed
    Menu menu = Menu(); //New menu instance
    menu.doMenuLoop(); //Start menu
    return 0;
}


void start_ncurses() //Ncurses initialization
{
    initscr(); //Screen initialization
    refresh(); //Refresh (Update) Screen
    noecho(); //No text shown when input is pressed
    curs_set(0); //No text cursor (blinking line)
    keypad(stdscr, true);
    timeout(GAME_FRAMERATE); //Max wait time between inputs
}
