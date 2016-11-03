#include "scoreHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define lengthName 20
#define nbOldScore 10

// TODO: regler pb avec la lecture du fichier quand le fichier a déjà été édité par le programme
//       faire le tri des scores
// Et apres version minimale terminée plus qu'à se retaper la création des blocs et la gestion des mouvements pour que ce soit
// plus propre ...

typedef struct{
  int score;
  int line;
  char name[lengthName];
}saveScore;

void showScore(int score){
  printf("Score: %d \n\n", score);
}

void printBestScores() {
  /* code */
}

void getName(char name[lengthName]) {
  printf("Nom du joueur (20 lettres max) : ");
  scanf("%s*c",name);
}

void readFile(saveScore oldScores[nbOldScore]){
  FILE *file;
  file = fopen("score.txt", "r");

  if (file != NULL) {
    for (int i = 0; i < nbOldScore; i++) {
      fscanf(file,"%d %d %s",&(oldScores[i]).score,&(oldScores[i]).line,oldScores[i].name);
    }
  }
  else
    printf("There is no file named \"score.txt\" !\n");
  fclose(file);
}

void writeFile(saveScore oldScores[nbOldScore]){
  FILE *file;
  file = fopen("score.txt", "w");

  if (file != NULL) {
    for (int i = 0; i < nbOldScore; i++) {
      fprintf(file,"%d %d %s \n",oldScores[i].score,oldScores[i].line,oldScores[i].name);
    }
  }
  else
    printf("There is no file named \"score.txt\" !\n");
  fclose(file);

}

void fileScoreHandler(saveScore oldScores[nbOldScore], int intention){
  switch (intention) {
    case 0: readFile(oldScores);
      break;
    case 1: writeFile(oldScores);
      break;
  }

}

void ramScores(saveScore *oldScores, saveScore *save){
  int aux;
  char auxString;
  // Permutation scores
  aux = save->score;
  save->score = oldScores->score;
  oldScores->score = aux;

  // Permutation nb lignes
  aux = save->line;
  save->line = oldScores->line;
  oldScores->line = aux;

  // Permutation noms
  for (int i = 0; i < lengthName; i++) {
    auxString = save->name[i];
    save->name[i] = oldScores->name[i];
    oldScores->name[i] = auxString;

  }
}

void endGameScreen(int *score){
  saveScore save;
  saveScore oldScores[nbOldScore];
  printf("=======================================================================");
  printf(" \n\n\n                    !!! GAME OVER !!!\n\n\n");
  printf("======================================================================= \n");

// On récupère les infos de la partie
  getName(save.name);
  save.score = *score;
  save.line = *score; // temporairement
  printf("name: %s\n",save.name );

  printf("On lit le fichier\n");
  fileScoreHandler(oldScores,0);

  printf("On regarde les scores dans le tableau\n");
  for (int i = 0; i < nbOldScore; i++) {
    if(oldScores[i].score<save.score){
      ramScores(&(oldScores[i]),&save);
    }
  }
  printf("On ecrit dans le fichier\n");
  fileScoreHandler(oldScores,1);

  printf("On affiche le tableau\n");
  for (int i = 0; i < nbOldScore; i++) {
    printf("save n°%d :\n    score: %d    lignes: %d   name: %s \n========\n",i,oldScores[i].score,oldScores[i].line,oldScores[i].name);
  }
  //Lire les vieux scores
  //Classer le nouveau score dans le vieux
  //Afficher le nouveau tableau des scores
  //Ecrire le nouveau fichier score
  printBestScores();
}

void deleteLine(char mat[Y][X], int line){
  for (int i = line; i > 0; i--) {
    for (int j = 0; j < X; j++) {
      mat[i][j] = mat[i-1][j];
    }
  }
}

int checkLines(char mat[Y][X], int score){
  int j;
  int isEmpty;
  for (int i = 0; i < Y-1; i++) {
    isEmpty = 0;
    if (mat[i][j] == 'o') {
      isEmpty = 1;
      for (j = 1; j < X-2; j++) {
        if (mat[i][j] == ' ') {
          isEmpty = 0;
        }
      }
    }
    if (isEmpty == 0) {
    }
    if (isEmpty == 1) {
      deleteLine(mat,i);
      score += 10;
    }
  }
  return score;
}
