#ifndef definition_h
#define definition_h

// IMPORTANT !!!
// La prediction du placement du bloc n'etant absolument pas optimisée (appels récurssifs dans une boucle while + double boucle for),
// si l'on veut s'amuser sur une grille plus grande,
// il faut mettre PREDICTION à une autre valeur que 0 ! (désactive la prediction)
#define PREDICTION 0

// TAILLE DE LA GRILLE
#define X 10
#define Y 12

//TAILLE DE TABLEAUX
#define lengthName 20
#define nbOldScore 10
#define SONGNAME 50

// DIFFICULTE
#define NEWLEVEL 10

#define CHILL 1
#define EASY 2
#define MEDIUM 3
#define HARD 4
#define PROGAMER 5
#define UNBEARABLE 6

// STRUCTURE CONTENANT LES COORDONNEE DU BLOC JOUÉ
typedef struct{
  int leftX;
  int middleX;
  int rightX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
  int lineFourY;
}coordBlock;

// STRUCTURE CONTENANT LES ELEMENT A SAUVEGARDER DANS LES FICHIER "score.txt" ET "score2.txt"
typedef struct{
  int score;
  int line;
  int tries;
  char name[lengthName];
}saveScore;

#endif
