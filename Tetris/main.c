#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"
#include "scoreHandler.h"
#include "definition.h"
#include <ncurses.h> //Equivalent à conio.h pour kbhit et getch
// #include <unistd.h>


// TODO: Ajouter les niveaux, pour les points
int main() {
  coordBlock block;
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  int nbLines;
  int saveLines = line;
  float seconds = 1.5;
  int level = 1;


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
    initscr(); // entering ncurses mode                 //Je ne sais pas trop pourquoi, mais s'il on ne quitte pas le mode initscr immédiatement après l'avoir démarré, on a un premier affichage cassé
    endwin(); //end ncurses mode                        //le problème étant que sans ce initscr, on ne peut pas prendre les flèches du clavier. A voir si on trouve une documentation permettant de trouver une solution plus élégante.
    show(mat, score, line); //on l'affiche
    movementHandler(mat, randomNumber, &score, &line, &block, seconds, level); //On gère les mouvements du bloc
    nbLines = line;
    // checkLines(mat,&score, &line, level);
    switch (line - nbLines) {
      case 1: break;
      case 2: score +=5;
        break;
      case 3: score +=10;
        break;
      case 4: score +=50;
    }
    if (line - saveLines == 5) {
      saveLines = line;
      seconds = seconds/2;
      level++;
    }
    show(mat, score, line); //on réaffiche la matrice une fois que le bloc est placé
    gameOn = gameOver(mat); // Vérifie si on peut encore jouer
    if (gameOn == 1) {
      endGameScreen(&score, &line); //Affiche un message et passa à la saisie des scores etc...
    }
  }
  return 0;
}
