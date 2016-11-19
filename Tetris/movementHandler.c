#include "movementHandler.h"
#include "matrixHandler.h"
#include "definition.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <sys/time.h>
// #include "kbhit.h"
// #include <unistd.h>

void testPrintInfo(int *position, coordBlock *block){
  printf("coordonnées coordBlock:\n");
  printf("lineOneY: %d\n", block->lineOneY);
  printf("lineTwoY: %d\n", block->lineTwoY);
  printf("lineThreeY: %d\n", block->lineThreeY);
  printf("leftX: %d\n", block->leftX);
  printf("middleX: %d\n", block->middleX);
  printf("rightX: %d\n", block->rightX);
  printf("position: %d\n",*position );

}

// Fonctions qui vérifient qu'on peut encore descendre (canMoveV) ou bouger horizontalement (canMoveH)

int canMoveH(char mat[Y][X], int side, coordBlock *block){
  int isPossible=0;

  int isPossibleOL = 0;
  int isPossibleOM = 0;
  int isPossibleOR = 0;
  int isPossibleTL = 0;
  int isPossibleTM = 0;
  int isPossibleTR = 0;
  int isPossibleThL = 0;
  int isPossibleThM = 0;
  int isPossibleThR = 0;
  int isPossibleFR = 0;
  int isPossibleFL = 0;

  switch (side) {
    case 0:
      if ((mat[block->lineOneY][block->leftX]=='x')) {
        if ((block->leftX -1 == -1)||(mat[block->lineOneY][block->leftX -1] == 'o')) {
          isPossibleOL = 1;
        }
      }
      if ((mat[block->lineOneY][block->middleX]=='x')) {
        if ((block->middleX -1 == -1)||(mat[block->lineOneY][block->middleX -1] == 'o')) {
          isPossibleOM = 1;
        }
      }

      if ((mat[block->lineTwoY][block->leftX]=='x')) {
        if (((block->leftX -1 == -1))||(mat[block->lineTwoY][block->leftX -1] == 'o')) {
          isPossibleTL = 1;
        }
      }
      if ((mat[block->lineTwoY][block->middleX]=='x')) {
        if ((block->middleX -1 == -1)||(mat[block->lineTwoY][block->middleX -1] == 'o')) {
          isPossibleTM = 1;
        }
      }

      if ((mat[block->lineThreeY][block->leftX]=='x')) {
        if ((block->leftX -1 == -1)||(mat[block->lineThreeY][block->leftX -1] == 'o')) {
          isPossibleThL = 1;
        }
      }
      if ((mat[block->lineThreeY][block->middleX]=='x')) {
        if ((block->middleX -1 == -1)||(mat[block->lineThreeY][block->middleX -1] == 'o')) {
          isPossibleThM = 1;
        }
      }
      if ((mat[block->lineFourY][block->leftX]=='x')) {
        if ((block->leftX -1 == -1)||(mat[block->lineFourY][block->leftX] == 'o')) {
          isPossibleFL = 1;
        }
      }
      break;
    case 1:
      printf("X: %d\n",X);
      if ((mat[block->lineOneY][block->middleX]=='x')) {
        if ((block->middleX +1 == X-1)||(mat[block->lineOneY][block->middleX +1] == 'o')) {
          isPossibleOM = 1;
        }
      }
      if ((mat[block->lineOneY][block->rightX]=='x')) {
        if ((block->rightX +1 == X-1)||(mat[block->lineOneY][block->rightX +1] == 'o')) {
          isPossibleOR = 1;
        }
      }

      if ((mat[block->lineTwoY][block->middleX]=='x')) {
        if ((block->middleX +1 == X-1)||(mat[block->lineTwoY][block->middleX +1] == 'o')) {
          isPossibleTM = 1;
        }
      }
      if ((mat[block->lineTwoY][block->rightX]=='x')) {
        if ((block->rightX +1 == X-1)||(mat[block->lineTwoY][block->rightX +1] == 'o')) {
          isPossibleTR = 1;
        }
      }

      if ((mat[block->lineThreeY][block->middleX]=='x')) {
        if ((block->middleX +1 == X-1)||(mat[block->lineThreeY][block->middleX +1] == 'o')) {
          isPossibleThM = 1;
        }
      }
      if ((mat[block->lineThreeY][block->rightX]=='x')) {
        if ((block->rightX +1 == X-1)||(mat[block->lineThreeY][block->rightX +1] == 'o')) {
          isPossibleThR = 1;
        }
      }

      if ((mat[block->lineFourY][block->middleX]=='x')) {
        if ((block->rightX == X-1)||(mat[block->lineFourY][block->rightX] == 'o')) {
          isPossibleFR = 1;
        }
      }
      // Cas où le I est renversé
      if ((mat[block->lineTwoY][block->rightX+1]=='x')) {
        if ((block->rightX +2 == X-1)||(mat[block->lineFourY][block->rightX+2] == 'o')) {
          isPossibleFR = 1;
        }
      }
      break;
  }
  isPossible = isPossibleThR + isPossibleThM + isPossibleThL + isPossibleTR + isPossibleTM + isPossibleTL + isPossibleOR + isPossibleOL + isPossibleOM + isPossibleFR + isPossibleFL;

  return isPossible;
}

