#include "movementHandler.h"
#include "matrixHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


// TODO:
// - Hitbox: A voir avec le temps si c'est bon
// - la touche Z
// - Trouver un moyen de remplacer les ZQSD par ←↓→
// et après ça on aura plus à toucher à ces mouvements putain de bordel !

// Fonctions qui vérifient qu'on peut encore descendre
int squareCanMove(char mat[Y][X]){
  extern squareDef Squareblock;
  int isPossible=0;
  if ((mat[Squareblock.lineTwoY +1][Squareblock.squareRightX] == 'o')||(mat[Squareblock.lineTwoY +1][Squareblock.squareLeftX] == 'o') || (mat[Squareblock.lineTwoY +1][Squareblock.squareLeftX] == '*')) {
    isPossible = 1;
  }
  return isPossible;
}

int ZCanMove(char mat[Y][X],int *position){
  extern ZDef Zblock;
  int isPossible=0;

  if ((*position == 0)||(*position == 2)||(*position == -2)) {
    if ((mat[Zblock.lineTwoY +1][Zblock.ZMiddleX] =='*')||(mat[Zblock.lineTwoY +1][Zblock.ZRightX] =='o')||(mat[Zblock.lineTwoY +1][Zblock.ZMiddleX] =='o')||(mat[Zblock.lineOneY+1][Zblock.ZLeftX]=='o')) {
      isPossible =1;
    }
  }
  if ((*position == 1)||(*position == -1)) {
    if ((mat[Zblock.lineThreeY +1][Zblock.ZLeftX] =='*')||(mat[Zblock.lineTwoY +1][Zblock.ZMiddleX] =='o')||(mat[Zblock.lineThreeY +1][Zblock.ZLeftX] =='o')) {
      isPossible =1;
    }
  }
  return isPossible;
}

int LCanMove(char mat[Y][X],int *position){
  extern LDef Lblock;
  int isPossible=0;
  if ((*position == 0)||(*position == -1)||(*position == 2)||(*position == -2)) {
    if ((mat[Lblock.lineThreeY +1][Lblock.LLeftX]=='o')||(mat[Lblock.lineThreeY +1][Lblock.LLeftX]=='*')||(mat[Lblock.lineThreeY +1][Lblock.LMiddleX]=='o')||((mat[Lblock.lineThreeY +1][Lblock.LRightX]=='o'))) {
      isPossible =1;
    }
  }
  if(*position == 1){
    if ((mat[Lblock.lineThreeY +1][Lblock.LLeftX]=='o')||(mat[Lblock.lineThreeY +1][Lblock.LLeftX]=='*')||(mat[Lblock.lineOneY +1][Lblock.LMiddleX]=='o')||((mat[Lblock.lineOneY +1][Lblock.LRightX]=='o'))) {
      isPossible =1;
    }
  }
  return isPossible;
}

int JCanMove(char mat[Y][X], int *position){
  extern JDef Jblock;

  int isPossible =0;
  if (*position == 0) {
    if ((mat[Jblock.lineThreeY +1][Jblock.JLeftX] == '*')||(mat[Jblock.lineThreeY +1][Jblock.JLeftX] == 'o')||(mat[Jblock.lineThreeY +1][Jblock.JMiddleX] == 'o')||(mat[Jblock.lineThreeY +1][Jblock.JRightX] == 'o')||(mat[Jblock.lineOneY +1][Jblock.JMiddleX] == 'o')||(mat[Jblock.lineOneY +1][Jblock.JLeftX] == 'o')) {
      isPossible =1;
    }
  }
  if (*position == 1) {
    if ((mat[Jblock.lineThreeY +1][Jblock.JLeftX] == '*')||(mat[Jblock.lineThreeY +1][Jblock.JLeftX] == 'o')||(mat[Jblock.lineThreeY +1][Jblock.JMiddleX] == 'o')||(mat[Jblock.lineThreeY +1][Jblock.JRightX] == 'o')) {
      isPossible =1;
    }
  }
  if (*position == -1) {
    if ((mat[Jblock.lineThreeY +1][Jblock.JLeftX] == '*')||(mat[Jblock.lineThreeY +1][Jblock.JLeftX] == 'o')||(mat[Jblock.lineThreeY +1][Jblock.JRightX] == 'o')||(mat[Jblock.lineOneY +1][Jblock.JMiddleX] == 'o')) {
      isPossible =1;
    }
  }
  if ((*position == 2)||(*position == -2)) {
    if ((mat[Jblock.lineThreeY +1][Jblock.JLeftX] == '*')||(mat[Jblock.lineThreeY +1][Jblock.JLeftX] == 'o')||(mat[Jblock.lineThreeY +1][Jblock.JMiddleX] == 'o')||(mat[Jblock.lineThreeY +1][Jblock.JRightX] == 'o')||(mat[Jblock.lineOneY +1][Jblock.JMiddleX] == 'o')||(mat[Jblock.lineOneY +1][Jblock.JRightX] == 'o')) {
      isPossible =1;
    }
  }
  return isPossible;
}

