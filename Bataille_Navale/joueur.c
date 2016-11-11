  struct joueur {
    char pseudo;
    int joue;
    int victoire;
  }joueur;

struct joueur Initialiserjoueur(struct joueur joueur)
{
  char pseudo;
  printf("Veuillez entrer votre pseudonyme : " );
  scanf("%c\n",pseudo);
  joueur.pseudo=pseudo;
  joueur.joue=0;
  joueur.victoire=0;
}
