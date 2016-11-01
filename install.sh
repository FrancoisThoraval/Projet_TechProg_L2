#!/usr/bin/env bash
echo "Installation de la bataille navale ..."
echo "Veuillez patienter"
# make ./Bataille_Navale/
# Si retour reussi
retour=$?
if [[ retour == 0 ]]; then
  echo "Installation réussie !"
fi

echo "Installation du tetris ..."
echo "Veuillez patienter"

make ./Tetris/main.c
retour=$?
if [[ retour == 0 ]]; then
  echo "Installation réussie !"
fi
touch ./Tetris/score.txt
echo "Success !!"