int TCanMove(char mat[Y][X], int *position){
  extern TDef Tblock;

  int isPossible=0;
  if (*position == 0) {
    if ((mat[Tblock.lineThreeY +1][Tblock.TMiddleX] == '*')||(mat[Tblock.lineThreeY +1][Tblock.TMiddleX] == 'o')||(mat[Tblock.lineOneY +1][Tblock.TLeftX] == 'o')||(mat[Tblock.lineOneY +1][Tblock.TRightX] == 'o')) {
      isPossible = 1;
    }
  }
  if (*position == 1) {
    if ((mat[Tblock.lineThreeY +1][Tblock.TRightX] == '*')||(mat[Tblock.lineThreeY +1][Tblock.TRightX] == 'o')||(mat[Tblock.lineTwoY +1][Tblock.TLeftX] == 'o')||(mat[Tblock.lineTwoY +1][Tblock.TMiddleX] == 'o')) {
      isPossible = 1;
    }
  }
  if (*position == -1) {
    if ((mat[Tblock.lineThreeY +1][Tblock.TLeftX] == '*')||(mat[Tblock.lineThreeY +1][Tblock.TLeftX] == 'o')||(mat[Tblock.lineTwoY +1][Tblock.TRightX] == 'o')||(mat[Tblock.lineTwoY +1][Tblock.TMiddleX] == 'o')) {
      isPossible = 1;
    }
  }
  if ((*position == 2)||(*position == -2)) {
    if ((mat[Tblock.lineThreeY +1][Tblock.TLeftX] == '*')||(mat[Tblock.lineThreeY +1][Tblock.TLeftX] == 'o')||(mat[Tblock.lineThreeY +1][Tblock.TRightX] == 'o')||(mat[Tblock.lineThreeY +1][Tblock.TMiddleX] == 'o')) {
      isPossible = 1;
    }
  }
  return isPossible;
}

int ICanMove(char mat[Y][X], int *position){
  extern IDef Iblock;

  int isPossible=0;

  if ((*position == 0)||(*position == 2)||(*position == -2)) {
    if ((mat[Iblock.lineThreeY +1][Iblock.IMiddleX] == '*')||(mat[Iblock.lineThreeY +1][Iblock.IMiddleX] == 'o')) {
      isPossible = 1;
    }
  }
  if ((*position == 1)||(*position == -1)) {
    if ((mat[Iblock.lineTwoY +1][Iblock.IMiddleX-1] == '*')||(mat[Iblock.lineTwoY +1][Iblock.IMiddleX -1] == 'o')||(mat[Iblock.lineTwoY +1][Iblock.IMiddleX] == 'o')||(mat[Iblock.lineTwoY +1][Iblock.IMiddleX +1] == 'o')) {
      isPossible = 1;
    }
  }
  return isPossible;
}

