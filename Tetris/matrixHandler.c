#include "matrixHandler.h"
#include "movementHandler.h"
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

int gameOver(char mat[Y][X],int mode, int difficulty_O_Meter){
  int good=0;
  if (mode == 0) {
    return (mat[1][X/2] == 'o');
  }else{
    for (int i = 0; i < Y; i++) {
      for (int j = 0; j < X; j++) {
        if (mat[i][j]=='o') {
          good++;
        }
      }
    }
    return((mat[1][X/2] == 'o')||(good==0));
  }
}

int randomize(int nbValues){
  //On tire au sort un nombre qui correspondra a la forme du bloc

  int randomNumber = rand() %nbValues;
  return randomNumber;
}

void initMatrix(char mat[Y][X]){
  // On cree les contours de la matrice
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      mat[i][j]=' ';
    }
  }
}

void fillMatrix(char mat[Y][X], int difficulty_O_Meter){
  int random;
  for (int i = Y-difficulty_O_Meter-1; i<Y; i++) {
    for (int j = 0; j < X-1; j++) {
      random = randomize(2);
      if (random == 0) {
        mat[i][j] = 'o';
      }
    }
  }
}

void show(char mat[Y][X],int score, int line, int tries) {
  erase();
  refresh();
  showScore(score, line, tries);
  for (int i = 0; i < Y; i++) {
    for (int j = -1; j < X; j++) {
      if ((j==-1 )||(j==X-1)) {
        attron(COLOR_PAIR(randomize(4)+1));
        printw("#");
        attron(COLOR_PAIR(7));
      }
      if ((i==Y-1) && (j!=X-1) && (j!=-1)) {
        attron(COLOR_PAIR(randomize(4)+1));
        printw("* ");
        attron(COLOR_PAIR(7));
      }
      if ((i!= Y-1) && (i!= -1) && (j!=X)&& (j!=-1)) {
        printw("%c ",mat[i][j]);
      }
    }
    printw("\n");
  }
}

// Initialisation des coordonnées de la structure
void initCoordStruct(coordBlock *block){

  block->lineOneY = 0;
  block->lineTwoY = 1;
  block->lineThreeY = 2;
  block->lineFourY = 3;

  block->leftX = X/2 -1;
  block->middleX = X/2;
  block->rightX = X/2 +1;
}

// Designs des blocs
void square(char mat[Y][X], int isSet, coordBlock *block, char blocChar) {
  mat[block->lineOneY][block->leftX] = blocChar;
  mat[block->lineOneY][block->middleX] = blocChar;
  mat[block->lineTwoY][block->leftX] = blocChar;
  mat[block->lineTwoY][block->middleX] = blocChar;
}

void zeee(char mat[Y][X], int isSet, int position, coordBlock *block, char blocChar) {
  if ((position == 0)||(position == 2)||(position == -2)) {
    mat[block->lineTwoY][block->leftX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineThreeY][block->rightX] = blocChar;

    mat[block->lineThreeY][block->middleX] = blocChar;
  }
  if ((position == 1)||(position == -1)) {
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;

    mat[block->lineTwoY][block->leftX] = blocChar;
    mat[block->lineThreeY][block->leftX] = blocChar;
  }
}

void leee(char mat[Y][X], int isSet, int position, coordBlock *block, char blocChar) {
  if (position == 0) {
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineThreeY][block->middleX] = blocChar;

    mat[block->lineThreeY][block->rightX] = blocChar;
  }
  if (position == 1) {
    mat[block->lineTwoY][block->rightX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->leftX] = blocChar;

    mat[block->lineThreeY][block->leftX] = blocChar;
  }
  if (position == -1) {
    mat[block->lineTwoY][block->rightX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->leftX] = blocChar;

    mat[block->lineOneY][block->rightX] = blocChar;
  }
  if ((position == 2)||(position == -2)){
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineThreeY][block->middleX] = blocChar;

    mat[block->lineOneY][block->leftX] = blocChar;
  }
}

void jeee(char mat[Y][X], int isSet, int position, coordBlock *block, char blocChar) {
  if (position == 0) {
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineThreeY][block->middleX] = blocChar;

    mat[block->lineThreeY][block->leftX] = blocChar;
  }
  if (position == -1) {
    mat[block->lineTwoY][block->rightX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->leftX] = blocChar;

    mat[block->lineThreeY][block->rightX] = blocChar;
  }
  if (position == 1) {
    mat[block->lineTwoY][block->rightX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->leftX] = blocChar;

    mat[block->lineOneY][block->leftX] = blocChar;
  }
  if ((position == 2)||(position == -2)){
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineThreeY][block->middleX] = blocChar;

    mat[block->lineOneY][block->rightX] = blocChar;
  }
}

