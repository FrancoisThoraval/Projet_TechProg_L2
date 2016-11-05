#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"
#include "scoreHandler.h"
// Var globales
coordBlock block;
// squareDef Squareblock;
// ZDef Zblock;
// LDef Lblock;
// IDef Iblock;
// JDef Jblock;
// TDef Tblock;
// SDef Sblock;

int main() {
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  initMatrix(mat); //on initialise la matrice


  while (gameOn != 1) { //On boucle tant que le jeu est lancé
    initCoordStruct();

    // Génération nombre aléatoire qui détermine le bloc
    do {
      randomNumber = randomize();
    } while(randomNumber == oldNumber);
    oldNumber = randomNumber;
    // randomNumber = 5;

    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,mat,2,0);
    Affiche(mat, score, line); //on l'affiche
    movementHandler(mat, randomNumber, score, line); //On gère les mouvements du bloc
    checkLines(mat,&score, &line);    
    Affiche(mat, score, line); //on réaffiche la matrice une fois que le bloc est placé
    gameOn = gameOver(mat); // Vérifie si on peut encore jouer
    if (gameOn == 1) {
      endGameScreen(&score, &line); //Affiche un message et passa à la saisie des scores etc...
    }
  }
  return 0;
}
