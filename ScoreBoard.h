//
// Created by onitn on 11/15/2023.
//

#ifndef TETRISS_SCOREBOARD_H
#define TETRISS_SCOREBOARD_H
#define MAX_NAME 10
#define FRAMERATE 300
#include "fstream"
#include "cstring"
#include "ncurses/ncurses.h"
struct highscoreEntry{
    char name[MAX_NAME+1];
    char score[MAX_NAME+1];
    bool filled;
};

class ScoreBoard {
 char highscore[MAX_NAME+1]{"0"};
 char playerName[MAX_NAME+1]{"Player"};
 char saveFilename[MAX_NAME+1]{"save.tto"};
 WINDOW *inputWindow;
 std::ifstream inputFile;
 std::ofstream outputFile;
 highscoreEntry previousScores[MAX_NAME]{};
    public:ScoreBoard(){
     inputWindow = newwin(4, MAX_NAME*3, 0,0);
    }


    void deleteWindows();
    void readHighscores();
    void writeHighscore();
    void insertScore();
    void insertName();
    void updateScoreBoard(int score);
    void renderScores();
};


#endif //TETRISS_SCOREBOARD_H
