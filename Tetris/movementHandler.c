#include "movementHandler.h"
#include "matrixHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
// #include <unistd.h>


void testPrintInfo(int *position){
  extern coordBlock block;
  printf("coordonnées coordBlock:\n");
  printf("lineOneY: %d\n", block.lineOneY);
  printf("lineTwoY: %d\n", block.lineTwoY);
  printf("lineThreeY: %d\n", block.lineThreeY);
  printf("leftX: %d\n", block.leftX);
  printf("middleX: %d\n", block.middleX);
  printf("rightX: %d\n", block.rightX);
  printf("position: %d\n",*position );

}

// Fonctions qui vérifient qu'on peut encore descendre (canMoveV) ou bouger horizontalement (canMoveH)

int canMoveH(char mat[Y][X], int side){
  extern coordBlock block;
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
      if ((mat[block.lineOneY][block.leftX]=='x')) {
        if ((block.leftX -1 == -1)||(mat[block.lineOneY][block.leftX -1] == 'o')) {
          isPossibleOL = 1;
        }
      }
      if ((mat[block.lineOneY][block.middleX]=='x')) {
        if ((block.middleX -1 == -1)||(mat[block.lineOneY][block.middleX -1] == 'o')) {
          isPossibleOM = 1;
        }
      }

      if ((mat[block.lineTwoY][block.leftX]=='x')) {
        if (((block.leftX -1 == -1))||(mat[block.lineTwoY][block.leftX -1] == 'o')) {
          isPossibleTL = 1;
        }
      }
      if ((mat[block.lineTwoY][block.middleX]=='x')) {
        if ((block.middleX -1 == -1)||(mat[block.lineTwoY][block.middleX -1] == 'o')) {
          isPossibleTM = 1;
        }
      }

      if ((mat[block.lineThreeY][block.leftX]=='x')) {
        if ((block.leftX -1 == -1)||(mat[block.lineThreeY][block.leftX -1] == 'o')) {
          isPossibleThL = 1;
        }
      }
      if ((mat[block.lineThreeY][block.middleX]=='x')) {
        if ((block.middleX -1 == -1)||(mat[block.lineThreeY][block.middleX -1] == 'o')) {
          isPossibleThM = 1;
        }
      }
      if ((mat[block.lineFourY][block.leftX]=='x')) {
        if ((block.leftX -1 == -1)||(mat[block.lineFourY][block.leftX] == 'o')) {
          isPossibleFL = 1;
        }
      }
      break;
    case 1:
      printf("X: %d\n",X);
      if ((mat[block.lineOneY][block.middleX]=='x')) {
        if ((block.middleX +1 == X-1)||(mat[block.lineOneY][block.middleX +1] == 'o')) {
          isPossibleOM = 1;
          printf("i\' touching ! \n");
        }
      }
      if ((mat[block.lineOneY][block.rightX]=='x')) {
        if ((block.rightX +1 == X-1)||(mat[block.lineOneY][block.rightX +1] == 'o')) {
          isPossibleOR = 1;
          printf("i\' touching ! \n");
        }
      }

      if ((mat[block.lineTwoY][block.middleX]=='x')) {
        if ((block.middleX +1 == X-1)||(mat[block.lineTwoY][block.middleX +1] == 'o')) {
          isPossibleTM = 1;
          printf("i\' touching ! \n");
        }
      }
      if ((mat[block.lineTwoY][block.rightX]=='x')) {
        if ((block.rightX +1 == X-1)||(mat[block.lineTwoY][block.rightX +1] == 'o')) {
          isPossibleTR = 1;
          printf("i\' touching ! \n");
        }
      }

      if ((mat[block.lineThreeY][block.middleX]=='x')) {
        if ((block.middleX +1 == X-1)||(mat[block.lineThreeY][block.middleX +1] == 'o')) {
          isPossibleThM = 1;
          printf("i\' touching ! \n");
        }
      }
      if ((mat[block.lineThreeY][block.rightX]=='x')) {
        if ((block.rightX +1 == X-1)||(mat[block.lineThreeY][block.rightX +1] == 'o')) {
          isPossibleThR = 1;
          printf("i\' touching ! \n");
        }
      }

      if ((mat[block.lineFourY][block.middleX]=='x')) {
        if ((block.rightX == X-1)||(mat[block.lineFourY][block.rightX] == 'o')) {
          isPossibleFR = 1;
          printf("i\' touching ! \n");
        }
      }
      // Cas où le I est renversé
      if ((mat[block.lineTwoY][block.rightX+1]=='x')) {
        if ((block.rightX +2 == X-1)||(mat[block.lineFourY][block.rightX+2] == 'o')) {
          isPossibleFR = 1;
          printf("i\' touching ! \n");
        }
      }
      break;
  }
  isPossible = isPossibleThR + isPossibleThM + isPossibleThL + isPossibleTR + isPossibleTM + isPossibleTL + isPossibleOR + isPossibleOL + isPossibleOM + isPossibleFR + isPossibleFL;

  return isPossible;
}

