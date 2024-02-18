//
// Created by onitn on 11/15/2023.
//

#ifndef TETRISS_SCOREBOARD_H
#define TETRISS_SCOREBOARD_H
#define MAX_NAME 10
#define MAX_SCORE_ENTRIES 10
#define FRAMERATE 300

#include "fstream"
#include "cstring"
#include "ncurses/ncurses.h"
#include "iostream"

struct highscoreEntry{
    char name[MAX_NAME+1] {""};
    int score {0};
    bool filled {false};
};

class ScoreBoard {
 char playerName[MAX_NAME+1]{"Player"};
 char saveFilename[MAX_NAME+1]{"save.tto"};
 WINDOW *inputWindow;
 std::ifstream inputFile;
 std::ofstream outputFile;
 highscoreEntry scoresList[MAX_SCORE_ENTRIES]{};
    public:ScoreBoard(){
     inputWindow = newwin(4, MAX_NAME*3, 0,0);
    }


    void deleteWindows();
    void readHighscores();
    void writeHighscore();
    void addScore(char name[], int score);
    void insertName(int score);
    void updateScoreBoard(int score);
    void renderScores();
};


#endif //TETRISS_SCOREBOARD_H