int SCanMove(char mat[Y][X], int *position){
  extern SDef Sblock;

  int isPossible = 0;

  if ((*position == 0)||(*position == 2)||(*position == -2)) {
    if ((mat[Sblock.lineTwoY +1][Sblock.SMiddleX] =='*')||(mat[Sblock.lineTwoY +1][Sblock.SLeftX] =='o')||(mat[Sblock.lineTwoY +1][Sblock.SMiddleX] =='o')||(mat[Sblock.lineOneY+1][Sblock.SRightX]=='o')) {
      isPossible =1;
    }
  }
  if ((*position == 1)||(*position == -1)) {
    if ((mat[Sblock.lineThreeY +1][Sblock.SRightX] =='*')||(mat[Sblock.lineTwoY +1][Sblock.SMiddleX] =='o')||(mat[Sblock.lineThreeY +1][Sblock.SRightX] =='o')) {
      isPossible =1;
    }
  }
  return isPossible;
}

int canMove(char mat[Y][X], int typeOfBlock, int *position){
  // extern IDef Iblock;
  int isPossible =0;
  switch (typeOfBlock) {
    case 0: isPossible = squareCanMove(mat);
      break;
    case 1: isPossible = ZCanMove(mat, position);
      break;
    case 2: isPossible = LCanMove(mat, position);
      break;
    case 3: isPossible = JCanMove(mat, position);
      break;
    case 4: isPossible = TCanMove(mat, position);
      break;
    case 5: isPossible = ICanMove(mat, position);
      break;
    case 6: isPossible = SCanMove(mat, position);
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
    case 'w': nextMovement = 5;
      break;
    case 'x': nextMovement = 6;
      break;
  }
  // On repasse le terminal en mode normal
  system ("/bin/stty cooked");
  return nextMovement;
}


// Square Movements
void squareMoveLeft(){
  extern squareDef Squareblock;
  if ((mat[Squareblock.lineTwoY][Squareblock.squareLeftX -1] != 'o')&&(mat[Squareblock.lineTwoY][Squareblock.squareLeftX -1] != '#')) {
    Squareblock.squareLeftX --;
    Squareblock.squareRightX --;
  }
}

void squareMoveDown(){
  extern squareDef Squareblock;

  Squareblock.lineOneY ++;
  Squareblock.lineTwoY ++;
}

void squareMoveRight(){
  extern squareDef Squareblock;
  if((mat[Squareblock.lineTwoY][Squareblock.squareRightX +1] != 'o')&&(mat[Squareblock.lineTwoY][Squareblock.squareRightX +1] != '#')){
    Squareblock.squareLeftX ++;
    Squareblock.squareRightX ++;
  }
}

// Z Movements
void ZMoveRight(int *position){
  extern ZDef Zblock;
  if ((*position == 1)||(*position == -1)){
    if ((mat[Zblock.lineOneY][Zblock.ZMiddleX +1]!='o')&&(mat[Zblock.lineOneY][Zblock.ZMiddleX +1]!='#')&&(mat[Zblock.lineThreeY][Zblock.ZLeftX +1]!='o')) {
      Zblock.ZLeftX ++;
      Zblock.ZRightX ++;
      Zblock.ZMiddleX ++;
    }
  }
  else{
    if ((mat[Zblock.lineOneY][Zblock.ZRightX +1]!='o')&&(mat[Zblock.lineOneY][Zblock.ZRightX +1]!='#')&&(mat[Zblock.lineTwoY][Zblock.ZRightX +1]!='o')) {
      Zblock.ZLeftX ++;
      Zblock.ZRightX ++;
      Zblock.ZMiddleX ++;
    }
  }
}

void ZMoveLeft(){
  extern ZDef Zblock;

  if ((mat[Zblock.lineOneY][Zblock.ZLeftX -1]!='o')&&(mat[Zblock.lineOneY][Zblock.ZLeftX -1]!='#')&&(mat[Zblock.lineTwoY][Zblock.ZMiddleX -1]!='o')) {
    Zblock.ZLeftX --;
    Zblock.ZRightX --;
    Zblock.ZMiddleX --;
  }
}

