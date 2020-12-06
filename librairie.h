/*
-----------------------------------------------------------------------------------
Nom du fichier : librairie.h
Auteur(s) : Théo Mirabile, Davide Caracol Mendes
Date creation : 01.12.2020
Description : -
Remarque(s) : -
Compilateur : Apple clang version 12.0.0, MinGW-W64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LIBRAIRIE_H
#define LIBRAIRIE_H

#include <vector>

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;

/**
 * Affiche un vecteur au format (v1, v2, ..., vn)
 * @param os Le flux non transformé
 * @param m Le vecteur à afficher
 * @return Le flux transformé
 */
std::ostream& operator << (std::ostream& os, const Vecteur& v);

/**
 * Affiche une matrice au format [(..),(..),(..)]
 * @param os Le flux non transformé
 * @param m La matrice à afficher
 * @return Le flux transformé
 */
std::ostream& operator << (std::ostream& os, const Matrice& m);

/**
 * Retourne un booléen indiquant si la matrice est carrée
 * (la longueur des lignes est régulière et égale le nombre de colonnes)
 * @param m La matrice à évaluer
 * @return true si la matrice est carrée, false dans le cas contraire
 */
bool estCarree(const Matrice& m);

/**
 * Retourne un booléen indiquant si la matrice est régulière
 * (toutes les lignes sont de même taille)
 * @param m La matrice à évaluer
 * @return true si la matrice est régulière, false dans le cas contraire
 */
bool estReguliere(const Matrice& m);

/**
 * Retourne un vecteur contenant la somme des valeurs de
 * chacune des lignes d'une matrice.
 * @param m La matrice à évaluer
 * @return Un vecteur contenant la somme des valeurs de chaque ligne
 */
Vecteur sommeLigne(const Matrice& m);

/**
 * Retourne la longueur du plus grand vecteur de la matrice
 * @param m La matrice à évaluer
 * @return La longueur trouvée
 */
size_t maxCol(const Matrice& m);

/**
 * Retour le vecteur d’une matrice dont la somme des valeurs
 * est la plus faible. Si plusieurs vecteurs présentent la même
 * somme, la fonction retourne celui d’indice le plus faible.
 * @param m La matrice à évaluer
 * @return Le vecteur trouvé
 */
Vecteur vectSommeMin(const Matrice& m);

/**
 * Mélange les vecteurs d’une matrice sans altérer les vecteurs.
 * La seed du générateur est basée sur l’heure.
 * @param m La matrice à mélanger, renvoyée par référence
 */
void shuffleMatrice(Matrice& m);

/**
 * Trie dans l’ordre décroissant une matrice en fonction de
 * l’élément max d’un vecteur.
 * @param m La matrice à trier, renvoyée par référence
 */
void sortMatrice(Matrice& m);

/**
 * Renvoie la somme des valeurs de la diagonale de droite à gauche
 * @param m La matrice d'entrée (doit être carrée)
 * @param somme La somme des valeurs renvoyée par référence
 * @return true si l'opération a réussi, false dans le cas inverse.
 */
bool sommeDiagDG(const Matrice& m, int& somme);

/**
 * Renvoie la somme des valeurs de la diagonale de gauche à droite
 * @param m La matrice d'entrée (doit être carrée)
 * @param somme La somme des valeurs renvoyée par référence
 * @return true si l'opération a réussi, false dans le cas inverse.
 */
bool sommeDiagGD(const Matrice& m, int& somme);

#endif
