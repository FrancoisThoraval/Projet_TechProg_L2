#include "menu.h"

// ===================================== MODE CLASSIQUE =====================================
//

void play(float difficulty_O_Meter) {
  coordBlock block;

  char mat[Y][X];
  int randomNumber;
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  int nbLines = 0;
  int saveLines = line;
  float seconds = 2;
  int level = 1;
  int tries =0;

  // Initialisation de la musique
  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *gameMusic = NULL;
  Mix_Chunk *sample = NULL;
  playSound(0,gameMusic); //Joue une musique tirée au hasard

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
    
    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,mat,0, &block,'x');
    refresh();
    show(mat, score, line,tries); //on l'affiche
    nbLines = line;
    movementHandler(mat, randomNumber, &score, &line, &block, seconds, level, tries); //On gère les mouvements du bloc
    switch (line - nbLines) { //On regarde combien de lignes on été supprimées et on affecte le score en fonction
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
    if (line - saveLines >= NEWLEVEL) { //Si on a passé le niveau supérieur, on accélère la vitesse de chute + jouer un son
      playSample(9,sample);
      saveLines = line;
      seconds = seconds/difficulty_O_Meter;
      level++;
    }
    refresh();
    show(mat, score, line, tries); //on réaffiche la matrice une fois que le bloc est placé
    gameOn = gameOver(mat,0,difficulty_O_Meter); // on vérifie si on peut encore jouer
    if (gameOn == 1) {
      Mix_FadeOutMusic(5000);
      menuGameOver(&difficulty_O_Meter,&score, &line,0,1); //Affiche un menu pour sauvegarder le score || revenir au menu || quitter le jeu
    }
  }
  free(sample);
}
// ===================================== MODE ALTERNATIF =====================================
//
// Quasi le même code que play(float difficulty_O_Meter) sauf qu'on accélère pas la chute des blocs qui est fixée à une vitesse de 2 secondes
// et que le game over vérifie s'il y a encore des blocs dans la matrice (ce qui rend le jeu un peu plus lent)

void playModeTwo(float difficulty_O_Meter) {
  coordBlock block;
  char mat[Y][X];
  int randomNumber;
  int gameOn =0;
  int oldNumber = -1;
  int score = 0;
  int line = 0;
  int nbLines = 0;
  float seconds = 2;
  int level = 1;
  int tries = 1;


  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *gameMusic = NULL;
  Mix_Chunk *sample = NULL;
  playSound(0,gameMusic);

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

    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,mat,0, &block,'x');
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