// Verification verticale que l'on peut encore descendre
int canMoveV(char mat[Y][X]){
  extern coordBlock block;
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

  if ((mat[block.lineOneY][block.leftX]=='x')) {
    if ((block.lineOneY == Y-2)||(mat[block.lineOneY +1][block.leftX] == 'o')) {
      isPossibleOL = 1;
    }
  }
  if ((mat[block.lineOneY][block.middleX]=='x')) {
    if ((block.lineOneY == Y-2)||(mat[block.lineOneY +1][block.middleX] == 'o')) {
      isPossibleOM = 1;
    }
  }
  if ((mat[block.lineOneY][block.rightX]=='x')) {
    if ((block.lineOneY == Y-2)||(mat[block.lineOneY +1][block.rightX] == 'o')) {
      isPossibleOR = 1;
    }
  }

  // Verification sur deuxième ligne
  if ((mat[block.lineTwoY][block.leftX]=='x')) {
    if ((block.lineTwoY == Y-2)||(mat[block.lineTwoY +1][block.leftX] == 'o')) {
      isPossibleTL = 1;
    }
  }
  if ((mat[block.lineTwoY][block.middleX]=='x')) {
    if ((block.lineTwoY == Y-2)||(mat[block.lineTwoY +1][block.middleX] == 'o')) {
      isPossibleTM = 1;
    }
  }
  if ((mat[block.lineTwoY][block.rightX]=='x')) {
    if ((block.lineTwoY == Y-2)||(mat[block.lineTwoY +1][block.rightX] == 'o')) {
      isPossibleTR = 1;
    }
  }

  // Verification sur troisieme ligne
  if ((mat[block.lineThreeY][block.leftX]=='x')) {
    if ((block.lineThreeY == Y-2)||(mat[block.lineThreeY +1][block.leftX] == 'o')) {
      isPossibleThL = 1;
    }
  }
  if ((mat[block.lineThreeY][block.middleX]=='x')) {
    if ((block.lineThreeY == Y-2)||(mat[block.lineThreeY +1][block.middleX] == 'o')) {
      isPossibleThM = 1;
    }
  }
  if ((mat[block.lineThreeY][block.rightX]=='x')) {
    if ((block.lineThreeY == Y-2)||(mat[block.lineThreeY +1][block.rightX] == 'o')) {
      isPossibleThR = 1;
    }
  }

  // Verification sur quatrieme ligne (cas du I)
  if ((mat[block.lineFourY][block.leftX]=='x')) {
    if ((block.lineFourY == Y-2)||(mat[block.lineFourY +1][block.leftX] == 'o')) {
      isPossibleFL = 1;
    }
  }
  if ((mat[block.lineFourY][block.middleX]=='x')) {
    if ((block.lineFourY == Y-2)||(mat[block.lineFourY +1][block.middleX] == 'o')) {
      isPossibleFM = 1;
    }
  }
  if ((mat[block.lineFourY][block.rightX]=='x')) {
    if ((block.lineFourY == Y-2)||(mat[block.lineFourY +1][block.rightX] == 'o')) {
      isPossibleFR = 1;
    }
  }
  if ((block.lineFourY == Y-1)||(block.lineThreeY == Y-1)||(block.lineTwoY == Y-1)||(block.lineOneY == Y-1)) {
    if (block.lineFourY == Y-1) {
      printf("linefour touche le fond\n");
    }
    if (block.lineThreeY == Y-1) {
      printf("linethree touche le fond\n");
    }
    if (block.lineTwoY == Y-1) {
      printf("linetwo touche le fond\n");
    }
    if (block.lineOneY == Y-1) {
      printf("lineone touche le fond\n");
    }
    printf("Normalement on devrait s\'arreter test2\n");
  }
  isPossible = isPossibleThR + isPossibleThM + isPossibleThL + isPossibleTR + isPossibleTM + isPossibleTL + isPossibleOR + isPossibleOL + isPossibleOM + isPossibleFR + isPossibleFL + isPossibleFM;
  return isPossible;
}

