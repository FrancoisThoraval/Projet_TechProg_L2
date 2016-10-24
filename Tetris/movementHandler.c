#include "movementHandler.h"
#include "matrixHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// TODO: movementHandler:
// - check type du bloc
// - en fonction du type de bloc observer l'evolution des points critiques de chaque bloc
//    ex: coin bas droite du carré si on peut aller a droite ou descendre
// - ecouter les touches de l'utilisateur pour recuperer les deplacements
// - effectuer le deplacement

int squareCanMove(char mat[Y][X]){
  extern squareDef Sblock;
  int isPossibleR=0;
  int isPossibleD=0;
  int isPossibleL=0;
  int isPossible;
  if ((mat[Sblock.lineTwoY +1][Sblock.squareRightX] == 'o')||(mat[Sblock.lineTwoY +1][Sblock.squareLeftX] == 'o') || (mat[Sblock.lineTwoY +1][Sblock.squareLeftX] == '#')) {
    isPossibleD = 1;
  }
  if ((mat[Sblock.lineTwoY][Sblock.squareLeftX -1] == 'o') || (mat[Sblock.lineTwoY][Sblock.squareLeftX -1] == '#')) {
    isPossibleL = 1;
  }
  if ((mat[Sblock.lineTwoY][Sblock.squareRightX +1] == 'o') || (mat[Sblock.lineTwoY][Sblock.squareRightX +1] == '#')) {
    isPossibleR = 1;
  }
  isPossible = isPossibleR + isPossibleL + isPossibleD;
  return isPossible;
}

int ZCanMove(char mat[Y][X]){
  extern ZDef Zblock;
  int isPossibleRTop=0;
  int isPossibleD=0;
  int isPossibleLTop=0;
  int isPossibleLMid=0;
  int isPossibleLBottom=0;
  int isPossibleRBottom=0;
  int isPossibleRMid=0;
  int isPossible;

  if ((mat[Zblock.lineOneY +1][Zblock.ZLeftTwoX]=='o')||(mat[Zblock.lineOneY +1][Zblock.ZLeftX]=='o')) {
    isPossibleD =1;
  }
  if ((mat[Zblock.lineOneY][Zblock.ZLeftTwoX -1]=='o')||(mat[Zblock.lineOneY][Zblock.ZLeftTwoX -1]=='#')) {
    isPossibleLTop=1;
  }
  if ((mat[Zblock.lineOneY][Zblock.ZRightTwoX +1]=='o')||(mat[Zblock.lineOneY][Zblock.ZRightX +1]=='#')) {
    isPossibleRTop=1;
  }
  if (mat[Zblock.lineTwoY][Zblock.ZMiddleX -1]=='o') {
    isPossibleLMid=1;
  }
  if ((mat[Zblock.lineThreeY][Zblock.ZLeftTwoX -1] =='o')||(mat[Zblock.lineThreeY][Zblock.ZLeftTwoX -1] =='#')) {
    isPossibleLBottom = 1;
  }
  if ((mat[Zblock.lineThreeY -1][Zblock.ZLeftTwoX] =='#')||(mat[Zblock.lineThreeY -1][Zblock.ZLeftX] =='o')||(mat[Zblock.lineThreeY -1][Zblock.ZMiddleX] =='o')||(mat[Zblock.lineThreeY -1][Zblock.ZRightX] =='o')||(mat[Zblock.lineThreeY -1][Zblock.ZRightTwoX] =='o')) {
    isPossibleD =1;
  }
  if ((mat[Zblock.lineThreeY][Zblock.ZRightTwoX +1] =='o')||(mat[Zblock.lineThreeY][Zblock.ZRightTwoX +1] =='#')) {
    isPossibleRBottom = 1;
  }
  if (mat[Zblock.lineTwoY][Zblock.ZRightX +1]=='o') {
    isPossibleRMid=1;
  }
  isPossible = isPossibleRTop + isPossibleRMid + isPossibleRBottom + isPossibleLBottom + isPossibleLTop + isPossibleLMid + isPossibleD;
  return isPossible;
}

