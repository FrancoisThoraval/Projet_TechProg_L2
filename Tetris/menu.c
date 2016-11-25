#include "menu.h"

void displayMenu(int i){
  switch (i) {
    case 1:
      erase();
      printw("-----------------------------------------------------\n");
      printw("-->  PLAY\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 2:
      erase();
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("-->  OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 3:
      erase();
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     OPTIONS\n");
      printw("-->  BEST SCORES\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 4:
      erase();
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("-->  EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
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
      printw("En bas\n\n");
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
          printw("Playing !\n");
          break;
        case 2: /*options();*/
          printw("Options !\n");
          break;
        case 3: /*bestScores()*/
          printw("Looking to the best scores !\n");
          break;
        case 4:
          printw("Leaving !\n");
          exit(0);
          break;
      }
      break;

    case -1:; //retour de getch quand on a rien tapé
      break;

    default: printw("touche non définie\n");
      nextMovement = menuMovement(pitem);
  }
  return nextMovement;
}

void menu(){
  int item = 1;
  int input;
  initscr();
  erase();
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
