/************************************************************
                     ENTETE DU PROGRAMME
************************************************************/

/*
 Programme : Fichier contenant toutes les définitions de fonctions/procédures contenues dans le fichier sp_sae_morpion.h
 But :
 Date de dernière modification :
 Auteur : E.CLEMENCEAU
 Remarques : Code conforme aux spécification internes données en cours
*/

/************************************************************
                         INCLUSION
************************************************************/
#include <iostream>
#include "sp_sae_morpion.h"
using namespace std;

/************************************************************
                     PROGRAMME PRINCIPAL
************************************************************/

///////////////////////////////////////////
/////////////// PROCEDURES ////////////////
///////////////////////////////////////////

void afficherRegles()
{
    cout << "----------------------  M O R P I O N  ----------------------" << endl
         << endl
         << "Jeux avec 2 joueurs humains et une grille de 9 cases : 3 lignes et 3 colonnes." << endl
         << "Chaque joueur joue a tour de role." << endl
         << "Le but du jeu est d'alligner, avant son adversaire, 3 symboles identiques, horizontalement, verticalement ou en diagonale" << endl
         << endl
         << "La partie se termine : " << endl
         << "- Quand l'un des joueurs a aligne ses 3 symboles, et il gagne." << endl
         << "- Quand la grille est complete, et il y a egalite (pas de gagnant)." << endl
         << "- Quand l'un des joueurs abandonne, et c'est alors l'autre joueur qui gagne."
         << "Chaque joueur a donc son propre symbole." << endl
         << endl
         << "Dans cette version du morpion une phase prealable de personalisation du morpion permet a chaque joueur de saisir son prenom et le symbole choisi pour jouer." << endl
         << "Lorsqu'arrive son tour de jouer, un joueur peut : " << endl
         << "- Saisir la position de la case ou placer son symbole, sous la forme LigneColonne (exemple : 12 pour Ligne 1, Colonne 2)" << endl
         << "- Saisir A ( ou a ) pour abandonner le jeu" << endl
         << endl
         << "-------------------------------------------------------------" << endl
         << endl;
}

void afficherGrille(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], const unsigned short int NOMBRES_LIGNES, const unsigned short int NOMBRES_COLONNES)
{
    for (unsigned short int i = 0; i < NOMBRES_LIGNES; ++i)
    {
        cout << "\t[";
        for (unsigned short int j = 0; j < NOMBRES_COLONNES; ++j)
        {
            if (j <= 1)
            {
                cout << grille[i][j];
                cout << "|";
            }
            if (j == 2)
            {
                cout << grille[i][j];
                cout << "]";
            }
        }

        cout << endl;
    }
}

void saisiePlacementSymbole(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int &ligne, unsigned short int &colonne, string &symbole, string &joueurCourrant, string &choix, unsigned short int &numTour)
{
    // Variable locale
    bool etat;
    char ligneL;
    char colonneC;
    do
    {
        cout << "--> " << joueurCourrant << ", entrez :" << endl
             << endl;
        do
        {
            cout << "\t Une coordonnee (LigneColonne, ex : 12 pour Ligne 1, Colonne 2), A(bandonner), R(egles)" << endl
                 << endl
                 << endl;

            cout << "\tVotre choix ?";
            cin >> choix;

            // Conversion string en char
            ligneL = choix[0];
            colonneC = choix[1];

            // Conversion char en int
            ligne = int(ligneL - 48);
            colonne = int(colonneC - 48);
        } while (ligne < 1 || ligne > 3 || colonne < 1 || colonne > 3);

        etat = verifPlacement(grille, ligne, colonne, numTour);

        // Vérification de l'emplacement saisis

        if (etat == true)
        {
            cout << "L'emplacement est deja utilise !" << endl
                 << endl;
        }
        else
        {
            placerSymbole(grille, ligne, colonne, symbole);
        }

        //  Condition d'arret de la boucle
    } while (etat == true);
}

void placerSymbole(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int &ligne, unsigned short int &colonne, string &symbole)
{
    bool placement;
    unsigned short int nTours;

    placement = verifPlacement(grille, ligne, colonne, nTours);
    if (placement == true)
    {
        cout << "L'emplacement est deja utilise !";
    }
    else
    {
        grille[ligne - 1][colonne - 1] = symbole;
    }
}

//////////////////////////////////////////
/////////////// FONCTIONS ////////////////
//////////////////////////////////////////

bool verifPlacement(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int ligne, unsigned short int colonne, unsigned short int &numTour)
{
    // Ajuster les indices pour correspondre à l'index du tableau qui commence à zéro
    ligne--;
    colonne--;

    if (grille[ligne][colonne] != " ")
    {
        return true;
    }
    else
    {
        numTour++;
        return false;
    }
}






bool verifVictoire(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int ligne, unsigned short int colonne)
{
    return verifVictoireDiagonale(grille, ligne, colonne) || verifVictoireHorizontale(grille, ligne, colonne) || verifVictoireVerticale(grille, ligne, colonne);
}





bool verifVictoireDiagonale(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int ligne, unsigned short int colonne)
{
    // Vérification diagonale
    if ((grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2] && grille[0][0] != " ") || (grille[0][2] == grille[1][1] && grille[1][1] == grille[2][0] && grille[0][2] != " "))
    {
        return true;
    }
    return false;
}

bool verifVictoireHorizontale(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int ligne, unsigned short int colonne)
{
    // Vérification horizontale
    if (grille[ligne][0] == grille[ligne][1] && grille[ligne][1] == grille[ligne][2] && grille[ligne][0] != " ")
    {
        return true;
    }
    return false;
}

bool verifVictoireVerticale(string grille[NOMBRES_LIGNES][NOMBRES_COLONNES], unsigned short int ligne, unsigned short int colonne)
{
    // Vérification verticale
    if (grille[0][colonne] == grille[1][colonne] && grille[1][colonne] == grille[2][colonne] && grille[0][colonne] != " ")
    {
        return true;
    }
    return false;
}
