//
// Created by onitn on 11/15/2023.
//

#ifndef TETRISS_SCOREBOARD_H
#define TETRISS_SCOREBOARD_H
#include "cstring"
#include "fstream"
#include "ncurses/ncurses.h"
#include "GlobalVariables.h"

struct highscoreEntry{
    char name[SCORE_MAX_NAME + 1] {""};
    int score {0};
    bool filled {false};
};

class ScoreBoard {
protected:
 char playerName[SCORE_MAX_NAME + 1]{"Player"};
 WINDOW *inputWindow;
 std::ifstream inputFile;
 std::ofstream outputFile;
 highscoreEntry scoresList[SCORE_MAX_ENTRIES]{};
 void readHighscores();
 void writeHighscore();
 void addScore(char name[], int score);
 void insertName(int score);

public:
    ScoreBoard(){
     inputWindow = newwin(4, SCORE_MAX_NAME * 3, 0, 0);
    }
    void deleteWindows();
    void updateScoreBoardFile(int newScore);
    void renderScores();
};


#endif //TETRISS_SCOREBOARD_H
