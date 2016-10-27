#include "scoreHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void showScore(int score){
  printf("Score: %d \n\n", score);
}

void deleteLine(char mat[Y][X], int line){
  for (int i = line; i > 0; i--) {
    for (int j = 0; j < X; j++) {
      mat[i][j] = mat[i-1][j];
    }
  }
}

int checkLines(char mat[Y][X], int score){
  int j;
  int isEmpty;
  for (int i = 0; i < Y-1; i++) {
    isEmpty = 0;
    if (mat[i][j] == 'o') {
      isEmpty = 1;
      for (j = 1; j < X-2; j++) {
        if (mat[i][j] == ' ') {
          isEmpty = 0;
        }
      }
    }
    if (isEmpty == 0) {
    }
    if (isEmpty == 1) {
      deleteLine(mat,i);
      score += 10;
    }
  }
  return score;
}
