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

void afficherGrilleAdverse(int grille[LARGTAB][LONGTAB])
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
        if (grille[j][i] != 10)
        {
          printf("| ");
        }
        else printf("|X");

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
    int verifcases(int grille[LARGTAB][LONGTAB],int x,int y,int nbecases,int sens)
    {
      printf("debugtest \n" );
      //DROITE
      if (sens==3)
        {
          printf("debug11 \n" );
          int i;
          for (i=y-1;i>=y-nbecases;i--)
          {
            printf("%d\n",i);
            if (grille[i][y]!=0)
            {
              return 1;
            }
          }
          return 0;
        }

        //GAUCHE
        else if (sens==2)
        {
          printf("debug12" );
          int i;
          for (i=y+1;i<=y+nbecases;i++)
          {
            if (grille[i][y]!=0)
            {
              return 1;
            }
          }
          return 0;
        }

        //HAUT
        else if (sens==1)
        {
          printf("debug13" );
          int i;
          for (i=y-1;i<=y-nbecases;i--)
          {
            if (grille[x][i]!=0)
            {
              return 1;
            }
          }
          return 0;
        }

        //BAS
        else
        {
          printf("debugt14" );
          int i;
          for (i=y+1;i>y+nbecases;i++)
          {
            if (grille[x][i]!=0)
            {
              return 1;
            }
          }
          return 0;
        }

  }

    void placerBateau(int grille1[LARGTAB][LONGTAB],int grillebis[LARGTAB][LONGTAB] , char* bateau, int nbe, char* joueur )
    {
      //A PREVOIR : JUSTE DEMANDER HORIZONTAL OU VERTICAL ET PLACER AUTO, Ajouter le nom du bateau au début pour gérer tout les bateau rapidement
      //pour le premier joueur
      int nbecases;
      switch (nbe) {
        case 2:
        nbecases = 4;
        break;
        case 3:
        nbecases = 3;
        break;
        case 4:
        nbecases = 3;
        break;
        case 5:
        nbecases = 2;
        break;
        case 6:
        nbecases = 1;
        break;
      }
      printf("%s, c'est à vous \n", &joueur);
      afficherGrille(grille1);
      printf("Pour votre %s\n",bateau);
      char choix1[2];
      int choix2=0;
      printf("Veuillez entrer le nom de votre première case \n");
      scanf("%s",choix1);
      printf("%s",choix1);
      struct coordonnees coord1 =  decouperCases(choix1);
      if (grille1[coord1.x][coord1.y]==0)
      {
        grille1[coord1.x][coord1.y]=nbe;
        afficherGrille(grille1);
        printf("Veuillez choisir entre les 4 options :  \n");
        printf("| 1 droite  \n");
        printf("| 2 gauche  \n");
        printf("| 3 haut  \n");
        printf("| 4 bas  \n");
        while(choix2<1 || choix2>4)
        {
          scanf("%d",&choix2);
        }

          //BAS
          if(choix2==4)
            {
              if (verifcases(grille1, coord1.x, coord1.y, nbecases, 1)==0)
              {
                int i;
                for (i=coord1.y+1;i<=coord1.y+nbecases;i++)
                {
                  grille1[coord1.x][i]=nbe;
                }
              }
              else
              {
                printf("debug2");

              }
            }

            //HAUT
          else if(choix2==3)
            {
              if (verifcases(grille1, coord1.x, coord1.y, nbecases, 2)==0)
              {
                int i;
                for (i=coord1.y-1;i>=coord1.y-nbecases;i--)
                {
                  grille1[coord1.x][i]=nbe;
                }
              }
              else
              {
                printf("debug3");

              }
            }

            //DROITE
            else if(choix2==1)
              {
                if (verifcases(grille1, coord1.x, coord1.y, nbecases, 3)==0)
                {
                  int i;
                  for (i=coord1.x+1;i<=coord1.x+nbecases;i++)
                  {
                    grille1[i][coord1.y]=nbe;
                  }
                }
                else
                {
                  printf("debug4");

                }
              }

              //GAUCHE
              else
                {
                  if (verifcases(grille1, coord1.x, coord1.y, nbecases, 4)==0)
                  {
                    int i;
                    for (i=coord1.x-1;i>=coord1.x-nbecases;i--)
                    {
                      grille1[i][coord1.y]=nbe;
                    }
                  }
                  else
                  {
                    printf("debug5");

                  }
                }
                afficherGrille(grille1);

      }
      afficherGrille(grille1);
    }
