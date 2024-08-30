//
// Created by onitn on 11/15/2023.
//

#include "ScoreBoard.h"
using namespace std;

//Checks to make sure that the score string is a valid number to avoid errors or set it to 0 if no number is score
void correctNonNumberScore(char score[]){
    bool containsNumbers = false;
    for (int i = 0; score[i] != '\0'; ++i) {
        if (!(score[i] >= '0' && score[i] <= '9')){
            score[i] = ' ';
        } else
        {
            containsNumbers = true;
        }
    }
    if (!containsNumbers) strcpy(score, "0");
}

//Reads the save file and adds the name and score pairs to the score list
void ScoreBoard::readScoresFile() {
    inputFile.open(GAME_SAVE_NAME);
    if (!inputFile.is_open()) return;
    char name[SCORE_MAX_NAME + 1] {""};
    char score[SCORE_MAX_NAME + 1] {""};

    while (!inputFile.eof()){
        inputFile.getline(name, SCORE_MAX_NAME + 1, ':');
        inputFile.getline(score, SCORE_MAX_NAME + 1);
        correctNonNumberScore(score);
        insertScoreToList(name, stoi(score));
    }
    inputFile.close();
}

//Writes the name and score pairs from the score list to the save file
void ScoreBoard::writeScoresFile() {//Simple printing to file of the names and scores
    if (scoreList == nullptr) return; // Nothing to save
    outputFile.open(GAME_SAVE_NAME);
    p_scoreList temp = scoreList;
    for (int i = 0; i < SCORE_MAX_ENTRIES && temp != nullptr; ++i) {
            outputFile<<temp->name<<":"<<temp->score;
            if (temp->next != nullptr) outputFile<<'\n'; //Prepare new line for next entry if it exists
            temp=temp->next;
    }
    outputFile.close();
}

//Inserts elements in a list while also sorting them
p_scoreList insertEntry(p_scoreList head, scoreEntry entry){
    if (head == nullptr) { //Create new list head
        head = new scoreEntry;
        (*head) = entry;
        head->next = nullptr;
        return head;
    }
    else if (head->score < entry.score){ //Replace list head
        p_scoreList temp;
        temp = head;
        head = new scoreEntry;
        (*head) = entry;
        head->next=temp;
        return head;
    } else { //Insert entry in the sublist
        head->next = insertEntry(head->next, entry);
        return head;
    }

}

//Inserts score entry to the highscore list
void ScoreBoard::insertScoreToList(char name[], int score) {
    scoreEntry entry;
    strcpy(entry.name, name);
    entry.score = score;
    scoreList = insertEntry(scoreList, entry);

}

//Gets the newest score after a game, inserts it to the score list and saves the update score list to the save file
void ScoreBoard::updateScoreFile(int newScore) {
    insertScoreName(newScore);//Get the name of the new newScore
    insertScoreToList(playerName, newScore);//Add newScore to the array if possible
    writeScoresFile();//Write the new scores to the file
}

//Function used to accept a player name for the most recent score when saving it
void ScoreBoard::insertScoreName(int score) {
    char _input = ' ';
    wclear(inputWindow); //Clear old contents
    timeout(-1); //Stop timeout so that we wait indefinitely for inputs from the player
    box(inputWindow,0,0);
    mvwprintw(inputWindow, 1,1,"Name: %s", playerName);
    mvwprintw(inputWindow, 2,1,"Score: %d", score);
    refresh();
    wrefresh(inputWindow);
    while (_input != '\n')
    {
        box(inputWindow,0,0);
        wrefresh(inputWindow);

        _input = getch();
        if (((_input >= 'a' && _input <= 'z') || (_input >= 'A' && _input <= 'Z')))//To simplify formating, we only accept letters
        {
            if (insertedNameLength < SCORE_MAX_NAME ){
            playerName[insertedNameLength] = _input;
            insertedNameLength++;
            }
        } else if (insertedNameLength > 0 && _input != '\n') //Anything other than enter and letters functions as backspace
        {
            insertedNameLength--;
            playerName[insertedNameLength] = '\0';
            wclear(inputWindow);
        }
        mvwprintw(inputWindow, 1,1,"Name: %s", playerName);
        mvwprintw(inputWindow, 2,1,"Score: %d", score);
    }
    timeout(GAME_FRAMERATE); //Reset timeout
}

//Draws the top scores to the screen
void ScoreBoard::renderScores() {
    clear();
    box(stdscr,0,0);
    int _draw_middle_x = getmaxx(stdscr) / 3;
    p_scoreList temp = scoreList;

    for (int i = 0; i < SCORE_MAX_ENTRIES && temp != nullptr; ++i) {
            mvprintw(3+i*2, _draw_middle_x, "Name: %s - Score: %d", temp->name, temp->score);
            temp=temp->next;
    }
    mvprintw(5 + SCORE_MAX_NAME * 2, (int) (_draw_middle_x * 1.5), MENU_EXIT_SELECTED);

    while (getch()!='\n');
    clear();
}

//Deletes the pointers of the entry list to free memory
void deleteScoreList(p_scoreList head)
{
    if (head == nullptr) return;
    deleteScoreList(head->next);
    delete head;
}

//Delete the window and score list when exiting to avoid memory leaks
void ScoreBoard::freeMemory() {
    delwin(inputWindow);
    deleteScoreList(scoreList);
    scoreList = nullptr;
}