void ZMoveDown(){
  extern ZDef Zblock;

  Zblock.lineOneY ++;
  Zblock.lineTwoY ++;
  Zblock.lineThreeY ++;
  Zblock.lineFourY ++;
}

//L Movements
void LMoveRight(){
  extern LDef Lblock;
  if ((mat[Lblock.lineOneY][Lblock.LLeftX +1]!='o')&&(mat[Lblock.lineTwoY][Lblock.LLeftX +1]!='o')&&(mat[Lblock.lineThreeY][Lblock.LLeftX +1]!='o')&&(mat[Lblock.lineThreeY][Lblock.LRightX +1]!='o')&&(mat[Lblock.lineThreeY][Lblock.LRightX +1]!='#')) {
    Lblock.LLeftX++;
    Lblock.LRightX++;
    Lblock.LMiddleX++;
  }
}

void LMoveLeft(int *position){
  extern LDef Lblock;
  if ((*position == -2)||(*position == -2)) {
    if ((mat[Lblock.lineThreeY][Lblock.LRightX -1]!='o')&&(mat[Lblock.lineOneY][Lblock.LRightX -1]!='o')&&(mat[Lblock.lineTwoY][Lblock.LRightX -1]!='o')) {
      Lblock.LLeftX--;
      Lblock.LRightX--;
      Lblock.LMiddleX--;
    }
  }else{
    if ((mat[Lblock.lineOneY][Lblock.LLeftX -1]!='o')&&(mat[Lblock.lineTwoY][Lblock.LLeftX -1]!='o')&&(mat[Lblock.lineThreeY][Lblock.LLeftX -1]!='o')&&(mat[Lblock.lineThreeY][Lblock.LLeftX -1]!='#')&&(mat[Lblock.lineTwoY][Lblock.LLeftX -1]!='#')&&(mat[Lblock.lineOneY][Lblock.LLeftX -1]!='#')) {
      Lblock.LLeftX--;
      Lblock.LRightX--;
      Lblock.LMiddleX--;
    }
  }
}

void LMoveDown(){
  extern LDef Lblock;

  Lblock.lineOneY ++;
  Lblock.lineTwoY ++;
  Lblock.lineThreeY ++;
}

// J Movements

void JMoveRight(){
  extern JDef Jblock;
  if ((mat[Jblock.lineOneY][Jblock.JRightX +1] != 'o')&&(mat[Jblock.lineTwoY][Jblock.JRightX +1] != 'o')&&(mat[Jblock.lineThreeY][Jblock.JRightX +1] != 'o')&&(mat[Jblock.lineTwoY][Jblock.JRightX +1] != '#')&&(mat[Jblock.lineThreeY][Jblock.JRightX +1] != '#')&&(mat[Jblock.lineOneY][Jblock.JRightX +1] != '#')){
    Jblock.JLeftX++;
    Jblock.JMiddleX++;
    Jblock.JRightX++;

  }
}

void JMoveLeft(){
  extern JDef Jblock;
  if ((mat[Jblock.lineOneY][Jblock.JLeftX -1] != 'o')&&(mat[Jblock.lineThreeY][Jblock.JLeftX -1] != 'o')&&(mat[Jblock.lineOneY][Jblock.JLeftX -1] != '#')&&(mat[Jblock.lineThreeY][Jblock.JLeftX -1] != '#')) {
    Jblock.JLeftX--;
    Jblock.JMiddleX--;
    Jblock.JRightX--;
  }
}

void JMoveDown(){
  extern JDef Jblock;

  Jblock.lineOneY++;
  Jblock.lineTwoY++;
  Jblock.lineThreeY++;
}

