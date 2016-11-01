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
  int *score;
  int *line;
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

void fileScoreHandler(saveScore oldScores[nbOldScore], int intention){
  FILE *file;
  file = fopen("score.txt", "r+");
  if (intention == 0) {
    if (file != NULL) {
      for (int i = 0; i < nbOldScore-1; i++) {
        fscanf(file,"%d %d %s",oldScores[i].score,oldScores[i].line,oldScores[i].name);
      }
      fclose(file);
    }
    else
      printf("There is no file named \"score.txt\" !\n");
  }else{
    if (file != NULL) {
      for (int i = 0; i < nbOldScore-1; i++) {
        fprintf(file,"%d %d %s",*oldScores[i].score,*oldScores[i].line,oldScores[i].name);
      }
      fclose(file);
    }
    else
      printf("There is no file named \"score.txt\" !\n");
  }
}

void endGameScreen(int *score){
  saveScore save;
  saveScore oldScores[nbOldScore];
  printf("=======================================================================");
  printf(" \n\n\n                    !!! GAME OVER !!!\n\n\n");
  printf("======================================================================= \n");
  getName(save.name);
  save.score = score;
  save.line = score; // temporairement
  printf("name: %s\n",save.name );
  printf("On lit une premiere fois le fichier\n");
  fileScoreHandler(oldScores,0);
  printf("premier test\n");
  for (int i = 0; i < nbOldScore -1; i++) {
    oldScores[i]=save;
  }
  printf("On ecrit dans le fichier\n");
  fileScoreHandler(oldScores,1);
  printf("On relit une seconde fois le fichier\n");
  fileScoreHandler(oldScores,0);
  for (int i = 0; i < nbOldScore; i++) {
    printf("save n°%d :\n    score: %d    lignes: %d   name: %s\n========\n",i,*oldScores[i].score,*oldScores[i].line,oldScores[i].name);
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
