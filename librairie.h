using namespace std;

#ifndef LIBRAIRIE_H
#define LIBRAIRIE_H

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

ostream& operator << (ostream& os, const Vecteur& v);
ostream& operator << (ostream& os, const Matrice& m);

bool estReguliere(Matrice& m);

#endif
