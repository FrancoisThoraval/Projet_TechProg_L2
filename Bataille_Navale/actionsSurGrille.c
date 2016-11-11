struct tir{
  struct coordonnees coord1;
  struct coordonnees coord2;
  struct coordonnees coord3;
}tir;


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
        if (grille[j][i] == 0)
        {
          printf("| ");
        }
        else if(grille[j][i]==1)
        {
          printf("|X");
        }
        else if(grille[j][i]==2)
        {
          printf("|P");
        }
        else if(grille[j][i]==3)
        {
          printf("|C");
        }
        else if(grille[j][i]==4)
        {
          printf("|K");
        }
        else if(grille[j][i]==5)
        {
          printf("|S");
        }
        else if(grille[j][i]==6)
        {
          printf("|T");
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


  struct coordonnees decouperCases(char case0[2])
    {
      int y = (int)case0[1]-49;
      int x = (int)case0[0]-65;
      struct coordonnees coord;
      coord.x=x;
      coord.y=y;
      printf("x= %d \n",x);
      printf("y= %d \n",y);
      return coord;
    }


  struct tir choisirCaseTir()
  {
    char choix1,choix2,choix3;
    printf("Veuillez entrer le nom de votre première case \n");
    scanf("%c", choix1);
    printf("Veuillez entrer le nom de votre seconde case \n");
    scanf("%c", &choix2);
    printf("Veuillez entrer le nom de votre troisième case \n");
    scanf("%c", &choix3);
    struct tir tir;
    tir.coord1 = decouperCases(&choix1);
    tir.coord2 = decouperCases(&choix2);
    tir.coord3 = decouperCases(&choix3);
    return tir;
  }

    void placerBateau(int grille1[LARGTAB][LONGTAB],int grillebis[LARGTAB][LONGTAB] , char* bateau, int nbe )
    {
      //A PREVOIR : JUSTE DEMANDER HORIZONTAL OU VERTICAL ET PLACER AUTO, Ajouter le nom du bateau au début pour gérer tout les bateau rapidement
      //pour le premier joueur
      afficherGrille(grille1);
      //premier Porte avion
      printf("Pour votre %s\n",bateau);
      char choix1[2];
      printf("Veuillez entrer le nom de votre première case \n");
      scanf("%s",choix1);
      printf("%s",choix1);
      struct coordonnees coord1 =  decouperCases(choix1);
      grille1[coord1.x][coord1.y]=nbe;

      printf("Veuillez entrer le nom de votre seconde case \n");
      scanf("%s",choix1);
      printf("DEBUG0 \n");
      coord1 =  decouperCases(choix1);
      if(grille1[coord1.x-1][coord1.y]==nbe || grille1[coord1.x+1][coord1.y]==nbe || grille1[coord1.x][coord1.y-1]==nbe || grille1[coord1.x][coord1.y+1]==nbe)
      {
        grille1[coord1.x][coord1.y]=nbe;
        printf("DEBUG \n");
      }
      else
      {
        while(grille1[coord1.x-1][coord1.y]!=nbe && grille1[coord1.x+1][coord1.y]!=nbe && grille1[coord1.x][coord1.y-1]!=nbe && grille1[coord1.x][coord1.y+1]!=nbe)
        {
          printf("Veuillez entrer le nom de votre seconde case  \n");
          scanf("%s",choix1);
          coord1 =  decouperCases(choix1);
        }
        grille1[coord1.x][coord1.y]=nbe;
        printf("DEBUG3 \n");
      }
      if (bateau == "Porte-Avion" || bateau == "Croiseur" || bateau == "Contre-Torpilleur" || bateau == "Sous-Marin" ) {
      printf("Veuillez entrer le nom de votre troisième case \n");
      scanf("%s",choix1);
      coord1 =  decouperCases(choix1);
      if(grille1[coord1.x-1][coord1.y]==nbe || grille1[coord1.x+1][coord1.y]==nbe || grille1[coord1.x][coord1.y-1]==nbe || grille1[coord1.x][coord1.y+1]==nbe)
      {
        grille1[coord1.x][coord1.y]=nbe;
      }
      else
      {
        while(grille1[coord1.x-1][coord1.y]==nbe && grille1[coord1.x+1][coord1.y]==nbe && grille1[coord1.x][coord1.y-1]==nbe && grille1[coord1.x][coord1.y+1]==nbe)
        {
          printf("Veuillez entrer le nom de votre troisième case  \n");
          scanf("%s",choix1);
          coord1 =  decouperCases(choix1);
        }
        grille1[coord1.x][coord1.y]=nbe;
      }

      if (bateau == "Porte-Avion" || bateau == "Croiseur") {
      printf("Veuillez entrer le nom de votre quatrième case \n");
      scanf("%s",choix1);
      coord1 =  decouperCases(choix1);
      if(grille1[coord1.x-1][coord1.y]==nbe || grille1[coord1.x+1][coord1.y]==nbe || grille1[coord1.x][coord1.y-1]==nbe || grille1[coord1.x][coord1.y+1]==nbe)
      {
        grille1[coord1.x][coord1.y]=nbe;
      }
      else
      {
        while(grille1[coord1.x-1][coord1.y]==nbe && grille1[coord1.x+1][coord1.y]==nbe && grille1[coord1.x][coord1.y-1]==nbe && grille1[coord1.x][coord1.y+1]==nbe)
        {
          scanf("%s",choix1);
          coord1 =  decouperCases(choix1);
        }
        grille1[coord1.x][coord1.y]=nbe;
      }
      if (bateau == "Porte-Avion") {
      printf("Veuillez entrer le nom de votre cinquième case \n");
      scanf("%s",choix1);
      coord1 =  decouperCases(choix1);
      if(grille1[coord1.x-1][coord1.y]==nbe || grille1[coord1.x+1][coord1.y]==nbe || grille1[coord1.x][coord1.y-1]==nbe || grille1[coord1.x][coord1.y+1]==nbe)
      {
        grille1[coord1.x][coord1.y]=nbe;
      }
      else
      {
        while(grille1[coord1.x-1][coord1.y]==nbe && grille1[coord1.x+1][coord1.y]==nbe && grille1[coord1.x][coord1.y-1]==nbe && grille1[coord1.x][coord1.y+1]==nbe)
        {
          scanf("%s",choix1);
          coord1 =  decouperCases(choix1);
        }
        grille1[coord1.x][coord1.y]=nbe;
      }
    }
    }
  }
      afficherGrille(grille1);
    }
