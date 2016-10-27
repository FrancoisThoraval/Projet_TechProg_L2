#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"
#include "scoreHandler.h"
// Var globales
squareDef Squareblock;
ZDef Zblock;
LDef Lblock;
IDef Iblock;
JDef Jblock;
TDef Tblock;
SDef Sblock;

int main() {
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  initMatrix(mat); //on initialise la matrice

  while (gameOn != 1) { //On boucle tant que le jeu est lancé
    do {
      randomNumber = randomize();
    } while(randomNumber == oldNumber);
    oldNumber = randomNumber;
    // randomNumber = 0;
    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,mat,1,0);
    Affiche(mat, score); //on l'affiche
    movementHandler(mat, randomNumber,score); //On gère les mouvements du bloc
    score = checkLines(mat,score);
    Affiche(mat, score); //on réaffiche la matrice une fois que le bloc est placé
    // scanf("%d", &gameOn);
  }
  return 0;
}
