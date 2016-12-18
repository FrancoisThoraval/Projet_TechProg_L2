#include "movementHandler.h"

// canRotate, canMoveH et canMoveV fonctionnent de la même facon, on regarde s'il y a un caractère 'x' autour des coordonnées (recherche du bloc)
// et on essaie si la position future de ce caractère sera possible ou non.
int canRotate(int direction, coordBlock *block, int typeOfBlock, int *position, char mat[Y][X]){
  int isPossibleA = 0;
  int isPossibleB = 0;
  int isPossibleC = 0;
  int isPossibleD = 0;
  int isPossibleE = 0;
  int isPossibleF = 0;
  int isPossibleG = 0;
  int isPossibleH = 0;

  switch (direction) {
    case 0: //Pivot gauche
      if ((mat[block->lineOneY][block->rightX]=='x')) {
        if ((block->leftX == -1)||(mat[block->lineOneY][block->leftX] == 'o')) {
          isPossibleA = 1;
        }
      }
      if ((mat[block->lineOneY][block->middleX]=='x')) {
        if ((block->leftX == -1)||(mat[block->lineTwoY][block->leftX] == 'o')) {
          isPossibleB = 1;
        }
      }
      if ((mat[block->lineOneY][block->leftX]=='x')) {
        if ((block->leftX == -1)||(mat[block->lineThreeY][block->leftX] == 'o')) {
          isPossibleC = 1;
        }
      }
      if ((mat[block->lineTwoY][block->leftX]=='x')) {
        if ((block->middleX == -1)||(mat[block->lineThreeY][block->middleX] == 'o')) {
          isPossibleD = 1;
        }
      }
      if ((mat[block->lineOneY][block->rightX]=='x')) {
        if ((block->middleX == -1)||(mat[block->lineOneY][block->rightX] == 'o')) {
          isPossibleE = 1;
        }
      }
      if ((mat[block->lineThreeY][block->leftX]=='x')) {
        if ((block->rightX == -1)||(mat[block->lineThreeY][block->rightX] == 'o')) {
          isPossibleF = 1;
        }
      }
      if ((mat[block->lineThreeY][block->middleX]=='x')) {
        if ((block->rightX == -1)||(mat[block->lineTwoY][block->rightX] == 'o')) {
          isPossibleG = 1;
        }
      }
      // Cas du I
      if ((mat[block->lineThreeY][block->rightX]=='x')) {
        if ((block->rightX == -1)||(mat[block->lineOneY][block->rightX] == 'o')) {
          isPossibleH = 1;
        }
      }

      break;
    case 1:
      if ((mat[block->lineOneY][block->leftX]=='x')) {
        if ((block->rightX == X-1)||(mat[block->lineOneY][block->rightX] == 'o')) {
          isPossibleA = 1;
        }
      }
      if ((mat[block->lineOneY][block->middleX]=='x')) {
        if ((block->rightX == X-1)||(mat[block->lineTwoY][block->rightX] == 'o')) {
          isPossibleB = 1;
        }
      }
      if ((mat[block->lineOneY][block->rightX]=='x')) {
        if ((block->rightX == X-1)||(mat[block->lineThreeY][block->rightX] == 'o')) {
          isPossibleC = 1;
        }
      }
      if ((mat[block->lineTwoY][block->leftX]=='x')) {
        if ((block->middleX == X-1)||(mat[block->lineOneY][block->middleX] == 'o')) {
          isPossibleD = 1;
        }
      }
      if ((mat[block->lineOneY][block->rightX]=='x')) {
        if ((block->middleX == X-1)||(mat[block->lineThreeY][block->middleX] == 'o')) {
          isPossibleE = 1;
        }
      }
      if ((mat[block->lineThreeY][block->leftX]=='x')) {
        if ((block->leftX == X-1)||(mat[block->lineOneY][block->leftX] == 'o')) {
          isPossibleF = 1;
        }
      }
      if ((mat[block->lineThreeY][block->middleX]=='x')) {
        if ((block->leftX == X-1)||(mat[block->lineTwoY][block->leftX] == 'o')) {
          isPossibleG = 1;
        }
      }
      if ((mat[block->lineThreeY][block->rightX]=='x')) {
        if ((block->leftX == X-1)||(mat[block->lineThreeY][block->leftX] == 'o')) {
          isPossibleH = 1;
        }
      }
      // Cas du I
      if ((mat[block->lineFourY][block->middleX]=='x')) {
        if ((block->rightX+1 == X-1)||(mat[block->lineOneY][block->rightX+1] == 'o')) {
          isPossibleH = 1;
        }
      }
      break;
  }
  return (isPossibleA + isPossibleB + isPossibleC + isPossibleD + isPossibleE + isPossibleF + isPossibleG + isPossibleH);
}

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
      break;
    case 1:
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

  if ((block->lineOneY >= Y-2)&&(block->lineTwoY >= Y-2)&&(block->lineThreeY >= Y-2)&&(block->lineFourY >= Y-2)) {
    return 1;
  }

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
  if ((mat[block->lineTwoY][block->rightX+1]=='x')) {
    if ((block->lineFourY == Y)||(mat[block->lineFourY -1][block->rightX+1] == 'o')) {
      isPossibleFR = 1;
    }
  }

  isPossible = isPossibleThR + isPossibleThM + isPossibleThL + isPossibleTR + isPossibleTM + isPossibleTL + isPossibleOR + isPossibleOL + isPossibleOM + isPossibleFR + isPossibleFL + isPossibleFM;
  return isPossible;
}