// T Movements
void TMoveRight(){
  extern TDef Tblock;

  if ((mat[Tblock.lineOneY][Tblock.TRightX +1] != 'o')&&(mat[Tblock.lineTwoY][Tblock.TMiddleX +1] != 'o')&&(mat[Tblock.lineThreeY][Tblock.TMiddleX +1] != 'o')&&(mat[Tblock.lineOneY][Tblock.TRightX +1] != '#')&&(mat[Tblock.lineTwoY][Tblock.TMiddleX +1] != '#')&&(mat[Tblock.lineThreeY][Tblock.TMiddleX +1] != '#')) {
    Tblock.TLeftX++;
    Tblock.TMiddleX++;
    Tblock.TRightX++;
  }
}

void TMoveLeft(){
  extern TDef Tblock;

  if ((mat[Tblock.lineOneY][Tblock.TLeftX -1] != 'o')&&(mat[Tblock.lineTwoY][Tblock.TMiddleX -1] != 'o')&&(mat[Tblock.lineThreeY][Tblock.TMiddleX -1] != 'o')&&(mat[Tblock.lineOneY][Tblock.TLeftX -1] != '#')&&(mat[Tblock.lineTwoY][Tblock.TMiddleX -1] != '#')&&(mat[Tblock.lineThreeY][Tblock.TMiddleX -1] != '#')) {
    Tblock.TLeftX--;
    Tblock.TMiddleX--;
    Tblock.TRightX--;
  }
}

void TMoveDown(){
  extern TDef Tblock;
  Tblock.lineOneY++;
  Tblock.lineTwoY++;
  Tblock.lineThreeY++;
}

// I Movements
void IMoveLeft(){
  extern IDef Iblock;

  if ((mat[Iblock.lineOneY][Iblock.IMiddleX -1] != 'o')&&(mat[Iblock.lineTwoY][Iblock.IMiddleX -1] != 'o')&&(mat[Iblock.lineThreeY][Iblock.IMiddleX -1] != 'o')&&(mat[Iblock.lineOneY][Iblock.IMiddleX -1] != '#')&&(mat[Iblock.lineTwoY][Iblock.IMiddleX -1] != '#')&&(mat[Iblock.lineThreeY][Iblock.IMiddleX -1] != '#')) {
    Iblock.IMiddleX --;
  }
}

void IMoveRight(){
  extern IDef Iblock;
  if ((mat[Iblock.lineOneY][Iblock.IMiddleX +1] != 'o')&&(mat[Iblock.lineTwoY][Iblock.IMiddleX +1] != 'o')&&(mat[Iblock.lineThreeY][Iblock.IMiddleX +1] != 'o')&&(mat[Iblock.lineOneY][Iblock.IMiddleX +1] != '#')&&(mat[Iblock.lineTwoY][Iblock.IMiddleX +1] != '#')&&(mat[Iblock.lineThreeY][Iblock.IMiddleX +1] != '#')) {
    Iblock.IMiddleX ++;
  }
}

void IMoveDown(){
  extern IDef Iblock;

  Iblock.lineOneY ++;
  Iblock.lineTwoY ++;
  Iblock.lineThreeY ++;
}

void SMoveDown(){
  extern SDef Sblock;

  Sblock.lineOneY ++;
  Sblock.lineTwoY ++;
  Sblock.lineThreeY ++;
  Sblock.lineFourY ++;
}

void SMoveRight(){
  extern SDef Sblock;

  if ((mat[Sblock.lineOneY][Sblock.SRightX +1] != 'o')&&(mat[Sblock.lineTwoY][Sblock.SMiddleX +1] != 'o')&&(mat[Sblock.lineOneY][Sblock.SRightX +1] != '#')&&(mat[Sblock.lineTwoY][Sblock.SMiddleX +1] != '#')) {
    Sblock.SRightX ++;
    Sblock.SMiddleX ++;
    Sblock.SLeftX ++;
  }
}

