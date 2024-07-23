#include "Menu.h"
#include "ctime"

void startNcurses();

int main() {
    startNcurses(); //Start Ncurses
    srand(time(nullptr)); //Random seed
    Menu menu = Menu(); //New menu instance
    menu.menuLoop(); //Start menu
    return 0;
}


void startNcurses() //Ncurses initialization
{
    initscr(); //Screen initialization
    refresh(); //Refresh (Update) Screen
    noecho(); //No text shown when input is pressed
    curs_set(0); //No text cursor (blinking line)
    keypad(stdscr, true);
    timeout(GAME_FRAMERATE); //Max wait time between inputs
}
