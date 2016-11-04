#include "definition.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void deleteLine(char mat[Y][X], int line);
void showScore(int score, int line);
void checkLines(char mat[Y][X], int *score, int *line);
void endGameScreen(int *score, int *line);
void printBestScores();