int LCanMove(char mat[Y][X]){
  extern LDef Lblock;
  int isPossibleD=0;
  int isPossibleL=0;
  int isPossibleR=0;
  int isPossibleBottomR=0;
  int isPossible;

  if ((mat[Lblock.lineThreeY +1][Lblock.LLeftX]=='o')||(mat[Lblock.lineThreeY +1][Lblock.LLeftX]=='#')||(mat[Lblock.lineThreeY +1][Lblock.LMiddleX]=='o')||((mat[Lblock.lineThreeY +1][Lblock.LMiddleX]=='#'))) {
    isPossibleD =1;
  }
  if ((mat[Lblock.lineOneY][Lblock.LLeftX -1]=='o')||(mat[Lblock.lineOneY][Lblock.LLeftX -1]=='#')) {
    isPossibleL =1;
  }
  if ((mat[Lblock.lineOneY][Lblock.LLeftX +1]=='o')||(mat[Lblock.lineOneY][Lblock.LLeftX +1]=='#')) {
    isPossibleR =1;
  }
  if ((mat[Lblock.lineThreeY][Lblock.LLeftX +1]=='o')||(mat[Lblock.lineThreeY][Lblock.LLeftX +1]=='#')) {
    isPossibleBottomR =1;
  }

  isPossible = isPossibleD + isPossibleR + isPossibleL + isPossibleBottomR;
  return isPossible;
}

int JCanMove(char mat[Y][X]){
  extern JDef Jblock;

  int isPossibleD =0;
  int isPossibleBottomL =0;
  int isPossibleMidL =0;
  int isPossibleTopL =0;
  int isPossibleBottomR=0;
  int isPossible;

  if ((mat[Jblock.lineThreeY +1][Jblock.JLeftX] == '#')||(mat[Jblock.lineThreeY +1][Jblock.JLeftX] == 'o')||(mat[Jblock.lineThreeY][Jblock.JMiddleX] == 'o')||(mat[Jblock.lineThreeY][Jblock.JRightX] = 'o')) {
    isPossibleD =1;
  }
  if ((mat[Jblock.lineThreeY][Jblock.JLeftX -1] == '#')||(mat[Jblock.lineThreeY][Jblock.JLeftX -1] == 'o')) {
    isPossibleBottomL = 1;
  }
  if ((mat[Jblock.lineOneY][Jblock.JLeftX -1] == '#')||(mat[Jblock.lineOneY][Jblock.JLeftX -1] == 'o')) {
    isPossibleTopL = 1;
  }
  if (mat[Jblock.lineTwoY][Jblock.JRightX -1] == 'o') {
    isPossibleMidL = 1;
  }
  if ((mat[Jblock.lineThreeY][Jblock.JRightX +1] == '#')||(mat[Jblock.lineThreeY][Jblock.JRightX +1] == 'o')) {
    isPossibleBottomR = 1;
  }
  isPossible = isPossibleBottomR + isPossibleMidL + isPossibleTopL + isPossibleBottomL + isPossibleD;
  return isPossible;
}

int TCanMove(char mat[Y][X]){
  extern TDef Tblock;

  int isPossibleBottomL = 0;
  int isPossibleBottomR = 0;
  int isPossibleBottomD = 0;
  int isPossibleTopL =0;
  int isPossibleTopR =0;
  int isPossibleTopLD =0;
  int isPossibleTopRD =0;
  int isPossible;

  if ((mat[Tblock.lineThreeY +1][Tblock.TMiddleX] == '#')||(mat[Tblock.lineThreeY +1][Tblock.TMiddleX] == 'o')) {
    isPossibleBottomD = 1;
  }
  if ((mat[Tblock.lineThreeY][Tblock.TMiddleX -1] == '#')||(mat[Tblock.lineThreeY][Tblock.TMiddleX -1] == 'o')) {
    isPossibleBottomL = 1;
  }
  if ((mat[Tblock.lineThreeY][Tblock.TMiddleX +1] == '#')||(mat[Tblock.lineThreeY][Tblock.TMiddleX +1] == 'o')) {
    isPossibleBottomR = 1;
  }
  if ((mat[Tblock.lineOneY][Tblock.TLeftX -1] == '#')||(mat[Tblock.lineOneY][Tblock.TLeftX -1] == 'o')) {
    isPossibleTopL = 1;
  }
  if ((mat[Tblock.lineOneY +1][Tblock.TLeftX] == '#')||(mat[Tblock.lineOneY +1][Tblock.TLeftX] == 'o')) {
    isPossibleTopLD = 1;
  }
  if ((mat[Tblock.lineOneY][Tblock.TRightX +1] == '#')||(mat[Tblock.lineOneY][Tblock.TRightX +1] == 'o')) {
    isPossibleTopR = 1;
  }
  if ((mat[Tblock.lineOneY +1][Tblock.TRightX] == '#')||(mat[Tblock.lineOneY +1][Tblock.TRightX] == 'o')) {
    isPossibleTopRD = 1;
  }

  isPossible = isPossibleTopRD + isPossibleTopR + isPossibleTopLD + isPossibleTopL + isPossibleBottomR + isPossibleBottomD + isPossibleBottomL;
  return isPossible;
}

