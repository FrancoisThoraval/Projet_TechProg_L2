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
  int randomNumber = rand() %6;
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

void Affiche(char mat[Y][X]) {
  printf("\n");
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      printf("%c",mat[i][j]);
    }
    printf("\n");
  }
}

// Designs des blocs
void square(char mat[Y][X], int isSet) {
  extern squareDef Squareblock;
  char blocChar = 'x';
  if (isSet == 1){
    Squareblock.lineOneY = 0;
    Squareblock.lineTwoY = 1;
    Squareblock.squareLeftX = X/2 -1;
    Squareblock.squareRightX = X/2;
  }
  mat[Squareblock.lineOneY][Squareblock.squareLeftX] = blocChar;
  mat[Squareblock.lineOneY][Squareblock.squareRightX] = blocChar;
  mat[Squareblock.lineTwoY][Squareblock.squareLeftX] = blocChar;
  mat[Squareblock.lineTwoY][Squareblock.squareRightX] = blocChar;
}

void zeee(char mat[Y][X], int isSet) {
  extern ZDef Zblock;
  char blocChar = 'x';
  if (isSet == 1){
    Zblock.lineOneY = 0;
    Zblock.lineTwoY = 1;
    Zblock.lineThreeY = 2;
    Zblock.lineFourY =3;
    Zblock.ZLeftX = X/2 -1;
    Zblock.ZMiddleX = X/2;
    Zblock.ZRightX = X/2 +1;
  }

  mat[Zblock.lineOneY][Zblock.ZLeftX] = blocChar;
  mat[Zblock.lineOneY][Zblock.ZMiddleX] = blocChar;
  mat[Zblock.lineOneY][Zblock.ZRightX] = blocChar;

  mat[Zblock.lineTwoY][Zblock.ZMiddleX] = blocChar;
  mat[Zblock.lineThreeY][Zblock.ZLeftX] = blocChar;

  mat[Zblock.lineFourY][Zblock.ZLeftX] = blocChar;
  mat[Zblock.lineFourY][Zblock.ZMiddleX] = blocChar;
  mat[Zblock.lineFourY][Zblock.ZRightX] = blocChar;
}

void leee(char mat[Y][X], int isSet) {
  extern LDef Lblock;
  char blocChar = 'x';
  if (isSet == 1){
    Lblock.LLeftX = X/2 -1;
    Lblock.LMiddleX = X/2;
    Lblock.LRightX = X/2 +1;
    Lblock.lineOneY = 0;
    Lblock.lineTwoY = 1;
    Lblock.lineThreeY = 2;
  }
  mat[Lblock.lineOneY][Lblock.LLeftX] = blocChar;
  mat[Lblock.lineTwoY][Lblock.LLeftX] = blocChar;
  mat[Lblock.lineThreeY][Lblock.LLeftX] = blocChar;

  mat[Lblock.lineThreeY][Lblock.LMiddleX] = blocChar;
  mat[Lblock.lineThreeY][Lblock.LRightX] = blocChar;
}

void jeee(char mat[Y][X], int isSet) {
  extern JDef Jblock;
  char blocChar = 'x';
  if (isSet == 1){
    Jblock.JLeftX = X/2 -1;
    Jblock.JMiddleX = X/2;
    Jblock.JRightX = X/2 +1;
    Jblock.lineOneY = 0;
    Jblock.lineTwoY = 1;
    Jblock.lineThreeY = 2;
  }
  mat[Jblock.lineOneY][Jblock.JLeftX] = blocChar;
  mat[Jblock.lineOneY][Jblock.JMiddleX] = blocChar;
  mat[Jblock.lineOneY][Jblock.JRightX] = blocChar;

  mat[Jblock.lineTwoY][Jblock.JRightX] = blocChar;
  mat[Jblock.lineTwoY][Jblock.JRightX] = blocChar;

  mat[Jblock.lineThreeY][Jblock.JRightX] = blocChar;
  mat[Jblock.lineThreeY][Jblock.JMiddleX] = blocChar;
  mat[Jblock.lineThreeY][Jblock.JLeftX] = blocChar;
}

void teee(char mat[Y][X], int isSet) {
  extern TDef Tblock;
  char blocChar = 'x';
  if (isSet == 1){
    Tblock.TLeftX = X/2 -1;
    Tblock.TMiddleX = X/2;
    Tblock.TRightX = X/2 +1;
    Tblock.lineOneY = 0;
    Tblock.lineTwoY = 1;
    Tblock.lineThreeY = 2;
  }
  mat[Tblock.lineOneY][Tblock.TLeftX] = blocChar;
  mat[Tblock.lineOneY][Tblock.TMiddleX] = blocChar;
  mat[Tblock.lineOneY][Tblock.TRightX] = blocChar;

  mat[Tblock.lineOneY][Tblock.TMiddleX] = blocChar;
  mat[Tblock.lineTwoY][Tblock.TMiddleX] = blocChar;
  mat[Tblock.lineThreeY][Tblock.TMiddleX] = blocChar;
}

void iail(char mat[Y][X], int isSet) {
  extern IDef Iblock;
  char blocChar = 'x';
  if (isSet == 1){
    Iblock.IMiddleX = X/2;
    Iblock.lineOneY = 0;
    Iblock.lineTwoY = 1;
    Iblock.lineThreeY = 2;
  }


  mat[Iblock.lineOneY][Iblock.IMiddleX] = blocChar;
  mat[Iblock.lineTwoY][Iblock.IMiddleX] = blocChar;
  mat[Iblock.lineThreeY][Iblock.IMiddleX] = blocChar;
}

void seee(char mat[Y][X], int isSet) {
  extern SDef Sblock;
  char blocChar = 'x';
  if (isSet == 1){
    Sblock.SLeftX = X/2 -1;
    Sblock.SMiddleX = X/2;
    Sblock.SRightX = X/2 +1;
    Sblock.lineOneY = 0;
    Sblock.lineTwoY = 1;
    Sblock.lineThreeY = 2;
    Sblock.lineFourY = 3;
  }

  mat[Sblock.lineOneY][Sblock.SRightX] = blocChar;
  mat[Sblock.lineOneY][Sblock.SMiddleX] = blocChar;
  mat[Sblock.lineOneY][Sblock.SLeftX] = blocChar;

  mat[Sblock.lineTwoY][Sblock.SLeftX] = blocChar;

  mat[Sblock.lineThreeY][Sblock.SRightX] = blocChar;

  mat[Sblock.lineFourY][Sblock.SRightX] = blocChar;
  mat[Sblock.lineFourY][Sblock.SMiddleX] = blocChar;
  mat[Sblock.lineFourY][Sblock.SLeftX] = blocChar;
}

void putBlockInMat(int randomNumber,char mat[Y][X], int isSet){
  switch (randomNumber) {
    case 0: square(mat, isSet);
      break;
    case 1: zeee(mat, isSet);
      break;
    case 2: leee(mat, isSet);
      break;
    case 3: jeee(mat, isSet);
      break;
    case 4: teee(mat, isSet);
      break;
    case 5: iail(mat, isSet);
      break;
    case 6: seee(mat, isSet);
      break;
    default: errorHandler(1);
      break;
  }
}

void matrixMovement(char mat[Y][X], int typeOfBlock){
  char newMat[Y][X];
  initMatrix(newMat);
  putBlockInMat(typeOfBlock,newMat,0);
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