void teee(char mat[Y][X], int isSet, int position, coordBlock *block, char blocChar) {
  if (position == 0) {
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;

    mat[block->lineOneY][block->leftX] = blocChar;
    mat[block->lineOneY][block->rightX] = blocChar;
  }
  if (position == 1) {
    mat[block->lineTwoY][block->leftX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;

    mat[block->lineOneY][block->leftX] = blocChar;
    mat[block->lineThreeY][block->leftX] = blocChar;
  }
  if (position == -1) {
    mat[block->lineTwoY][block->rightX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;

    mat[block->lineOneY][block->rightX] = blocChar;
    mat[block->lineThreeY][block->rightX] = blocChar;
  }
  if ((position == 2)||(position == -2)){
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;

    mat[block->lineTwoY][block->leftX] = blocChar;
    mat[block->lineTwoY][block->rightX] = blocChar;
  }
}

void iail(char mat[Y][X], int isSet, int position, coordBlock *block, char blocChar) {
  if ((position == 0)||(position == 2)||(position == -2)) {
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineThreeY][block->middleX] = blocChar;
    mat[block->lineFourY][block->middleX] = blocChar;
  }
  if ((position == 1)||(position == -1)) {
    mat[block->lineTwoY][block->rightX] = blocChar;
    mat[block->lineTwoY][block->rightX+1] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->leftX] = blocChar;
  }

}

void seee(char mat[Y][X], int isSet, int position, coordBlock *block, char blocChar) {
    if ((position == 0)||(position == 2)||(position == -2)) {
    mat[block->lineThreeY][block->leftX] = blocChar;
    mat[block->lineThreeY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->rightX] = blocChar;

    mat[block->lineTwoY][block->middleX] = blocChar;
  }
  if ((position == 1)||(position == -1)) {
    mat[block->lineOneY][block->middleX] = blocChar;
    mat[block->lineTwoY][block->middleX] = blocChar;

    mat[block->lineTwoY][block->rightX] = blocChar;
    mat[block->lineThreeY][block->rightX] = blocChar;
  }
}

void putBlockInMat(int randomNumber,char mat[Y][X], int isSet, int position, coordBlock *block, char blocChar){
  switch (randomNumber) {
    case 0: square(mat, isSet, block, blocChar);
      break;
    case 1: zeee(mat, isSet, position, block, blocChar);
      break;
    case 2: leee(mat, isSet, position, block, blocChar);
      break;
    case 3: jeee(mat, isSet, position, block, blocChar);
      break;
    case 4: teee(mat, isSet,position, block, blocChar);
      break;
    case 5: iail(mat, isSet, position, block, blocChar);
      break;
    case 6: seee(mat, isSet, position, block, blocChar);
      break;
    default: errorHandler(1);
      break;
  }
}

coordBlock copyBlock(coordBlock *block){
  coordBlock copy;

  copy.leftX = block->leftX;
  copy.middleX = block->middleX;
  copy.rightX = block->rightX;
  copy.lineOneY = block->lineOneY;
  copy.lineTwoY = block->lineTwoY;
  copy.lineThreeY = block->lineThreeY;
  copy.lineFourY = block->lineFourY;
  return copy;
}

void matrixMovement(char mat[Y][X], int typeOfBlock, int position, coordBlock *block){
  char newMat[Y][X];
  char blocChar= 'x';
  coordBlock previewBlock = copyBlock(block);
  int isPossible = canMoveV(mat,&previewBlock);
  initMatrix(newMat);
  putBlockInMat(typeOfBlock,newMat,0,position, block, blocChar);
  // directDown(mat,typeOfBlock,position, &previewBlock);     //Pour une raison obscure, si on appelle la fonction, on obtient une seg fault parfois
  while (isPossible == 0) {                                   //si on recopie tout, plus de seg fault !?
    previewBlock.lineOneY ++;
    previewBlock.lineTwoY ++;
    previewBlock.lineThreeY ++;
    previewBlock.lineFourY ++;
    matrixMovement(mat,typeOfBlock,position, &previewBlock);
    isPossible = canMoveV(mat,&previewBlock);
  }
  if ((previewBlock.lineOneY-1 >= block->lineFourY)) {
    blocChar= '\'';
    putBlockInMat(typeOfBlock,newMat,0,position, &previewBlock, blocChar);
  }

  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      if (mat[i][j] == 'o') {
        newMat[i][j] = 'o';
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
        default: mat[i][j] =' ';
      }
    }
  }
}
