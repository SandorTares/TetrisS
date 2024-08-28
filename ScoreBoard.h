//
// Created by onitn on 11/15/2023.
//

#ifndef TETRISS_SCOREBOARD_H
#define TETRISS_SCOREBOARD_H
#include "cstring"
#include "fstream"
#include "ncurses/ncurses.h"
#include "GlobalVariables.h"

struct scoreEntry{
    char name[SCORE_MAX_NAME + 1] {""};
    int score {0};
    bool filled {false};
    scoreEntry* next = nullptr;
};

typedef scoreEntry* p_scoreList;

class ScoreBoard {
protected:
 char playerName[SCORE_MAX_NAME + 1]{"Player"};
 int insertedNameLength = 6;
 WINDOW *inputWindow;
 std::ifstream inputFile;
 std::ofstream outputFile;
 p_scoreList scoreList = nullptr;
 void readScoresFile();
 void writeScoresFile();
 void insertScoreToList(char name[], int score);
 void insertScoreName(int score);

public:
    ScoreBoard(){
     inputWindow = newwin(4, SCORE_MAX_NAME * 3, 0, 0);
        readScoresFile();//Read the scores from the save file
    }
    void freeMemory();
    void updateScoreFile(int newScore);
    void renderScores();
};


#endif //TETRISS_SCOREBOARD_H
