//
// Created by onitn on 11/15/2023.
//

#include "ScoreBoard.h"
using namespace std;
void ScoreBoard::readHighscores() {
    inputFile.open(saveFilename);
    char ch = ' ';
    int counter=0;
    for (auto & previousScore : previousScores) {
        previousScore.filled = false;
        inputFile.get(ch);
        for (counter = 0; counter < MAX_NAME && !inputFile.eof() && ch!=':'; ++counter) {
            previousScore.name[counter] = ch;
            inputFile.get(ch);
        }
        previousScore.name[counter] = '\0';

        inputFile.get(ch);
        for (counter = 0; counter < MAX_NAME && !inputFile.eof() && ch!='\n'; ++counter) {
            if (ch >= '0' && ch<='9') {
                previousScore.score[counter] = ch;
                previousScore.filled = true;
            }
                inputFile.get(ch);
        }
        previousScore.score[counter] = '\0';
    }
    inputFile.close();
}

void ScoreBoard::writeHighscore() {
    outputFile.open(saveFilename);

    for (auto & previousScore : previousScores) {
        if (previousScore.filled)
        {
            outputFile<<previousScore.name<<':'<<previousScore.score<<'\n';
        }

    }
    outputFile.close();
}

void ScoreBoard::insertScore() {
    for (int i = 0; i < MAX_NAME; ++i) {
        if (!previousScores[i].filled) {
            strcpy(previousScores[i].name, playerName);
            strcpy(previousScores[i].score, highscore);
            previousScores[i].filled = true;
            return;
        } else {
            if (stoi(previousScores[i].score) < stoi(highscore)) {
                for (int j = 0; j < MAX_NAME-i; ++j) {
                    previousScores[MAX_NAME-1-j] = previousScores[MAX_NAME-2-j];
                }
                strcpy(previousScores[i].name, playerName);
                strcpy(previousScores[i].score, highscore);
                return;
            }
        }
    }
    }

void ScoreBoard::updateScoreBoard(int score) {
    sprintf(highscore,"%d", score);
    readHighscores();
    insertName();
    insertScore();
    writeHighscore();
}

void ScoreBoard::insertName() {
    int nextFreeLetterPos = 6;
    char ch = ' ';
    timeout(-1);
    box(inputWindow,0,0);
    mvwprintw(inputWindow, 1,1,"Name: %s", playerName);
    mvwprintw(inputWindow, 2,1,"Score: %s", highscore);
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
        mvwprintw(inputWindow, 2,1,"Score: %s", highscore);
    }
    timeout(FRAMERATE);
}

void ScoreBoard::renderScores() {
    readHighscores();
    clear();
    refresh();
    box(stdscr,0,0);
    int middleX=0, middleY=0;
    getmaxyx(stdscr, middleY, middleX);
    middleX = middleX/3;
    middleY = middleY/3;
    for (int i = 0; i < MAX_NAME; ++i) {
        if (previousScores[i].filled)
        {
            mvprintw(3+i*2,middleX,"Name: %s - Score: %s", previousScores[i].name,previousScores[i].score);
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
