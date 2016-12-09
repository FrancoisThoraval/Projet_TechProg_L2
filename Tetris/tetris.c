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


void play(float difficulty_O_Meter) {
  coordBlock block;
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  int nbLines = 0;
  int saveLines = line;
  float seconds = 2;
  int level = 1;
  int tries =0;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *gameMusic = NULL;
  Mix_Chunk *sample = NULL;
  playSound(0,gameMusic);

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
    show(mat, score, line,tries); //on l'affiche
    nbLines = line;
    movementHandler(mat, randomNumber, &score, &line, &block, seconds, level, tries); //On gère les mouvements du bloc
    switch (line - nbLines) {
      case 1:
        playSample(4, sample);
        break;
      case 2: score +=100;
        playSample(11,sample);
        break;
      case 3: score +=200;
        playSample(5, sample);
        break;
      case 4: score +=500;
        playSample(8, sample);
        refresh();
    }
    if (line - saveLines == NEWLEVEL) {
      Mix_VolumeMusic(MIX_MAX_VOLUME/2);
      playSample(9,sample);
      saveLines = line;
      seconds = seconds/difficulty_O_Meter;
      level++;
      Mix_VolumeMusic(MIX_MAX_VOLUME-20);
    }
    if (line - saveLines == NEWLEVEL+5) {
      playSound(1,gameMusic);
      saveLines = line;
      seconds = seconds/difficulty_O_Meter;
      level++;
      Mix_VolumeMusic(MIX_MAX_VOLUME-20);
    }
    // erase();
    refresh();
    show(mat, score, line, tries); //on réaffiche la matrice une fois que le bloc est placé
    gameOn = gameOver(mat,0,difficulty_O_Meter); // Vérifie si on peut encore jouer
    if (gameOn == 1) {
      Mix_FadeOutMusic(5000);
      menuGameOver(&difficulty_O_Meter,&score, &line,0,1); //Affiche un message et passe à la saisie des scores etc...
    }
  }
  free(sample);
}

void playModeTwo(float difficulty_O_Meter) {
  coordBlock block;
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  int nbLines = 0;
  float seconds = 2;
  int level = 1;
  int tries = 1;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *gameMusic = NULL;
  Mix_Chunk *sample = NULL;
  playSound(0,gameMusic);

  // seconds = seconds/difficulty_O_Meter;
  erase();
  initMatrix(mat); //on initialise la matrice
  fillMatrix(mat,difficulty_O_Meter);
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
    show(mat, score, line,tries); //on l'affiche
    nbLines = line;
    movementHandler(mat, randomNumber, &score, &line, &block, seconds, level, tries); //On gère les mouvements du bloc
    switch (line - nbLines) {
      case 1:
        playSample(4, sample);
        break;
      case 2: score +=100;
        playSample(11,sample);
        break;
      case 3: score +=200;
        playSample(5, sample);
        break;
      case 4: score +=500;
        playSample(8, sample);
        refresh();
    }
    refresh();
    show(mat, score, line, tries); //on réaffiche la matrice une fois que le bloc est placé
    gameOn = gameOver(mat,1,difficulty_O_Meter); // Vérifie si on peut encore jouer
    if (gameOn == 1) {
      Mix_FadeOutMusic(5000);
      menuGameOver(&difficulty_O_Meter,&score, &line,&tries,2); //Affiche un message et passe à la saisie des scores etc...
    }else
      tries++;
  }
  free(sample);
}
