// #include "menu.h"
#include "definition.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>


void deleteLine(char mat[Y][X], int line);
void showScore(int score, int line, int tries);
void checkLines(char mat[Y][X], int *score, int *line, int level);
// void endGameScreen(int *score, int *line);
void printBestScores(saveScore oldScores[nbOldScore]);
void Score(int *score, int *line, float *difficulty_O_Meter);
void getName(char name[lengthName]);
void readFile(saveScore oldScores[nbOldScore]);
void writeFile(saveScore oldScores[nbOldScore]);
void fileScoreHandler(saveScore oldScores[nbOldScore], int intention);
void sortScores(saveScore oldScores[nbOldScore], saveScore save);
void writeFile2(saveScore oldScores[nbOldScore]);
void readFile2(saveScore oldScores[nbOldScore]);
void sortScores2(saveScore oldScores[nbOldScore], saveScore save);
void Score2(int *score, int *line, float *difficulty_O_Meter, int *tries);
void printBestScores2(saveScore oldScores[nbOldScore]);
