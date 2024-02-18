//
// Created by onitn on 11/15/2023.
//

#include "ScoreBoard.h"
using namespace std;

void validateScore(char score[]){
    bool containsNumbers = false;
    for (int i = 0; score[i] != '\0'; ++i) {
        if (!(score[i] >= '0' && score[i] <= '9')){
            score[i] = ' ';
        } else
        {
            containsNumbers = true;
        }
    }
    if (!containsNumbers) strcpy(score, "-1");
}

void ScoreBoard::readHighscores() {
    inputFile.open(saveFilename);
    char name[MAX_NAME+1] {""};
    char score[MAX_NAME+1] {""};
    inputFile.getline(name, MAX_NAME+1, ':');
    inputFile.getline(score, MAX_NAME+1);
    while (!inputFile.eof()){
    validateScore(score);
    addScore(name, stoi(score));
    inputFile.getline(name, MAX_NAME+1, ':');
    inputFile.getline(score, MAX_NAME+1);
    }
    inputFile.close();
}

void ScoreBoard::writeHighscore() {
    outputFile.open(saveFilename);

    for (auto & previousScore : scoresList) {
        if (previousScore.filled)
        {
            outputFile<<previousScore.name<<":"<<previousScore.score<<'\n';
        }

    }
    outputFile.close();
}

void ScoreBoard::addScore(char name[], int score) {

    for (int i = 0; i < MAX_NAME; ++i) {
        if (!scoresList[i].filled) {
            strcpy(scoresList[i].name, name);
            scoresList[i].score = score;
            scoresList[i].filled = true;
            return;
        } else {
            if (scoresList[i].score < score) {
                for (int j = 0; j < MAX_NAME-i; ++j) {
                    scoresList[MAX_NAME - 1 - j] = scoresList[MAX_NAME - 2 - j];
                }
                strcpy(scoresList[i].name, name);
                scoresList[i].score = score;
                return;
            }
        }
    }
    }

void ScoreBoard::updateScoreBoard(int score) {
    readHighscores();
    insertName(score);
    addScore(playerName, score);
    writeHighscore();
}

void ScoreBoard::insertName(int score) {
    int nextFreeLetterPos = 6;
    char ch = ' ';
    timeout(-1);
    box(inputWindow,0,0);
    mvwprintw(inputWindow, 1,1,"Name: %s", playerName);
    mvwprintw(inputWindow, 2,1,"Score: %d", score);
    wrefresh(inputWindow);
    while (ch!='\n')
    {
        box(inputWindow,0,0);
        wrefresh(inputWindow);

        ch = getch();
        if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
        {
            if (nextFreeLetterPos < MAX_NAME ){
            playerName[nextFreeLetterPos] = ch;
            nextFreeLetterPos++;
            }
        } else if (nextFreeLetterPos > 0 && ch!='\n')
        {
            nextFreeLetterPos--;
            playerName[nextFreeLetterPos] = '\0';
            wclear(inputWindow);
        }
        mvwprintw(inputWindow, 1,1,"Name: %s", playerName);
        mvwprintw(inputWindow, 2,1,"Score: %d", score);
    }
    timeout(FRAMERATE);
}

void ScoreBoard::renderScores() {
    readHighscores();
    clear();
    refresh();
    box(stdscr,0,0);
    int middleX = getmaxx(stdscr)/3;
    for (int i = 0; i < MAX_NAME; ++i) {
        if (scoresList[i].filled)
        {
            mvprintw(3+i*2, middleX, "Name: %s - Score: %d", scoresList[i].name, scoresList[i].score);
        }
    }
    attron(COLOR_PAIR(1));
        mvprintw(5+MAX_NAME*2,middleX*1.5,"-EXIT");
    attroff(COLOR_PAIR(1));
    refresh();
    char ch = ' ';
    while (ch!='\n')
    {
        ch = getch();
    }
    clear();
    refresh();
}

void ScoreBoard::deleteWindows() {
    wclear(inputWindow);
    wrefresh(inputWindow);
    delwin(inputWindow);
}