void moveDownEvery(int seconds){
  moveDown();
  sleep(seconds);
}

int getNextMovement(){
  // On passe le terminal en mode raw pour ne pas avoir a appuyer sur entrée a chaque fois
  system ("/bin/stty raw");
  int nextMovement= 0;
  int c = getchar();
  switch (c) {
    case 'Q':;
    case 'q': nextMovement = 1;
      printf("A gauche \n\n");
      break;
    case 'S': ;
    case 's': nextMovement = 2;
      printf("En bas\n\n");
      break;
    case 'D':;
    case 'd': nextMovement = 3;
      printf("A droite\n\n");
      break;
    case 'Z':;
    case 'z': nextMovement = 4;
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
  }
  // On repasse le terminal en mode normal
  system ("/bin/stty cooked");
  return nextMovement;
}

void moveLeft(char mat[Y][X]){
  extern coordBlock block;
  int isPossible = canMoveH(mat,0);
  if (isPossible == 0) {
    block.leftX --;
    block.middleX --;
    block.rightX --;
  }
}

void moveRight(char mat[Y][X]){
  extern coordBlock block;
  int isPossible = canMoveH(mat,1);
  if (isPossible == 0){
    block.leftX ++;
    block.middleX ++;
    block.rightX ++;
  }
}

void moveDown(){
  extern coordBlock block;
  block.lineOneY ++;
  block.lineTwoY ++;
  block.lineThreeY ++;
  block.lineFourY ++;
  if ((block.lineFourY == Y-1)||(block.lineThreeY == Y-1)||(block.lineTwoY == Y-1)||(block.lineOneY == Y-1)) {
    printf("Normalement on devrait s\'arreter test 1\n");
  }
}

void directDown(char mat[Y][X], int typeOfBlock, int position){
  extern coordBlock block;
  int isPossible = canMoveV(mat);

  while (isPossible == 0) {
    block.lineOneY ++;
    block.lineTwoY ++;
    block.lineThreeY ++;
    block.lineFourY ++;
    matrixMovement(mat,typeOfBlock,position);
    isPossible = canMoveV(mat);
    testPrintInfo(&position);
  }
}

void Move(char mat[Y][X], int movement, int typeOfBlock,int *position, int *score){
  char unpause;
  switch (movement) {
    case 1: moveLeft(mat);
      matrixMovement(mat,typeOfBlock,*position);
      break;
    case 2: moveDown(mat);
      *score = *score +1;
      matrixMovement(mat,typeOfBlock,*position);
      break;
    case 3: moveRight(mat);
      matrixMovement(mat,typeOfBlock,*position);
      break;
    case 4: directDown(mat,typeOfBlock,*position);
      *score = *score +5;
      matrixMovement(mat,typeOfBlock,*position);
      break;
    case 5: //Gauche
      *position = *position +1;
      if (*position > 2) {
        *position = -1;
      }
      matrixMovement(mat,typeOfBlock,*position);
      break;
    case 6: //Droite
      *position = *position -1;
      if (*position < -2) {
        *position = 1;
      }
      matrixMovement(mat,typeOfBlock,*position);
      break;
    case 7: printf("\n\n============ GAME PAUSED ============\n\n");
      printf("type a key and press enter to unpause \n");
      scanf("%c", &unpause);
      break;
  }
}

void movementHandler(char mat[Y][X], int randomNumber, int *score, int line){
  extern coordBlock block;
  // struct timeval tv;

  int noConflict =0; //Determine si le bloc ne peut plus descendre + bas
  int movement;
  int position = 0;
  // int seconds = 1;
  if (noConflict == 0){
    noConflict = canMoveV(mat); //Vérifie que le joueur peut encore descendre le bloc
    while(noConflict == 0){
      movement = getNextMovement(); //Voir kb_hit et getch()
      Move(mat, movement, randomNumber, &position, score);
      show(mat,*score,line);
      testPrintInfo(&position);
      noConflict = canMoveV(mat);
    }
    blockEnd(mat);
  }
  else
    printf("touching\n");
}