// Verification verticale que l'on peut encore descendre
int canMoveV(char mat[Y][X], coordBlock *block){
  int isPossible=0;

  int isPossibleOR = 0;
  int isPossibleOM = 0;
  int isPossibleOL = 0;
  int isPossibleTL = 0;
  int isPossibleTM = 0;
  int isPossibleTR = 0;
  int isPossibleThL = 0;
  int isPossibleThM = 0;
  int isPossibleThR = 0;
  int isPossibleFR = 0;
  int isPossibleFM = 0;
  int isPossibleFL = 0;

  if ((mat[block->lineOneY][block->leftX]=='x')) {
    if ((block->lineOneY == Y-2)||(mat[block->lineOneY +1][block->leftX] == 'o')) {
      isPossibleOL = 1;
    }
  }
  if ((mat[block->lineOneY][block->middleX]=='x')) {
    if ((block->lineOneY == Y-2)||(mat[block->lineOneY +1][block->middleX] == 'o')) {
      isPossibleOM = 1;
    }
  }
  if ((mat[block->lineOneY][block->rightX]=='x')) {
    if ((block->lineOneY == Y-2)||(mat[block->lineOneY +1][block->rightX] == 'o')) {
      isPossibleOR = 1;
    }
  }

  // Verification sur deuxième ligne
  if ((mat[block->lineTwoY][block->leftX]=='x')) {
    if ((block->lineTwoY == Y-2)||(mat[block->lineTwoY +1][block->leftX] == 'o')) {
      isPossibleTL = 1;
    }
  }
  if ((mat[block->lineTwoY][block->middleX]=='x')) {
    if ((block->lineTwoY == Y-2)||(mat[block->lineTwoY +1][block->middleX] == 'o')) {
      isPossibleTM = 1;
    }
  }
  if ((mat[block->lineTwoY][block->rightX]=='x')) {
    if ((block->lineTwoY == Y-2)||(mat[block->lineTwoY +1][block->rightX] == 'o')) {
      isPossibleTR = 1;
    }
  }

  // Verification sur troisieme ligne
  if ((mat[block->lineThreeY][block->leftX]=='x')) {
    if ((block->lineThreeY == Y-2)||(mat[block->lineThreeY +1][block->leftX] == 'o')) {
      isPossibleThL = 1;
    }
  }
  if ((mat[block->lineThreeY][block->middleX]=='x')) {
    if ((block->lineThreeY == Y-2)||(mat[block->lineThreeY +1][block->middleX] == 'o')) {
      isPossibleThM = 1;
    }
  }
  if ((mat[block->lineThreeY][block->rightX]=='x')) {
    if ((block->lineThreeY == Y-2)||(mat[block->lineThreeY +1][block->rightX] == 'o')) {
      isPossibleThR = 1;
    }
  }

  // Verification sur quatrieme ligne (cas du I)
  if ((mat[block->lineFourY][block->leftX]=='x')) {
    if ((block->lineFourY == Y-2)||(mat[block->lineFourY +1][block->leftX] == 'o')) {
      isPossibleFL = 1;
    }
  }
  if ((mat[block->lineFourY][block->middleX]=='x')) {
    if ((block->lineFourY == Y-2)||(mat[block->lineFourY +1][block->middleX] == 'o')) {
      isPossibleFM = 1;
    }
  }
  if ((mat[block->lineFourY][block->rightX]=='x')) {
    if ((block->lineFourY == Y-2)||(mat[block->lineFourY +1][block->rightX] == 'o')) {
      isPossibleFR = 1;
    }
  }
  if ((block->lineFourY == Y-1)||(block->lineThreeY == Y-1)||(block->lineTwoY == Y-1)||(block->lineOneY == Y-1)) {
    if (block->lineFourY == Y-1) {
    }
    if (block->lineThreeY == Y-1) {
    }
    if (block->lineTwoY == Y-1) {
    }
    if (block->lineOneY == Y-1) {
    }
  }
  isPossible = isPossibleThR + isPossibleThM + isPossibleThL + isPossibleTR + isPossibleTM + isPossibleTL + isPossibleOR + isPossibleOL + isPossibleOM + isPossibleFR + isPossibleFL + isPossibleFM;
  return isPossible;
}

