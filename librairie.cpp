/*
-----------------------------------------------------------------------------------
Nom du fichier : librairie.cpp
Auteur(s)      : Théo Mirabile, Davide Caracol Mendes
Date creation  : 01.12.2020
Description    : Cette librairie contient des fonctions qui opèrent sur des vecteurs
                 et matrices
Remarque(s)    : - Dans les fonctions operator <<, des types auto n'ont pas été
                   utilisé par respect pour la donnée.
                 - Des boucles for et des sous-fonctions ont été utilisées avec des
                   itérateurs, car les fonctions lambda n'ont pas été vues en cours.
                 - Les fonctions ne gèrent pas les matrices vides, à l'exception de
                   estCarree et estReguliere.
Compilateur    : Apple clang version 12.0.0, MinGW-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iostream>
#include "librairie.h"

using namespace std;

/**
 * Compare la somme des éléments de deux vecteurs
 * @param v1 Le vecteur 1
 * @param v2 Le vecteur 2
 * @return true si la somme de `v1` est inférieure à celle de `v2`, false dans le cas contraire.
 */
bool comparerSommes(const Vecteur& v1, const Vecteur& v2);

/**
 * Compare le nombre d'éléments de deux vecteurs
 * @param v1 Le vecteur 1
 * @param v2 Le vecteur 2
 * @return true si le nombre d'éléments de `v1` est inférieur à celui de `v2`, false dans le cas contraire.
 */
bool comparerTailles(const Vecteur& v1, const Vecteur& v2);

/**
 * Compare les valeurs maximales de deux vecteurs
 * @param v1 Le vecteur 1
 * @param v2 Le vecteur 2
 * @return true si la valeur maximale de `v1` est supérieure à celle de `v2`, false sinon.
 */
bool comparerValeursMax(const Vecteur& v1, const Vecteur& v2);

ostream& operator << (ostream& os, const Vecteur& v)
{
    os << '(';

    // Pour chaque élément du vecteur (via des itérateurs)
    for(Vecteur::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        // Pour le premier élément, on ne le précède pas d'une virgule
        if(i != v.begin())
            os << ", ";
        // On concatène le pointeur correspondant à l'élément
        os << *i;
    }
    os << ")";

    // Retourne le flux
    return os;
}

ostream& operator << (ostream& os, const Matrice& m)
{
    os << '[';

    // Pour chaque ligne de la matrice (via des itérateurs)
    for(Matrice::const_iterator i = m.begin(); i != m.end(); ++i)
    {
        // Pour le premier élément, on ne le précède pas d'une virgule
        if(i != m.begin())
            os << ", ";
        // On concatène le pointeur correspondant à l'élément
        os << *i;
    }
    os << "]";

    // Retourne le flux
    return os;
}

bool estCarree(const Matrice& m)
{
    // La matrice est carrée si elle est vide, ou alors si son nombre de lignes
    // égale le nombre d'éléments de sa première ligne et qu'elle est régulière.
    return m.empty() || (estReguliere(m) && m.size() == m[0].size());
}

bool estReguliere(const Matrice& m)
{
    // Si la matrice n'est pas vide
    if(not(m.empty()))
    {
        // On récupère le nombre d'éléments de la première ligne
        size_t ligne = m[0].size();

        // Pour chaque ligne de la matrice
        for(const auto& i : m)
        {
            // On compare le nombre d'éléments à celui de la première ligne
            // dans le cas ou une ligne diffère, on en déduit que la matrice
            // n'est pas régulière.
            if (i.size() != ligne)
                return false;
        }
    }
    return true;
}

size_t maxCol(const Matrice& m)
{
    // Retourne la taille du vecteur ayant le plus d'éléments
    return max_element(m.begin(), m.end(), comparerTailles)->size();
}

Vecteur sommeLigne(const Matrice& m)
{
    // Vecteur utilisé comme retour de la fonction
    Vecteur sommeLigne;

    // Ajoute les sommes de chaques lignes dans le vecteur
    for(const auto & i : m)
    {
        sommeLigne.push_back(accumulate(i.begin(), i.end(), 0));
    }

    // Retourne le vecteur
    return sommeLigne;
}

Vecteur vectSommeMin(const Matrice& m)
{
    // Renvoie le vecteur dont la somme des éléments est la plus petite
    return *min_element(m.begin(), m.end(), comparerSommes);
}

void shuffleMatrice(Matrice& m)
{
    // Génère une seed aléatoire basée sur l'heure courante
    unsigned seed = (unsigned)chrono::system_clock::now().time_since_epoch().count();

    // Mélange les vecteurs de la matrice selon la seed générée
    shuffle (m.begin(), m.end(), default_random_engine(seed));
}

void sortMatrice(Matrice& m)
{
    // Trie les vecteurs de la matrice selon leur valeur max
    sort(m.begin(), m.end(), comparerValeursMax);
}

bool sommeDiagDG(const Matrice& m, int& somme) {

    // La matrice doit être carrée
    if (estCarree(m)) {

        // Détermine le nombre de lignes de la matrice
        size_t taille = m.size();

        // Pour chaque ligne de la matrice
        for (size_t i = 0; i < taille; ++i)
        {
            // On prend les éléments de gauche à droite
            // En décrémentant de 1 à chaque ligne
            somme += m[i][taille - i - 1];
        }
        return true;
    }
    return false;
}

bool sommeDiagGD(const Matrice& m, int& somme) {

    // La matrice doit être carrée
    if (estCarree(m)) {

        // Détermine le nombre de lignes de la matrice
        size_t taille = m.size();

        // Pour chaque ligne de la matrice
        for (size_t i = 0; i < taille; ++i)
        {
            // On prend les éléments de droite à gauche
            // En incrémentant de 1 à chaque ligne
            somme += m[i][i];
        }
        return true;
    }
    return false;
}

bool comparerSommes(const Vecteur& v1, const Vecteur& v2)
{
    // Compare le nombre d'éléments de deux vecteurs
    return accumulate(v1.begin(), v1.end(), 0) < accumulate(v2.begin(), v2.end(), 0);
}

bool comparerTailles(const Vecteur& v1, const Vecteur& v2)
{
    return v1.size() < v2.size();
}

bool comparerValeursMax(const Vecteur& v1, const Vecteur& v2)
{
    return *max_element(v1.begin(), v1.end()) > *max_element(v2.begin(), v2.end());
}
