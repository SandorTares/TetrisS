//
// Created by onitn on 11/15/2023.
//

#include "ScoreBoard.h"
using namespace std;

void validateScore(char score[]){ //Checks to make sure that the score string is a valid number to avoid erros with stoi or set it to -1 if no number is found
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

void ScoreBoard::readHighscores() { //Reads the input file and adding the name and score pairs in the scoreList array
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

void ScoreBoard::writeHighscore() {//Simple printing to file of the names and scores
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
        if (!scoresList[i].filled) { //if the slot is free, put the score entry there
            strcpy(scoresList[i].name, name);
            scoresList[i].score = score;
            scoresList[i].filled = true;
            return;
        } else {
            if (scoresList[i].score < score) { //otherwise check which score is higher
                for (int j = 0; j < MAX_NAME-i; ++j) {
                    scoresList[MAX_NAME - 1 - j] = scoresList[MAX_NAME - 2 - j]; //if the new score is higher, shift the scores down
                }
                strcpy(scoresList[i].name, name);
                scoresList[i].score = score;
                return;
            }
        }
    }
    }

void ScoreBoard::updateScoreBoardFile(int score) {
    readHighscores();//Read the scores from the save file
    insertName(score);//Get the name of the new score
    addScore(playerName, score);//Add score to the array if possible
    writeHighscore();//Write the new scores to the file
}

void ScoreBoard::insertName(int score) {
    int nextFreeLetterPos = 6;
    char ch = ' ';
    timeout(-1); //Stop timeout so that we wait indefinitely for inputs from the player
    box(inputWindow,0,0);
    mvwprintw(inputWindow, 1,1,"Name: %s", playerName);
    mvwprintw(inputWindow, 2,1,"Score: %d", score);
    wrefresh(inputWindow);
    while (ch!='\n')
    {
        box(inputWindow,0,0);
        wrefresh(inputWindow);

        ch = getch();
        if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))//To simplify formating, we only accept letters
        {
            if (nextFreeLetterPos < MAX_NAME ){
            playerName[nextFreeLetterPos] = ch;
            nextFreeLetterPos++;
            }
        } else if (nextFreeLetterPos > 0 && ch!='\n') //Anything other than enter and letters functions as backspace
        {
            nextFreeLetterPos--;
            playerName[nextFreeLetterPos] = '\0';
            wclear(inputWindow);
        }
        mvwprintw(inputWindow, 1,1,"Name: %s", playerName);
        mvwprintw(inputWindow, 2,1,"Score: %d", score);
    }
    timeout(FRAMERATE); //Reset timeout
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
        mvprintw(5+MAX_NAME*2,middleX*1.5,MENU_EXIT_SELECTED);
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

void ScoreBoard::deleteWindows() { //Clear and delete windows to avoid memory leaks
    wclear(inputWindow);
    wrefresh(inputWindow);
    delwin(inputWindow);
}
