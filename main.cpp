/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s) : Théo Mirabile
Date creation : <jj.mm.aaaa>
Description : <à compléter>
Remarque(s) : <à compléter>
Compilateur : Apple clang version 12.0.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include "librairie.h"

using namespace std;

int main() {

    vector<int> v = {3, 4, 5, 6, 7};
    vector<vector<int>> m = {{1, 2, 3, 4, 5},
                             {3, 4, 5, 6, 7},
                             {8, 9, 0, 1, 2}};

    cout << m;

    return EXIT_SUCCESS;
}