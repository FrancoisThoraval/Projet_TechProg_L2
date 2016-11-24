#include "menu.h"

void displayMenu(int i){
  system("clear");
  switch (i) {
    case 1:
      printf("-----------------------------------------------------\n");
      printf("-->  PLAY\n");
      printf("     OPTIONS\n");
      printf("     BEST SCORES\n");
      printf("     EXIT\n");
      printf("-----------------------------------------------------\n");
      printf("Note: Use up arrow and down arrow to move\n");
      printf("      Backspace to choose\n");
      break;
    case 2:
      printf("-----------------------------------------------------\n");
      printf("     PLAY\n");
      printf("-->  OPTIONS\n");
      printf("     BEST SCORES\n");
      printf("     EXIT\n");
      printf("-----------------------------------------------------\n");
      printf("Note: Use up arrow and down arrow to move\n");
      printf("      Backspace to choose\n");
      break;
    case 3:
      printf("-----------------------------------------------------\n");
      printf("     PLAY\n");
      printf("     OPTIONS\n");
      printf("-->  BEST SCORES\n");
      printf("     EXIT\n");
      printf("-----------------------------------------------------\n");
      printf("Note: Use up arrow and down arrow to move\n");
      printf("      Backspace to choose\n");
      break;
    case 4:
      printf("-----------------------------------------------------\n");
      printf("     PLAY\n");
      printf("     OPTIONS\n");
      printf("     BEST SCORES\n");
      printf("-->  EXIT\n");
      printf("-----------------------------------------------------\n");
      printf("Note: Use up arrow and down arrow to move\n");
      printf("      Backspace to choose\n");
      break;
  }
}

int menuMovement(int *pitem){

  int nextMovement= 0;
  int input;
  keypad(stdscr, TRUE);
  // raw();     // CTRL-C and others do not generate signals
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  input = getch();
  nocbreak();
  endwin();
  switch (input) {
    case KEY_UP: nextMovement = 1;
      printf("En bas\n\n");
      *pitem = *pitem-1;
      if (*pitem == 0) {
        *pitem = 4;
      }
      break;
    case KEY_DOWN: nextMovement = 2;
      *pitem = *pitem+1;
      if (*pitem == 5) {
        *pitem = 1;
      }
      break;
    case KEY_BACKSPACE: nextMovement = 3;
      switch (*pitem) {
        case 1: play();
          printf("Playing !\n");
          break;
        case 2: /*options();*/
          printf("Options !\n");
          break;
        case 3: /*bestScores()*/
          printf("Looking to the best scores !\n");
          break;
        case 4:
          printf("Leaving !\n");
          exit(0);
          break;
      }
      break;

    case -1:; //retour de getch quand on a rien tapé
      break;

    default: printf("touche non définie\n");
      nextMovement = menuMovement(pitem);
  }
  return nextMovement;
}

void menu(){
  int item = 1;
  int input;
  initscr();
  noecho();
  refresh();
  endwin();
  displayMenu(item);
  input = menuMovement(&item);
  while (input != KEY_ENTER) {
    displayMenu(item);
    input = menuMovement(&item);
  }
}