int getNextMovement(char mat[Y][X],int score, int line){

  int nextMovement= 0;
  int input;
  keypad(stdscr, TRUE);
  raw();     // CTRL-C and others do not generate signals
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  input = getch();
  nocbreak();
  endwin();
  switch (input) {
    case KEY_LEFT: nextMovement = 1;
      printf("A gauche \n\n");
      break;
    case KEY_DOWN: nextMovement = 2;
      printf("En bas\n\n");
      break;
    case KEY_RIGHT: nextMovement = 3;
      printf("A droite\n\n");
      break;
    case KEY_UP: nextMovement = 4;
      break;
    case 'W':;
    case 'w': nextMovement = 5;
      break;
    case 'X':;
    case 'x': nextMovement = 6;
      break;
    case 'P':;
    case 'p': nextMovement = 7;
      break;
    case -1:; //retour de getch quand on a rien tapé
      break;

    default: printf("touche non définie\n");
      nextMovement = getNextMovement(mat,score,line);
  }
  return nextMovement;
}

void moveLeft(char mat[Y][X], coordBlock *block){
  int isPossible = canMoveH(mat,0,block);
  if (isPossible == 0) {
    block->leftX --;
    block->middleX --;
    block->rightX --;
  }
}

void moveRight(char mat[Y][X], coordBlock *block){
  int isPossible = canMoveH(mat,1,block);
  if (isPossible == 0){
    block->leftX ++;
    block->middleX ++;
    block->rightX ++;
  }
}

void moveDown(coordBlock *block){
  block->lineOneY ++;
  block->lineTwoY ++;
  block->lineThreeY ++;
  block->lineFourY ++;
}

void moveDownEvery(int seconds, coordBlock *block, int score, int line, int randomNumber, int position){
  int noConflict;
  // seconds = seconds * 1000;
  noConflict = canMoveV(mat, block);
  if (noConflict ==0) {
    // timeout(seconds);
    Move(mat, 2, randomNumber, &position, &score, block);
  }
}

void directDown(char mat[Y][X], int typeOfBlock, int position, coordBlock *block){
  int isPossible = canMoveV(mat,block);

  while (isPossible == 0) {
    block->lineOneY ++;
    block->lineTwoY ++;
    block->lineThreeY ++;
    block->lineFourY ++;
    matrixMovement(mat,typeOfBlock,position, block);
    isPossible = canMoveV(mat,block);
    testPrintInfo(&position,block);
  }
}

void Move(char mat[Y][X], int movement, int typeOfBlock,int *position, int *score, coordBlock *block){
  char unpause;
  switch (movement) {
    case 1: moveLeft(mat, block);
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
      case 2: moveDown(block);
      *score = *score +1;
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 3: moveRight(mat, block);
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 4: directDown(mat,typeOfBlock,*position, block);
      *score = *score +5;
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 5: //Gauche
      *position = *position +1;
      if (*position > 2) {
        *position = -1;
      }
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 6: //Droite
      *position = *position -1;
      if (*position < -2) {
        *position = 1;
      }
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 7: system("clear");
      printf("\n\n============ GAME PAUSED ============\n\n");
      printf("type a key and press enter to unpause \n");
      scanf("%c", &unpause);
      break;
  }
}

void movementHandler(char mat[Y][X], int randomNumber, int *score, int line, coordBlock *block, float seconds){
  int noConflict =0; //Determine si le bloc ne peut plus descendre + bas
  int movement;
  int position = 0;
  struct timeval start,step;
  int timeElapsed;
  // time_t start;

  show(mat,*score,line);
  if (noConflict == 0){

    nodelay(stdscr,TRUE);
    noConflict = canMoveV(mat, block); //Vérifie que le joueur peut encore descendre le bloc
    while(noConflict == 0){
      // start = time(NULL);
      gettimeofday(&start,NULL);
      gettimeofday(&step,NULL);
      timeElapsed = (((step.tv_sec - start.tv_sec)*1000000L+step.tv_usec) - start.tv_usec); //Convertit le temps mesuré en microsecondes
      while((timeElapsed< seconds*1000*1000)){ //On convertit les secondes en microsecondes
        movement = getNextMovement(mat,*score,line); // Recupère la touche
        noConflict = canMoveV(mat, block);
        if (noConflict ==0) { //On re-vérifie si on peut descendre pour éviter le bug où en appuyant sur la touche de descente au bon moment il était possible de placer des points là où on ne peut pas.
          Move(mat, movement, randomNumber, &position, score, block); //Gere le mouvement en fonction de la touche
          if ((movement > 0) && (movement < 8)) { //Pour eviter le scintillement de l'écran
            show(mat,*score,line);
          }
        }
        gettimeofday(&step,NULL);
        timeElapsed = (((step.tv_sec - start.tv_sec)*1000000L+step.tv_usec) - start.tv_usec);
      }
      noConflict = canMoveV(mat,block);
      if (noConflict == 0) {
        Move(mat, 2, randomNumber, &position, score, block);
        show(mat,*score,line);
      }
    }
    blockEnd(mat);
  }
}
