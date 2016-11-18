#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"
#include "scoreHandler.h"
#include "definition.h"
// #include <unistd.h>

int main() {
  coordBlock block;
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  int nbLines;
  initMatrix(mat); //on initialise la matrice

  while (gameOn != 1) { //On boucle tant que le jeu est lancé
    initCoordStruct(&block);

    // Génération nombre aléatoire qui détermine le bloc
    do {
      randomNumber = randomize();
    } while(randomNumber == oldNumber);
    oldNumber = randomNumber;
    // randomNumber = 0;

    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,mat,2,0, &block);
    show(mat, score, line); //on l'affiche
    movementHandler(mat, randomNumber, &score, line, &block); //On gère les mouvements du bloc
    nbLines = line;
    checkLines(mat,&score, &line);
    switch (line - nbLines) {
      case 1: break;
      case 2: score +=5;
        break;
      case 3: score +=10;
        break;
      case 4: score +=50;
    }
    show(mat, score, line); //on réaffiche la matrice une fois que le bloc est placé
    printf("line - nbLines: %d",line - nbLines);
    gameOn = gameOver(mat); // Vérifie si on peut encore jouer
    if (gameOn == 1) {
      endGameScreen(&score, &line); //Affiche un message et passa à la saisie des scores etc...
    }

  }
  return 0;
}
