#!/usr/bin/env bash
RED='\033[31m'
GREENLIGHT='\033[32m'
YELLOW='\033[33m'
NC='\033[0m' # No Color
echo -e "${RED}/!\ Installateur automatique de la bataille navale indisponible ... ${NC}"
# echo "Installation de la bataille navale ..."
# echo "Veuillez patienter"
# make ./Bataille_Navale/
# Si retour reussi
# retour=$?
# if [[ $retour -eq 0 ]];
# then
#   echo "${GREENLIGHT}Installation réussie !${NC}"
# else
#   echo "${YELLOW}NOTE:"
#   echo "Verifiez que vous avez bien la sdl ainsi que le sdl-mixer d'installé sur votre machine${NC}"
# fi

echo "Installation du tetris ..."
echo "Veuillez patienter"

make ./Tetris/main.c
retour=$?
if [[ $retour -eq 0 ]];
then
  echo -e "${GREENLIGHT}Installation réussie !${NC}"
else
  echo -e "${YELLOW}NOTE:"
  echo -e "Verifiez que vous avez bien la sdl ainsi que le sdl-mixer d'installé sur votre machine${NC}"
fi

echo "setup des scores"
cd Tetris/
rm *.txt
touch ./score.txt
touch ./score2.txt

echo "19999 0 DrNo" >> score.txt
echo "9999 0 Goldfinger" >> score.txt
echo "6000 0 Blofeld" >> score.txt
echo "4000 0 Requin" >> score.txt
echo "2000 0 Scaramanga" >> score.txt
echo "1000 0 MrWhite" >> score.txt
echo "666 0 LeChiffre" >> score.txt
echo "500 0 King" >> score.txt
echo "100 0 Largo" >> score.txt
echo "0 0 Moneypenny" >> score.txt

echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt
echo "0 0 0 noName" >> score2.txt

echo "Success !!"
cd ../
