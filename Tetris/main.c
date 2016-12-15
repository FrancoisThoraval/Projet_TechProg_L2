#include "menu.h"

int main() {
  float difficulty_O_Meter = MEDIUM; //Initialisation de la difficultée
  srand(time(NULL));
  callMenuWithMusic(&difficulty_O_Meter); //Appel du menu
  return 0;
}
