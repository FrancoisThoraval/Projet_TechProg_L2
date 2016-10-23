#include "matrixHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void errorHandler(int errorCode){
  switch (errorCode) {
    case 1: printf("Erreur n°%d: Erreur lors de la création du nouveau bloc\n",errorCode);
      exit(1);
      break;
  }
}

int randomize(){
  //On tire au sort un nombre qui correspondra a la forme du bloc
  srand(time(NULL));
  int randomNumber = rand() %5;
  return randomNumber;
}

void initMatrix(char mat[Y][X]){
  // On cree les contours de la matrice
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      mat[i][j]=' ';
      if (i==Y-1) {
        mat[i][j]='#';
      }
      if ((j==0)||(j==X-1)) {
        mat[i][j]='#';
      }
    }
  }
}

void Affiche(char mat[Y][X]) {
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      printf("%c",mat[i][j]);
    }
    printf("\n");
  }
}

// Designs des blocs
void square(char mat[Y][X]) {
  squareDef block;
  char blocChar = 'x';
  block.lineOneY = 0;
  block.lineTwoY = 1;
  block.squareLeftX = X/2 -1;
  block.squareRightX = X/2;

  mat[block.lineOneY][block.squareLeftX] = blocChar;
  mat[block.lineOneY][block.squareRightX] = blocChar;
  mat[block.lineTwoY][block.squareLeftX] = blocChar;
  mat[block.lineTwoY][block.squareRightX] = blocChar;
}

void zeee(char mat[Y][X]) {
  ZDef block;
  char blocChar = 'x';

  block.lineOneY = 0;
  block.lineTwoY = 1;
  block.lineThreeY = 2;
  block.ZLeftX = X/2 -2;
  block.ZLeftTwoX = X/2 -1;
  block.ZMiddleX = X/2;
  block.ZRightX = X/2 +1;
  block.ZRightTwoX = X/2 +2;

  mat[block.lineOneY][block.ZLeftX] = blocChar;
  mat[block.lineOneY][block.ZLeftTwoX] = blocChar;
  mat[block.lineOneY][block.ZMiddleX] = blocChar;
  mat[block.lineOneY][block.ZRightX] = blocChar;
  mat[block.lineOneY][block.ZRightTwoX] = blocChar;

  mat[block.lineTwoY][block.ZRightX] = blocChar;
  mat[block.lineTwoY][block.ZMiddleX] = blocChar;

  mat[block.lineThreeY][block.ZLeftX] = blocChar;
  mat[block.lineThreeY][block.ZLeftTwoX] = blocChar;
  mat[block.lineThreeY][block.ZMiddleX] = blocChar;
  mat[block.lineThreeY][block.ZRightX] = blocChar;
  mat[block.lineThreeY][block.ZRightTwoX] = blocChar;
}

void leee(char mat[Y][X]) {
  LDef block;
  char blocChar = 'x';

  block.LLeftX = X/2 -1;
  block.LMiddleX = X/2;
  block.LRightX = X/2 +1;
  block.lineOneY = 0;
  block.lineTwoY = 1;
  block.lineThreeY = 2;

  mat[block.lineOneY][block.LLeftX] = blocChar;
  mat[block.lineTwoY][block.LLeftX] = blocChar;
  mat[block.lineThreeY][block.LLeftX] = blocChar;

  mat[block.lineThreeY][block.LMiddleX] = blocChar;
  mat[block.lineThreeY][block.LRightX] = blocChar;
}

void jeee(char mat[Y][X]) {
  JDef block;
  char blocChar = 'x';

  block.JLeftX = X/2 -1;
  block.JMiddleX = X/2;
  block.JRightX = X/2 +1;
  block.lineOneY = 0;
  block.lineTwoY = 1;
  block.lineThreeY = 2;

  mat[block.lineOneY][block.JLeftX] = blocChar;
  mat[block.lineOneY][block.JMiddleX] = blocChar;
  mat[block.lineOneY][block.JRightX] = blocChar;

  mat[block.lineTwoY][block.JRightX] = blocChar;
  mat[block.lineTwoY][block.JRightX] = blocChar;

  mat[block.lineThreeY][block.JRightX] = blocChar;
  mat[block.lineThreeY][block.JMiddleX] = blocChar;
  mat[block.lineThreeY][block.JLeftX] = blocChar;
}

void teee(char mat[Y][X]) {
  TDef block;
  char blocChar = 'x';

  block.TLeftX = X/2 -1;
  block.TMiddleX = X/2;
  block.TRightX = X/2 +1;
  block.lineOneY = 0;
  block.lineTwoY = 1;
  block.lineThreeY = 2;

  mat[block.lineOneY][block.TLeftX] = blocChar;
  mat[block.lineOneY][block.TMiddleX] = blocChar;
  mat[block.lineOneY][block.TRightX] = blocChar;

  mat[block.lineOneY][block.TMiddleX] = blocChar;
  mat[block.lineTwoY][block.TMiddleX] = blocChar;
  mat[block.lineThreeY][block.TMiddleX] = blocChar;
}

void iail(char mat[Y][X]) {
  IDef block;
  char blocChar = 'x';

  block.IMiddleX = X/2;
  block.lineOneY = 0;
  block.lineTwoY = 1;
  block.lineThreeY = 2;


  mat[block.lineOneY][block.IMiddleX] = blocChar;
  mat[block.lineTwoY][block.IMiddleX] = blocChar;
  mat[block.lineThreeY][block.IMiddleX] = blocChar;
}

void putBlockInMat(int randomNumber,char mat[Y][X]){
  switch (randomNumber) {
    case 0: square(mat);
      break;
    case 1: zeee(mat);
      break;
    case 2: leee(mat);
      break;
    case 3: jeee(mat);
      break;
    case 4: teee(mat);
      break;
    case 5: iail(mat);
      break;
    default: errorHandler(1);
      break;
  }
}

//On recopie l'ancienne matrice
void recopyOldMat(char mat[Y][X]){
  for (int i = 0; i < Y-1; i++) {
    for (int j = 0; j < X-1; j++) {
      switch (mat[i][j]) {
        case 'x': mat[i][j] = 'o';
        break;
        case 'o': break;
        case '#': break;
        case '_': break;
        default: mat[i][j] =' ';
      }
    }
  }
}
