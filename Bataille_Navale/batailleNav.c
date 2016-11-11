#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGTAB 10
#define LONGTAB 10
#include "bateaux.c"
#include "joueur.c"
#include "actionsSurGrille.c"

int main(int argc, char **argv) {
  int ichoix = 0;
  int valider = 0;
//Menu de base à continuer
  /*while (ichoix<1 | ichoix>3) {
  printf("MENU : \n");
  printf("|1 Nouvelle partie : \n");
  printf("|2 Charger partie : \n");
  printf("|3 Options\n");
  scanf("%d\n", &ichoix);
}*/
  //grille à modifier pour les rendre statiques
  int grille1[LARGTAB][LONGTAB];
  int grille2[LARGTAB][LONGTAB];
  int grille1bis[LARGTAB][LONGTAB];
  int grille2bis[LARGTAB][LONGTAB];
  //test1
  initialiserGrille(grille1);
  initialiserGrille(grille2);
  initialiserGrille(grille1bis);
  initialiserGrille(grille2bis);
  placerBateau(grille1,grille1bis,"Porte-Avion",2);
  placerBateau(grille1,grille1bis,"Croiseur",3);
  placerBateau(grille1,grille1bis,"Contre-Torpilleur",4);
  placerBateau(grille1,grille1bis,"Sous-Marin",5);
  placerBateau(grille1,grille1bis,"Torpilleur",6);

  /*afficherGrille(grille1);
  ichoix = afficherMenuGrille();
  if (ichoix == 1 )
    {


    }*/
  return 0;
}
