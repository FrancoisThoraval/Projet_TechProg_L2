struct coordonnees {
  int x;
  int y;
} coordonnees;
  typedef enum Bateau typeBateau;
  enum typeBateau {
    TORPILLEUR,CONTRETORPILLEUR,PORTEAVION,CROISEUR,SOUSMARIN
};

  struct PorteAvion{
    struct coordonnees coord1;
    struct coordonnees coord2;
    struct coordonnees coord3;
    struct coordonnees coord4;
    struct coordonnees coord5;
    int etat;
  }PorteAv;
  struct Croiseur{
    struct coordonnees coord1;
    struct coordonnees coord2;
    struct coordonnees coord3;
    struct coordonnees coord4;
    int etat;
  }Crois;
  struct ContreTorpilleur{
    struct coordonnees coord1;
    struct coordonnees coord2;
    struct coordonnees coord3;
    int etat;
  }Contre;
  struct SousMarin{
    struct coordonnees coord1;
    struct coordonnees coord2;
    struct coordonnees coord3;
    int etat;
  }SousM;
  struct Torpilleur{
    struct coordonnees coord1;
    struct coordonnees coord2;
    int etat;
  }Torp;
