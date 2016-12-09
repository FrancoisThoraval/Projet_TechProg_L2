#include "menu.h"
#include "musicHandler.h"

int main() {
  float difficulty_O_Meter = MEDIUM;
  srand(time(NULL));
  callMenuWithMusic(&difficulty_O_Meter);
  return 0;
}
