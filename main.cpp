#include "Menu.h"
#include "ctime"
void startNcurses();

int main() {
    startNcurses();
    srand(time(nullptr));
    Menu menu = Menu();
    menu.menuLoop();
    return 0;
}


void startNcurses()
{
    initscr();
    refresh();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    timeout(FRAMERATE);
    if (has_colors()) start_color();
    init_pair(1,COLOR_RED, COLOR_BLACK);
    if (can_change_color()) init_color(COLOR_WHITE, 1000, 498, 152);
    init_pair(2,COLOR_WHITE, COLOR_BLACK);
    init_pair(3,COLOR_YELLOW, COLOR_BLACK);
    init_pair(4,COLOR_GREEN, COLOR_BLACK);
    init_pair(5,COLOR_CYAN, COLOR_BLACK);
    init_pair(6,COLOR_BLUE, COLOR_BLACK);
    init_pair(7,COLOR_MAGENTA, COLOR_BLACK);
}
