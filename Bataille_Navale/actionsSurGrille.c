void afficherGrille(int grille[LARGTAB][LONGTAB])
{
  int i,j,ligne;
  printf("  |A|B|C|D|E|F|G|H|I|J\n" );
  for(i=0;i<10;i++)
  {
    ligne = i+1;
    printf("%d",ligne);
    if (i<9){
    printf(" ");
  }
      for (j = 0; j < 10; j++)
      {
        if (grille[i][j] == 0)
        {
          printf("| ");
        }
        else if(grille[i][j]==1)
        {
          printf("|X");
        }
      }
      printf("\n");
  }
}

int afficherMenuGrille(){
  int ichoix = 0;
  while (ichoix<1 || ichoix>2)
  {
    printf("MENU : \n");
    printf("|1 Choisir Cases : \n");
    printf("|2 Abandonner : \n");
    scanf("%d", &ichoix);
  }
  return ichoix;
}

void initialiserGrille(int grille[LARGTAB][LONGTAB]){
  int i,j;
  for(i=0;i<10;i++)
  {
      for (j = 0; j < 10; j++)
      {
        grille[i][j]=0;
      }
  }
  }

  char choisirCase()
  {
    //à commencer



  }


  struct coordonnees decouperCases(char case0[1])
    {
      int y = (int)case0[1]-1;
      int x = (int)case0[0]-41;
      struct coordonnees coord;
      coord.x=x;
      coord.y=y;
      return coord;


    }
