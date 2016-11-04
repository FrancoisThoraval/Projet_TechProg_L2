#include <stdio.h>
#define LARGTAB 10
#define LONGTAB 10
#include "bateaux.c"
#include "joueur.c"
#include "actionsSurGrille.c"

int main(int argc, char **argv) {
  int ichoix = 0;
//Menu de base à continuer
/*  while (ichoix<1 | ichoix>3) {
  printf("MENU : \n");
  printf("|1 Nouvelle partie : \n");
  printf("|2 Charger partie : \n");
  printf("|3 Options\n");
  scanf("%d\n", &ichoix);
}*/
  //grille à modifier pour les rendre statiques
  int grille1[LARGTAB][LONGTAB];
  int grille2[LARGTAB][LONGTAB];
  initialiserGrille(grille1);
  afficherGrille(grille1);
  ichoix = afficherMenuGrille();
  if (ichoix == 1 )
    {


    }
  return 0;
}
