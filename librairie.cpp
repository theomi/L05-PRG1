/*
-----------------------------------------------------------------------------------
Nom du fichier : librairie.cpp
Auteur(s) : Théo Mirabile, Davide Caracol Mendes
Date creation : 01.12.2020
Description : -
Remarque(s) : -
Compilateur : Apple clang version 12.0.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include "librairie.h"

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

ostream& operator << (ostream& os, const Vecteur& v)
{
    os << '(';
    for(Vecteur::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        if(i != v.begin())
            os << ", ";
        os << *i;
    }
    os << ")";

    return os;
}

ostream& operator << (ostream& os, const Matrice& m)
{
    os << '[';
    for(Matrice::const_iterator i = m.begin(); i != m.end(); ++i)
    {
        if(i != m.begin())
            os << ", ";
        os << *i;
    }
    os << "]";

    return os;
}

bool estCarree(const Matrice& m)
{
    return estReguliere(m) && m.size() == m[0].size();
}

bool estReguliere(const Matrice& m)
{
    size_t ligne = m[0].size();

    for(const auto& i : m)
    {
        if (i.size() != ligne)
            return false;
    }

    return true;
}

bool comparerTailles(const Vecteur& v1, const Vecteur& v2)
{
    return v1.size() < v2.size();
}

size_t maxCol(const Matrice& m)
{
    return max_element(m.begin(), m.end(), comparerTailles)->size();
}

bool comparerSommes(const Vecteur& v1, const Vecteur& v2)
{
    return accumulate(v1.begin(), v1.end(), 0) < accumulate(v2.begin(), v2.end(), 0);
}

Vecteur sommeLigne(const Matrice& m)
{
    Vecteur sommeLigne;
    for(const auto & i : m)
    {
        sommeLigne.push_back(accumulate(i.begin(), i.end(), 0));
    }

    return sommeLigne;
}

Vecteur vectSommeMin(const Matrice& m)
{
    return *min_element(m.begin(), m.end(), comparerSommes);
}

bool comparerValeurs(const Vecteur& v1, const Vecteur& v2)
{
    return *max_element(v1.begin(), v1.end()) > *max_element(v2.begin(), v2.end());
}

void sortMatrice(Matrice& m)
{
    sort(m.begin(), m.end(), comparerValeurs);
}

void shuffleMatrice(Matrice& m)
{
    unsigned seed = (unsigned)chrono::system_clock::now().time_since_epoch().count();
    shuffle (m.begin(), m.end(), default_random_engine(seed));
}

bool sommeDiagDG(const Matrice& m, int& somme) {
    if (estCarree(m)) {
        const unsigned long taille = m.size();
        for (unsigned long i = 0; i < taille; ++i)
        {
            somme += m[i][taille - i - 1];
        }
        return true;
    }
    return false;
}

bool sommeDiagGD(const Matrice& m, int& somme) {
    if (estCarree(m)) {
        for (unsigned long i = 0; i < m.size(); ++i)
        {
            somme += m[i][i];
        }
        return true;
    }
    return false;
}
