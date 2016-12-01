#include "scoreHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "definition.h"
#include "menu.h"

void showScore(int score, int line){
  printw("Score: %d Lines deleted: %d\n\n", score, line);
}

void printBestScores(saveScore oldScores[nbOldScore]) {
  // erase();
  // refresh();
  system("clear");
  printf("\n=============================================  TOP 10 SCORES  ================================================\n\n");
  for (int i = nbOldScore -1; i >= 0; i--) {
    printf("save n°%d :\n    score: %d    lignes: %d   name: %s \n========\n",nbOldScore-i,oldScores[i].score,oldScores[i].line,oldScores[i].name);
  }
}

void getName(char name[lengthName]) {
  printf("Nom du joueur (20 lettres max) : ");
  scanf("%s",name);
}

void readFile(saveScore oldScores[nbOldScore]){
  FILE *file;
  file = fopen("score.txt", "r");

  if (file != NULL) {
    for (int i = nbOldScore -1; i >= 0; i--) {
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
    for (int i = nbOldScore -1; i >= 0; i--) {
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

void sortScores(saveScore oldScores[nbOldScore], saveScore save){
  for (int i = nbOldScore -1; i >= 0; i--) {
    if(oldScores[i].score < save.score){
      ramScores(&(oldScores[i]),&save);
      if (i < 1) {
        ramScores(&save,&(oldScores[i-1]));
      }
    }
  }
}

void Score(int *score, int *line){
  saveScore save;
  saveScore oldScores[nbOldScore];
  system("clear");
  // On récupère les infos de la partie
  getName(save.name);
  save.score = *score;
  save.line = *line;
  printf("name: %s\n",save.name );

  // On lit le fichier score.txt et on met les valeur dans un tableau de scores
  fileScoreHandler(oldScores,0);

  // On trie le tableau de scores
  sortScores(oldScores,save);

  // On écrit le nouveau fichier
  fileScoreHandler(oldScores,1);

  // On affiche les scores
  printBestScores(oldScores);
  printf("\n -------- Back to menu in 3 seconds --------\n");
  sleep(3);
  menu();
  // endwin();
}

void deleteLine(char mat[Y][X], int line){

  for (int i = line; i > 0; i--) {
    for (int j = 0; j < X; j++) {
      mat[i][j] = mat[i-1][j];
    }
  }
}

void checkLines(char mat[Y][X], int *score, int *line, int level){
  int j;
  int isEmpty;

  for (int i = 0; i < Y; i++) {
    isEmpty = 0;
    if (mat[i][j] == 'o') {
      j=0;
      while ((j<X) && (mat[i][j]=='o')) {
        j++;
      }
      if (mat[i][j] == ' ') {
        isEmpty = 0;
      }
      if (j==X-1) {
        isEmpty = 1;
      }
    }
    if (isEmpty == 1) {
      // printf("(on supprime la ligne n° %d\n",i );
      deleteLine(mat,i);
      *score += (10*level);
      *line = *line +1;
      j=0;
    }
  }
}
