#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGTAB 10
#define LONGTAB 10
#include "bateaux.c"
#include "joueur.c"
#include "actionsSurGrille.c"

int main(int argc, char **argv) {
  int grille1[LARGTAB][LONGTAB];
  int grille2[LARGTAB][LONGTAB];
  int grille1bis[LARGTAB][LONGTAB];
  int grille2bis[LARGTAB][LONGTAB];
  int ichoix = 0;
  int valider = 0;
//Menu de base à continuer
  while (ichoix<1 || ichoix>3) {
    printf("MENU : \n");
    printf("|1 Nouvelle partie : \n");
    printf("|2 Charger partie : \n");
    printf("|3 Options\n");
    printf("Entrez votre choix : ");
    scanf("%d", &ichoix);
  }
  //grille à modifier pour les rendre statiques
  if (ichoix == 1)
  {
  //test1
    char joueur1[20];
    char joueur2[20];
    char pseudo[20];
    Initialiserjoueur(1,joueur1);
    Initialiserjoueur(2,joueur2);
    initialiserGrille(grille1);
    initialiserGrille(grille2);
    initialiserGrille(grille1bis);
    initialiserGrille(grille2bis);
    // pour le joueur 1
    placerBateau(grille1,grille1bis,"Porte-Avion",2, "joueur1");
    placerBateau(grille1,grille1bis,"Croiseur",3,"joueur1");
    placerBateau(grille1,grille1bis,"Contre-Torpilleur",4,"joueur1");
    placerBateau(grille1,grille1bis,"Sous-Marin",5,"joueur1");
    placerBateau(grille1,grille1bis,"Torpilleur",6,"joueur1");
    afficherGrilleAdverse(grille1);
    system("clear");
    // pour le joueur 2
    placerBateau(grille2,grille2bis,"Porte-Avion",2,"joueur2");
    placerBateau(grille2,grille2bis,"Croiseur",3,"joueur2");
    placerBateau(grille2,grille2bis,"Contre-Torpilleur",4,"joueur2");
    placerBateau(grille2,grille2bis,"Sous-Marin",5,"joueur2");
    placerBateau(grille2,grille2bis,"Torpilleur",6,"joueur2");
    }
  /*afficherGrille(grille1);
  ichoix = afficherMenuGrille();
  if (ichoix == 1 )
    {


    }*/
  return 0;
}