int ICanMove(char mat[Y][X]){
  extern IDef Iblock;

  int isPossibleR =0;
  int isPossibleL =0;
  int isPossibleD =0;
  int isPossible;

  if ((mat[Iblock.lineThreeY +1][Iblock.IMiddleX] == '#')||(mat[Iblock.lineThreeY +1][Iblock.IMiddleX] == 'o')) {
    isPossibleD = 1;
  }
  if ((mat[Iblock.lineThreeY][Iblock.IMiddleX +1] == '#')||(mat[Iblock.lineThreeY][Iblock.IMiddleX +1] == 'o')) {
    isPossibleR = 1;
  }
  if ((mat[Iblock.lineThreeY][Iblock.IMiddleX -1] == '#')||(mat[Iblock.lineThreeY][Iblock.IMiddleX -1] == 'o')) {
    isPossibleL = 1;
  }
  isPossible = isPossibleL + isPossibleR + isPossibleD;
  return isPossible;
}

int canMove(char mat[Y][X], int typeOfBlock){
  // extern IDef Iblock;
  int isPossible =0;
  switch (typeOfBlock) {
    case 0: isPossible = squareCanMove(mat);
      break;
    case 1: isPossible = ZCanMove(mat);
      break;
    case 2: isPossible = LCanMove(mat);
      break;
    case 3: isPossible = JCanMove(mat);
      break;
    case 4: isPossible = TCanMove(mat);
      break;
    case 5: isPossible = ICanMove(mat);
      break;
  }

  return isPossible;
}

int getNextMovement(){
  // On passe le terminal en mode raw pour ne pas avoir a appuyer sur entrée a chaque fois
  system ("/bin/stty raw");
  int nextMovement= 0;
  int c = getchar();
  switch (c) {
    case 'q': nextMovement = 1;
      printf("A gauche \n\n");
      break;
    case 's': nextMovement = 2;
      printf("En bas\n\n");
      break;
    case 'd': nextMovement = 3;
      printf("A droite\n\n");
      break;
    /*case 'z': printf("En haut\n\n");
      break;*/
  }
  // On repasse le terminal en mode normal
  system ("/bin/stty cooked");
  return nextMovement;
}

void squareMoveLeft(){
  extern squareDef Sblock;

  Sblock.squareLeftX --;
  Sblock.squareRightX --;
}

void squareMoveDown(){
  extern squareDef Sblock;

  Sblock.lineOneY ++;
  Sblock.lineTwoY ++;
}

void squareMoveRight(){
  extern squareDef Sblock;

  Sblock.squareLeftX ++;
  Sblock.squareRightX ++;
}

void Move(char mat[Y][X], int movement, int typeOfBlock){
  switch (typeOfBlock) {
    case 0:
      switch (movement) {
        case 1: squareMoveLeft();
          matrixMovement(mat,typeOfBlock);
          break;
        case 2: squareMoveDown();
          matrixMovement(mat,typeOfBlock);
          break;
        case 3: squareMoveRight();
          matrixMovement(mat,typeOfBlock);
          break;
      }
    break;
  }
}

int movementHandler(char mat[Y][X], int randomNumber){
  int noConflict =0; //Determine si le bloc ne peut plus descendre + bas

  return noConflict;
}
