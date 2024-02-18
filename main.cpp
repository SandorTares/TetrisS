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
    timeout(FRAMERATE); //Max wait time between inputs
    if (has_colors()) start_color(); //Start color mode if supported
    init_pair(GRAPHICS_RED, COLOR_RED, COLOR_BLACK); //Start each color
    init_pair(GRAPHICS_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(GRAPHICS_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GRAPHICS_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(GRAPHICS_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(GRAPHICS_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(GRAPHICS_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
}
