#include "scoreHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "definition.h"
#include "menu.h"

void showScore(int score, int line, int tries){
  if (tries == 0) {
    printw("Score: %d Lines deleted: %d\n\n", score, line);
  }else
    printw("Score: %d Lines deleted: %d Tries: %d\n\n", score, line, tries);
}

void printBestScores(saveScore oldScores[nbOldScore]) {
  erase();
  // system("clear");
  printw("\n=============================================  TOP 10 SCORES  ================================================\n\n");
  for (int i = nbOldScore -1; i >= 0; i--) {
    printw("save n°%d :\n    score: %d    lignes: %d   name: %s \n========\n",nbOldScore-i,oldScores[i].score,oldScores[i].line,oldScores[i].name);
  }
  refresh();
}

void printBestScores2(saveScore oldScores[nbOldScore]) {
  erase();
  refresh();
  // system("clear");
  printw("\n=============================================  TOP 10 SCORES  ================================================\n\n");
  for (int i = nbOldScore -1; i >= 0; i--) {
    printw("save n°%d :\n    score: %d    lignes: %d    tries:%d   name: %s \n========\n",nbOldScore-i,oldScores[i].score,oldScores[i].line,oldScores[i].tries,oldScores[i].name);
  }
}

void getName(char name[lengthName]) {
  // char cur_input;
  echo();
  // system("clear");
  printf("Nom du joueur (20 lettres max) : ");
  scanf("%s",name);
  // printw("Nom du joueur (20 lettres max) : ");
  //
  // for(int i=0; i <= lengthName; i++) {
  //   cur_input = getch();
  //   if(cur_input != '\n')
  //     name[i] = cur_input;
  //   else
  //     if (((int)(cur_input) > 126)&&((int)(cur_input) < 32)) {
  //       i--;
  //     }else
  //       break;
  // }
  // getstr(name);
  // printw("Name: %s", name);
  // getch();
  // refresh();
}

void readFile(saveScore oldScores[nbOldScore]){
  FILE *file;
  file = fopen("score.txt", "r");

  if (file != NULL) {
    for (int i = nbOldScore -1; i >= 0; i--) {
      fscanf(file,"%d %d %s",&(oldScores[i]).score,&(oldScores[i]).line,oldScores[i].name);
    }
  }
  else{
    perror("There is no file named \"score.txt\" !\n");
  }
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
    perror("There is no file named \"score.txt\" !\n");
  fclose(file);

}

void readFile2(saveScore oldScores[nbOldScore]){
  FILE *file;
  file = fopen("score2.txt", "r");

  if (file != NULL) {
    for (int i = nbOldScore -1; i >= 0; i--) {
      fscanf(file,"%d %d %d %s \n",&(oldScores[i]).score,&(oldScores[i]).line,&(oldScores[i]).tries ,oldScores[i].name);
    }
  }
  else
    perror("There is no file named \"score2.txt\" !\n");
  fclose(file);
}

void writeFile2(saveScore oldScores[nbOldScore]){
  FILE *file;
  file = fopen("score2.txt", "w");

  if (file != NULL) {
    for (int i = nbOldScore -1; i >= 0; i--) {
      fprintf(file,"%d %d %d %s \n",oldScores[i].score,oldScores[i].line,oldScores[i].tries ,oldScores[i].name);
    }
  }
  else
    perror("There is no file named \"score2.txt\" !\n");
  fclose(file);
}

void fileScoreHandler(saveScore oldScores[nbOldScore], int intention){
  switch (intention) {
    case 0: readFile(oldScores);
      break;
    case 1: writeFile(oldScores);
      break;
    case 2: readFile2(oldScores);
      break;
    case 3: writeFile2(oldScores);
      break;
  }

}

void ramScores(saveScore *oldScores, saveScore *save, int isMode2){
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

  if (isMode2 == 0) {
    aux = save->tries;
    save->tries = oldScores->tries;
    oldScores->tries = aux;
  }

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
      ramScores(&(oldScores[i]),&save,1);
      // if (i < 1) {
      //   ramScores(&save,&(oldScores[i-1]),1);
      // }
    }
  }
}

void sortScores2(saveScore oldScores[nbOldScore], saveScore save){
  for (int i = nbOldScore -1; i >= 0; i--) {
    if(oldScores[i].tries < save.tries){
      ramScores(&(oldScores[i]),&save,0);
      if (i < 1) {
        ramScores(&save,&(oldScores[i-1]),0);
      }
    }
  }
}

void Score(int *score, int *line, float *difficulty_O_Meter){
  saveScore save;
  saveScore oldScores[nbOldScore];
  // On récupère les infos de la partie
  getName(save.name);
  save.score = *score;
  save.line = *line;

  // On lit le fichier score.txt et on met les valeur dans un tableau de scores
  fileScoreHandler(oldScores,0);

  // On trie le tableau de scores
  sortScores(oldScores,save);

  // On écrit le nouveau fichier
  fileScoreHandler(oldScores,1);
  // printBestScores(oldScores);
  // sleep(3);
  // printf("going back to menu in 3 seconds\n");
  callMenuWithMusic(difficulty_O_Meter);
}

void Score2(int *score, int *line, float *difficulty_O_Meter, int *tries){
  saveScore save;
  saveScore oldScores[nbOldScore];
  // On récupère les infos de la partie
  getName(save.name);
  save.score = *score;
  save.line = *line;
  save.tries = *tries;

  // On lit le fichier score.txt et on met les valeur dans un tableau de scores
  fileScoreHandler(oldScores,2);

  // On trie le tableau de scores
  sortScores2(oldScores,save);

  // On écrit le nouveau fichier
  fileScoreHandler(oldScores,3);
  // printBestScores2(oldScores);
  // sleep(3);
  callMenuWithMusic(difficulty_O_Meter);
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
