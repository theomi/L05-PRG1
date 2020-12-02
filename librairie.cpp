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
#include "librairie.h"

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

ostream& operator << (ostream& os, const Vecteur& v) {
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

ostream& operator << (ostream& os, const Matrice& m) {
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

bool estReguliere(Matrice& m)
{



}