int getNextMovement(char mat[Y][X],int score, int line){
  Mix_Chunk *sample = NULL;
  int epileptic = randomize(4)+1;
  int nextMovement= 0;
  int input;
  keypad(stdscr, TRUE);
  // raw();     // CTRL-C and others do not generate signals
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  input = getch();
  nocbreak();
  //refresh();
  switch (input) {
    case KEY_LEFT: nextMovement = 1;
      attron(COLOR_PAIR(epileptic));
      // printf("A gauche \n\n");
      break;
    case KEY_DOWN: nextMovement = 2;
      // printf("En bas\n\n");
      break;
    case KEY_RIGHT: nextMovement = 3;
      attron(COLOR_PAIR(epileptic));
      // printf("A droite\n\n");
      break;
    case KEY_UP: nextMovement = 4;
      attron(COLOR_PAIR(epileptic));
      break;
    case 'W':;
    case 'w': nextMovement = 5;
      attron(COLOR_PAIR(epileptic));
      break;
    case 'X':;
    case 'x': nextMovement = 6;
      attron(COLOR_PAIR(epileptic));

      break;
    case 'P':;
    case 'p': nextMovement = 7;
      attron(COLOR_PAIR(epileptic));
      break;
    case -1:; //retour de getch quand on a rien tapé
      break;

    default: playSample(10,sample);
      nextMovement = getNextMovement(mat,score,line);
  }
  free(sample);
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

void directDown(char mat[Y][X], int typeOfBlock, int position, coordBlock *block){
  int isPossible = canMoveV(mat,block);

  while (isPossible == 0) {
    block->lineOneY ++;
    block->lineTwoY ++;
    block->lineThreeY ++;
    block->lineFourY ++;
    matrixMovement(mat,typeOfBlock,position, block);
    isPossible = canMoveV(mat,block);
  }
}

void Move(char mat[Y][X], int movement, int typeOfBlock,int *position, int *score, coordBlock *block){
  char unpause;
  Mix_Chunk *sample = NULL;
  switch (movement) {
    case 1: moveLeft(mat, block);
      playSample(1,sample);
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
      case 2: moveDown(block);
      *score = *score +1;
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 3: moveRight(mat, block);
      playSample(1,sample);
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 4: directDown(mat,typeOfBlock,*position, block);
      playSample(6,sample);
      *score = *score +5;
      matrixMovement(mat,typeOfBlock,*position, block);
      break;
    case 5: //Gauche
      if ((canRotate(0, block, typeOfBlock, position, mat)==0)&&(canRotate(1, block, typeOfBlock, position, mat)==0)) {
        *position = *position +1;
        if (*position > 2) {
          *position = -1;
        }
        matrixMovement(mat,typeOfBlock,*position, block);
      }
      break;
    case 6: //Droite
      if ((canRotate(1, block, typeOfBlock, position, mat)==0)&&(canRotate(0, block, typeOfBlock, position, mat)==0)) {
        *position = *position -1;
        if (*position < -2) {
          *position = 1;
        }
        matrixMovement(mat,typeOfBlock,*position, block);
      }
      break;
    case 7:
      // system("clear");
      erase();
      refresh();
      printw("\n\n============ GAME PAUSED ============\n\n");
      printw("type a key and press enter to unpause \n");
      do {
        unpause = getch();
      } while(unpause == ERR);
      break;
  }
  free(sample);
}

void movementHandler(char mat[Y][X], int randomNumber, int *score, int *line, coordBlock *block, float seconds, int level, int tries){
  int noConflict =0; //Determine si le bloc ne peut plus descendre + bas
  int movement;
  int position = 0;
  struct timeval start,step;
  int timeElapsed;
  // time_t start;
  refresh();
  show(mat,*score,*line,tries);
  if (noConflict == 0){

    nodelay(stdscr,TRUE);
    noConflict = canMoveV(mat, block); //Vérifie que le joueur peut encore descendre le bloc
    while(noConflict == 0){

      // start = time(NULL);
      gettimeofday(&start,NULL);
      gettimeofday(&step,NULL);
      // on mesure le temps
      timeElapsed = (((step.tv_sec - start.tv_sec)*1000000L+step.tv_usec) - start.tv_usec); //Convertit le temps mesuré en microsecondes
      while((timeElapsed< seconds*1000*1000)){ //On convertit les secondes en microsecondes
        movement = getNextMovement(mat,*score,*line); // Recupère la touche
        noConflict = canMoveV(mat, block);
        if (noConflict ==0) { //On re-vérifie si on peut descendre pour éviter le bug où en appuyant sur la touche de descente au bon moment il était possible de placer des points là où on ne peut pas.
          Move(mat, movement, randomNumber, &position, score, block); //Gere le mouvement en fonction de la touche
          if ((movement > 0) && (movement < 8)) { //Pour eviter le scintillement de l'écran
            show(mat,*score,*line,tries);
          }
        }
        gettimeofday(&step,NULL);
        timeElapsed = (((step.tv_sec - start.tv_sec)*1000000L+step.tv_usec) - start.tv_usec);
      }
      noConflict = canMoveV(mat,block);
      if (noConflict == 0) {
        Move(mat, 2, randomNumber, &position, score, block);
        refresh();
        show(mat,*score,*line,tries);
      }
    }
    blockEnd(mat);
    checkLines(mat, score, line, level);
  }
}
