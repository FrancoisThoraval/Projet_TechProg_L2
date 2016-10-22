#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define Y 14
#define X 12

void errorHandler(int errorCode){
  switch (errorCode) {
    case 1: printf("Erreur n°%d: Erreur lors de la création du nouveau bloc\n",errorCode);
      exit(1);
      break;
  }
}

void Affiche(int size, char mat[][size]) {
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      printf("%c",mat[i][j]);
    }
    printf("\n");
  }
}


// Designs des blocs
void square(int size, char mat[][size]) {
  char blocChar = 'x';

  mat[0][X/2 -1] = blocChar;
  mat[0][X/2] = blocChar;
  mat[1][X/2 -1] = blocChar;
  mat[1][X/2] = blocChar;
}

void zeee(int size, char mat[][size]) {
  char blocChar = 'x';

  mat[0][X/2 -2] = blocChar;
  mat[0][X/2 -1] = blocChar;
  mat[0][X/2] = blocChar;
  mat[0][X/2 +1] = blocChar;
  mat[0][X/2 +2] = blocChar;

  mat[1][X/2 +1] = blocChar;
  mat[1][X/2] = blocChar;

  mat[2][X/2 -2] = blocChar;
  mat[2][X/2 -1] = blocChar;
  mat[2][X/2] = blocChar;
  mat[2][X/2 +1] = blocChar;
  mat[2][X/2 +2] = blocChar;
}

void leee(int size, char mat[][size]) {
  char blocChar = 'x';

  mat[0][X/2 -1] = blocChar;
  mat[1][X/2 -1] = blocChar;
  mat[2][X/2 -1] = blocChar;

  mat[2][X/2] = blocChar;
  mat[2][X/2 +1] = blocChar;
}

void jeee(int size, char mat[][size]) {
  char blocChar = 'x';

  mat[0][X/2 -1] = blocChar;
  mat[0][X/2] = blocChar;
  mat[0][X/2 +1] = blocChar;

  mat[1][X/2 +1] = blocChar;
  mat[2][X/2 +1] = blocChar;

  mat[2][X/2] = blocChar;
  mat[2][X/2 -1] = blocChar;
}

void teee(int size, char mat[][size]) {
  char blocChar = 'x';
  mat[0][X/2 -1] = blocChar;
  mat[0][X/2] = blocChar;
  mat[0][X/2 +1] = blocChar;

  mat[0][X/2] = blocChar;
  mat[1][X/2] = blocChar;
  mat[2][X/2] = blocChar;
}

void iail(int size, char mat[][size]) {
  char blocChar = 'x';

  mat[0][X/2] = blocChar;
  mat[1][X/2] = blocChar;
  mat[2][X/2] = blocChar;
}

void putBlockInMat(int randomNumber, int size, char mat[][size]){
  switch (randomNumber) {
    case 0: square(size,mat);
      break;
    case 1: zeee(size,mat);
      break;
    case 2: leee(size,mat);
      break;
    case 3: jeee(size,mat);
      break;
    case 4: teee(size,mat);
      break;
    case 5: iail(size,mat);
      break;
    default: errorHandler(1);
      break;
  }
}

//On recopie l'ancienne matrice
void recopyOldMat(int size, char mat[][size]){
  for (int i = 0; i < Y-1; i++) {
    for (int j = 0; j < X-1; j++) {
      switch (mat[i][j]) {
        case 'x': mat[i][j] = 'o';
        break;
        case 'o': break;
        case '#': break;
        case '_': break;
        default: mat[i][j] =' ';
      }
    }
  }
}

void initMatrix(int size,char mat[][size]){
  // On cree les contours de la matrice
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      mat[i][j]=' ';
      if (i==Y-1) {
        mat[i][j]='#';
      }
      if ((j==0)||(j==X-1)) {
        mat[i][j]='#';
      }
    }
  }

}

int randomize(){
  //On tire au sort un nombre qui correspondra a la forme du bloc
  srand(time(NULL));
  int randomNumber = rand() %5;
  return randomNumber;
}

int movementHandler(){
  int noConflict =0; //Determine si le bloc ne peut plus descendre + bas

  return noConflict;
}

int main() {
  char mat[X][Y];
  int gameOn =0;
  int oldNumber = -1;
  int randomNumber;
  int noConflict =0;
  initMatrix(X,mat); //on initialise la matrice

  // while (gameOn != 1) { //On boucle tant que le jeu est lancé
    do {
      randomNumber = randomize();
    } while(randomNumber == oldNumber);
    oldNumber = randomNumber;
    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,X,mat);
    Affiche(X,mat); //on l'affiche
    if (noConflict == 0){
      noConflict = movementHandler(X,mat); //gere les mouvements du bloc par le joueur
    }
    recopyOldMat(X,mat);
    Affiche(X,mat); //on l'affiche
  // }
  return 0;
}
