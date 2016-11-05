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

int gameOver(char mat[Y][X]){
  return ((mat[1][X/2] == 'x')||(mat[1][X/2] == 'o'));
}

int randomize(){
  //On tire au sort un nombre qui correspondra a la forme du bloc
  srand(time(NULL));
  int randomNumber = rand() %7;
  return randomNumber;
}

void initMatrix(char mat[Y][X]){
  // On cree les contours de la matrice
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      mat[i][j]=' ';
      if (i==Y-1) {
        mat[i][j]='*';
      }
      if ((j==0)||(j==X-1)) {
        mat[i][j]='#';
      }
    }
  }
}

void Affiche(char mat[Y][X],int score, int line) {
  for (int i = 0; i < 30; i++) {
    printf("\n");
  }
  showScore(score, line);
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      printf("%c ",mat[i][j]);
    }
    printf("\n");
  }
}

// Initialisation des coordonnées de la structure
void initCoordStruct(){
  extern coordBlock block;

  block.lineOneY = 0;
  block.lineTwoY = 1;
  block.lineThreeY = 2;
  block.lineFourY = 3;

  block.leftX = X/2 -1;
  block.middleX = X/2;
  block.rightX = X/2 +1;
}

// Designs des blocs
void square(char mat[Y][X], int isSet) {
  extern coordBlock block;
  char blocChar = 'x';

  mat[block.lineOneY][block.leftX] = blocChar;
  mat[block.lineOneY][block.middleX] = blocChar;
  mat[block.lineTwoY][block.leftX] = blocChar;
  mat[block.lineTwoY][block.middleX] = blocChar;
}

void zeee(char mat[Y][X], int isSet, int position) {
  extern coordBlock block;
  char blocChar = 'x';

  if ((position == 0)||(position == 2)||(position == -2)) {
    mat[block.lineTwoY][block.leftX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineThreeY][block.rightX] = blocChar;

    mat[block.lineThreeY][block.middleX] = blocChar;
  }
  if ((position == 1)||(position == -1)) {
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;

    mat[block.lineTwoY][block.leftX] = blocChar;
    mat[block.lineThreeY][block.leftX] = blocChar;
  }
}

void leee(char mat[Y][X], int isSet, int position) {
  extern coordBlock block;
  char blocChar = 'x';

  if (position == 0) {
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineThreeY][block.middleX] = blocChar;

    mat[block.lineThreeY][block.rightX] = blocChar;
  }
  if (position == 1) {
    mat[block.lineTwoY][block.rightX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.leftX] = blocChar;

    mat[block.lineThreeY][block.leftX] = blocChar;
  }
  if (position == -1) {
    mat[block.lineTwoY][block.rightX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.leftX] = blocChar;

    mat[block.lineOneY][block.rightX] = blocChar;
  }
  if ((position == 2)||(position == -2)){
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineThreeY][block.middleX] = blocChar;

    mat[block.lineOneY][block.leftX] = blocChar;
  }
}

void jeee(char mat[Y][X], int isSet, int position) {
  extern coordBlock block;
  char blocChar = 'x';

  if (position == 0) {
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineThreeY][block.middleX] = blocChar;

    mat[block.lineThreeY][block.leftX] = blocChar;
  }
  if (position == -1) {
    mat[block.lineTwoY][block.rightX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.leftX] = blocChar;

    mat[block.lineThreeY][block.rightX] = blocChar;
  }
  if (position == 1) {
    mat[block.lineTwoY][block.rightX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.leftX] = blocChar;

    mat[block.lineOneY][block.leftX] = blocChar;
  }
  if ((position == 2)||(position == -2)){
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineThreeY][block.middleX] = blocChar;

    mat[block.lineOneY][block.rightX] = blocChar;
  }
}

void teee(char mat[Y][X], int isSet, int position) {
  extern coordBlock block;

  char blocChar = 'x';

  if (position == 0) {
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;

    mat[block.lineOneY][block.leftX] = blocChar;
    mat[block.lineOneY][block.rightX] = blocChar;
  }
  if (position == 1) {
    mat[block.lineTwoY][block.leftX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;

    mat[block.lineOneY][block.leftX] = blocChar;
    mat[block.lineThreeY][block.leftX] = blocChar;
  }
  if (position == -1) {
    mat[block.lineTwoY][block.rightX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;

    mat[block.lineOneY][block.rightX] = blocChar;
    mat[block.lineThreeY][block.rightX] = blocChar;
  }
  if ((position == 2)||(position == -2)){
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;

    mat[block.lineTwoY][block.leftX] = blocChar;
    mat[block.lineTwoY][block.rightX] = blocChar;
  }
}

void iail(char mat[Y][X], int isSet, int position) {
  extern coordBlock block;
  char blocChar = 'x';

  if ((position == 0)||(position == 2)||(position == -2)) {
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineThreeY][block.middleX] = blocChar;
    mat[block.lineFourY][block.middleX] = blocChar;
  }
  if ((position == 1)||(position == -1)) {
    mat[block.lineTwoY][block.rightX] = blocChar;
    mat[block.lineTwoY][block.rightX+1] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.leftX] = blocChar;
  }

}

void seee(char mat[Y][X], int isSet, int position) {
  extern coordBlock block;
  char blocChar = 'x';
    if ((position == 0)||(position == 2)||(position == -2)) {
    mat[block.lineThreeY][block.leftX] = blocChar;
    mat[block.lineThreeY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.rightX] = blocChar;

    mat[block.lineTwoY][block.middleX] = blocChar;
  }
  if ((position == 1)||(position == -1)) {
    mat[block.lineOneY][block.middleX] = blocChar;
    mat[block.lineTwoY][block.middleX] = blocChar;

    mat[block.lineTwoY][block.rightX] = blocChar;
    mat[block.lineThreeY][block.rightX] = blocChar;
  }
}

void putBlockInMat(int randomNumber,char mat[Y][X], int isSet, int position){
  switch (randomNumber) {
    case 0: square(mat, isSet);
      break;
    case 1: zeee(mat, isSet, position);
      break;
    case 2: leee(mat, isSet, position);
      break;
    case 3: jeee(mat, isSet, position);
      break;
    case 4: teee(mat, isSet,position);
      break;
    case 5: iail(mat, isSet, position);
      break;
    case 6: seee(mat, isSet, position);
      break;
    default: errorHandler(1);
      break;
  }
}

void matrixMovement(char mat[Y][X], int typeOfBlock, int position){
  char newMat[Y][X];
  initMatrix(newMat);
  putBlockInMat(typeOfBlock,newMat,0,position);
  for (int i = 0; i < Y-1; i++) {
    for (int j = 0; j < X-1; j++) {

      switch (mat[i][j]) {
        case 'o': newMat[i][j] = 'o';
          break;
        case '#': break;
        case '_': break;
        // default: newMat[i][j] =' ';
      }
    }
  }
  for (int i = 0; i < Y-1; i++) {
    for (int j = 0; j < X-1; j++) {
      mat[i][j] = newMat[i][j];
    }
  }
}

//Quand le bloc est placé on remplace les x par de o
void blockEnd(char mat[Y][X]){
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
