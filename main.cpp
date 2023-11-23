/************************************************************
                     ENTETE DU PROGRAMME
************************************************************/

/*
 Programme : Morpion
 But : Jeux du morpion classique sur une grille 3x3 en joueur contre joueur
 Date de dernière modification : 16/11/2023
 Auteur : E.CLEMENCEAU
 Remarques : Code conforme aux spécification internes données en cours
*/

/************************************************************
                         INCLUSION
************************************************************/
#include <iostream>
#include <cctype>
#include "sp_sae_morpion.h"
#include "game-tools.h"
using namespace std;

/************************************************************
                     PROGRAMME PRINCIPAL
************************************************************/
int main(void)
{

    // Variables
    string nomJoueur1;                        // Nom du joueur 1
    string nomJoueur2;                        // Nom du joueur 2
    string nomJoueurCourrant;                 // Nom du joueur courrant
    const unsigned short int NB_LIGNES = 3;   // Nombre de colonnes de la grille de morpîon
    const unsigned short int NB_COLONNES = 3; // Nombre de colonnes de la grille de morpion
    string symboleJ1;                           // Symbole utilisé par le joueur 1 pour la partie
    string symboleJ2;                           // Symbole utilisé par le joueur 2 pour la partie
    string symboleJoueurCourrant;               // Symbole du joueur courrant
    unsigned short int nbTours = 1;               // Nombre de tours de la partie
    char debPartie;                           // Symbole permétant de débuter la partie
    string placementSymbole;
    unsigned short int numLigne;
    unsigned short int numColonne;


    // Affichage des regles

    afficherRegles();

    // Phase de personalisation

    cout << "--- Phase de personalisation ---" << endl
         << endl;

    // Saisie du nom et caractère des joueurs

    // Saisie info joueur 1

    cout << "JOUEUR 1 entrez votre prenom : ";
    cin >> nomJoueur1;
    cout << nomJoueur1 << ", entrez votre symbole (1 lettre ou 1 chiffre) : ";
    cin >> symboleJ1;
    cout << endl;

    // Saisie info joueur 2 avec vérification que le prénom et le symbole du joueur soit différent de celui du joueur 1

    cout << "JOUEUR 2 entrez votre prenom : ";
    cin >> nomJoueur2;

    // Différenciation des symboles des deux joueurs

    cout << nomJoueur2 << ", entrez votre symbole (1 lettre ou 1 chiffre different de " << symboleJ2 << ") : ";
    cin >> symboleJ2;

    // Presser J pour jouer
    cout << "Saisir 'J' pour jouer : ";
    cin >> debPartie;
    while (debPartie != 'J')
    {
        cout << "Saisir 'J' pour jouer : ";
        cin >> debPartie;
    }
    effacer();

    // Initialisation de la grille en 3x3 les [|] s'affiche dans

    string grilleMorpion[NB_LIGNES][NB_COLONNES] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}};

    // Affichage temporaire du tableau(Procédure d'afficherGrille)

    
    while (true)
    {
        if (nbTours % 2 == 0)
        {
            nomJoueurCourrant = nomJoueur2;
            symboleJoueurCourrant = symboleJ2;
        }
        if (nbTours % 2 != 0)
        {
            nomJoueurCourrant = nomJoueur1;
            symboleJoueurCourrant = symboleJ1;
        }
        
        cout << "Tours numero " << nbTours << endl << endl;
        afficherGrille(grilleMorpion, NOMBRES_COLONNES, NOMBRES_LIGNES);
        cout << endl;
        saisiePlacementSymbole(grilleMorpion, numLigne, numColonne, symboleJoueurCourrant, nomJoueurCourrant, placementSymbole, nbTours);
        if (nbTours == 9)
        {
            break;
        }
        
    }

    return 0;
}
/**
 * @brief 
 * if nbTours >= 5 déclancher la vérif
 * 
 */
