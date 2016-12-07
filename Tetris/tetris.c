#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"
#include "scoreHandler.h"
#include "definition.h"
#include "menu.h"

#include <ncurses.h> //Equivalent à conio.h pour kbhit et getch
// #include <unistd.h>


int play(float difficulty_O_Meter) {
  coordBlock block;
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  int nbLines;
  int saveLines = line;
  float seconds = 2;
  int level = 1;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *gameMusic = Mix_LoadMUS(" ");
  Mix_Music *sample = Mix_LoadMUS(" ");
  playSound('m',0,gameMusic);

  seconds = seconds/difficulty_O_Meter;
  erase();
  initMatrix(mat); //on initialise la matrice
  while (gameOn != 1) { //On boucle tant que le jeu est lancé
    initCoordStruct(&block);
    // Génération nombre aléatoire qui détermine le bloc
    do {
      randomNumber = randomize(7);
    } while(randomNumber == oldNumber);
    oldNumber = randomNumber;
    // randomNumber = 5;

    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,mat,2,0, &block);
    refresh();
    show(mat, score, line); //on l'affiche
    movementHandler(mat, randomNumber, &score, &line, &block, seconds, level); //On gère les mouvements du bloc
    nbLines = line;
    switch (line - nbLines) {
      case 1:
        playSound('s',1,sample);
      break;
      case 2: score +=25;
        break;
      case 3: score +=100;
        break;
      case 4: score +=400;
    }
    if (line - saveLines == NEWLEVEL) {
      saveLines = line;
      seconds = seconds/difficulty_O_Meter;
      level++;
    }
    // erase();
    refresh();
    show(mat, score, line); //on réaffiche la matrice une fois que le bloc est placé
    gameOn = gameOver(mat); // Vérifie si on peut encore jouer
    if (gameOn == 1) {
      Mix_FadeOutMusic(5000);
      menuGameOver(&difficulty_O_Meter,&score, &line); //Affiche un message et passe à la saisie des scores etc...
    }
  }
  return 0;
}

int playMode2(){
  return 0;
}
