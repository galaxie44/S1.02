/************************************************************
                     ENTETE DU PROGRAMME
************************************************************/

/*
 Programme : fichier pour les déclarations de toutes les fonctions/procédures
 But :
 Date de dernière modification :
 Auteur : E.CLEMENCEAU
 Remarques : Code conforme aux spécification internes données en cours
*/

/************************************************************
                         INCLUSION
************************************************************/
#include <iostream>
using namespace std;

/************************************************************
                     PROGRAMME PRINCIPAL
************************************************************/
// Variables
const unsigned short int NOMBRES_LIGNES = 3;
const unsigned short int NOMBRES_COLONNES = 3;

// Déclarations de toutes les procédures :

void afficherRegles();
// But : Afficher les regles de la partie

void saisiePlacementSymbole(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int &ligne, unsigned short int &colonne, string &symbole, string &joueurCourrant, string &choix, unsigned short int &numTour);
// But : Placer un symbole dans la grille

void afficherGrille(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], const unsigned short int NOMBRES_LIGNES, const unsigned short int NOMBRES_COLONNES);
// But : Afficher la grille de morpion 

void placerSymbole(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int &ligne, unsigned short int &colonne, string &symbole);






// Déclaration de toutes les fonctions :

bool verifPlacement(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int &ligne, unsigned short int &colonne, unsigned short int &numTour);
// But : Vérifier si le placement un symbole a déja été placé dans le tableau ou le choix a été fait 


