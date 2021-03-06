/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Théo Mirabile, Davide Caracol Mendes
Date creation  : 01.12.2020
Description    : Affiche les fonctions de la librairie annexe
Remarque(s)    : - Une seule matrice initiale est utilisée séquentiellement par toutes
                   les fonctions.
                 - Les fonctions ne gèrent pas les matrices vides, à l'exception de
                   estCarree et estReguliere.
Compilateur    : Apple clang version 12.0.0, MinGW-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "librairie.h"

using namespace std;

int main() {

    vector<int> v = {3, 4, 5, 6, 7};
    vector<vector<int>> m = {{1, 2, 6, 5, 7, 3},
                             {2, 4, 9, 3, 3, 1},
                             {2, 1, 1, 1, 1, 1},
                             {3, 4, 4, 5, 6, 7},
                             {1, 2, 1, 2, 1, 2},
                             {5, 4, 3, 2, 1, 0}};

   cout << "Bonjour, ce programme va vous présenter différentes fonctions" << endl << endl;

   //Affichage du vecteur v
   cout << "Voici le vecteur : "<< endl;
   cout << v;
   cout << endl;

   //Affichage du vecteur m
   cout << "Voici la matrice : " << endl;
   cout << m;
   cout << endl << endl;

   //Affichage de la fonction estCarree
   estCarree(m) ? cout << "La matrice est carrée" << endl : cout << "La matrice n'est pas carrée" << endl;

   //Affichage de la fonction estReguliere
   estReguliere(m) ? cout << "La matrice est régulière" << endl : cout << "La matrice n'est pas régulière" << endl;

   //Affichage de la fonction maxCol
   cout << "La longueur maximum des vecteurs de la matrice vaut " << maxCol(m) << endl;

   //Affichage de la fonction sommeLigne
   cout << "Vecteur contenant la sommes des valeurs de chaque ligne: " << sommeLigne(m) << endl;

   //Affichage de la fonction vectSommeMin
   cout << "Ligne de la matrice dont la somme est la plus faible : " << vectSommeMin(m) << endl;

   //Affichage de la fonction shuffleMatrice
   shuffleMatrice(m);
   cout << "Les vecteurs de la matrice ont été mélangés : " << m << endl;

   //Affichage de la fonction sortMatrice
   sortMatrice(m);
   cout << "La matrice a été trié dans l'ordre décroissant : " << m << endl;

   //Affichage de la fonction sommeDiagDG
   int somme_diag_dg = 0;
   bool somme_diag_dg_erreur = sommeDiagDG(m, somme_diag_dg);
   if (somme_diag_dg_erreur) {
      cout << "La valeur de la diagonale Droite -> Gauche vaut " << somme_diag_dg << endl;
   } else {
      cout << "Le processus de calcul de la diagonale Droite -> Gauche a rencontré une erreur" << endl;
   }

   //Affichage de la fonction sommeDiagGD
   int somme_diag_gd = 0;
   bool somme_diag_gd_erreur = sommeDiagGD(m, somme_diag_gd);
   if (somme_diag_gd_erreur) {
      cout << "La valeur de la diagonale Gauche -> Droite vaut " << somme_diag_gd << endl;
   } else {
      cout << "Le processus de calcul de la diagonale Gauche -> Droite a rencontré une erreur" << endl;
   }

   return EXIT_SUCCESS;
}