void SMoveLeft(int *position){
  extern SDef Sblock;
  if ((*position == 1)||(*position == -1)){
    if ((mat[Sblock.lineOneY][Sblock.SMiddleX -1] != 'o')&&(mat[Sblock.lineTwoY][Sblock.SMiddleX -1] != 'o')&&(mat[Sblock.lineThreeY][Sblock.SRightX -1] != 'o')&&(mat[Sblock.lineOneY][Sblock.SMiddleX -1] != '#')&&(mat[Sblock.lineTwoY][Sblock.SMiddleX -1] != '#')&&(mat[Sblock.lineThreeY][Sblock.SRightX -1] != '#')) {
      Sblock.SRightX --;
      Sblock.SMiddleX --;
      Sblock.SLeftX --;
    }
  }
  else{
    if ((mat[Sblock.lineOneY][Sblock.SLeftX -1] != 'o')&&(mat[Sblock.lineTwoY][Sblock.SLeftX -1] != 'o')&&(mat[Sblock.lineFourY][Sblock.SLeftX -1] != 'o')&&(mat[Sblock.lineOneY][Sblock.SLeftX -1] != '#')&&(mat[Sblock.lineTwoY][Sblock.SLeftX -1] != '#')&&(mat[Sblock.lineFourY][Sblock.SLeftX -1] != '#')) {
      Sblock.SRightX --;
      Sblock.SMiddleX --;
      Sblock.SLeftX --;
    }
  }
}

void Move(char mat[Y][X], int movement, int typeOfBlock,int *position){
  switch (typeOfBlock) {
    case 0: // carré
      switch (movement) {
        case 1: squareMoveLeft();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 2: squareMoveDown();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 3: squareMoveRight();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 5:
          break;
        case 6:
          break;
        // case 5: TurnRight(mat,)
      }
      break;
    case 1: // Z
      switch (movement) {
        case 1: ZMoveLeft();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 2: ZMoveDown();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 3: ZMoveRight(position);
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 5:
          *position = *position -1;
          if (*position < -2) {
            *position = 1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 6:
          *position = *position +1;
          if (*position > 2) {
            *position = -1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        }
      break;
    case 2: // L
      switch (movement) {
        case 1: LMoveLeft(position);
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 2: LMoveDown();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 3: LMoveRight();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 5:
          *position = *position -1;
          if (*position < -2) {
            *position = 1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 6:
          *position = *position +1;
          if (*position > 2) {
            *position = -1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        }
      break;
    case 3: // J
      switch (movement) {
        case 1: JMoveLeft();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 2: JMoveDown();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 3: JMoveRight();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 5:
          *position = *position -1;
          if (*position < -2) {
            *position = 1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 6:
          *position = *position +1;
          if (*position > 2) {
            *position = -1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        }
      break;
    case 4: // T
      switch (movement) {
        case 1: TMoveLeft();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 2: TMoveDown();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 3: TMoveRight();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 5:
          *position = *position -1;
          if (*position < -2) {
            *position = 1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 6:
          *position = *position +1;
          if (*position > 2) {
            *position = -1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        }
      break;
    case 5: // I
      switch (movement) {
        case 1: IMoveLeft();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 2: IMoveDown();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 3: IMoveRight();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 5:
          *position = *position -1;
          if (*position < -2) {
            *position = 1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 6:
          *position = *position +1;
          if (*position > 2) {
            *position = -1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        }
      break;
    case 6: // S
      switch (movement) {
        case 1: SMoveLeft(position);
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 2: SMoveDown();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 3: SMoveRight();
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 5:
          *position = *position -1;
          if (*position < -2) {
            *position = 1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        case 6:
          *position = *position +1;
          if (*position > 2) {
            *position = -1;
          }
          matrixMovement(mat,typeOfBlock,*position);
          break;
        }
      break;
  }
}

void movementHandler(char mat[Y][X], int randomNumber){
  int noConflict =0; //Determine si le bloc ne peut plus descendre + bas
  int movement;
  int position = 0;

  if (noConflict == 0){
    noConflict = canMove(mat,randomNumber, &position); //Vérifie que le joueur peut encore descendre le bloc
    while(noConflict == 0){
      movement = getNextMovement();
      Move(mat, movement, randomNumber, &position);
      printf("position: %d\n",position);
      Affiche(mat);
      noConflict = canMove(mat,randomNumber, &position);
    }
    blockEnd(mat);
  }
}
