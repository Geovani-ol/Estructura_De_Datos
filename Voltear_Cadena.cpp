#include "Voltear_Cadena.h"
#include <iostream>

using namespace std;

void Voltear_Cadena::voltear(const string &cadena, size_t indice) {
    if (indice >= cadena.length()) return;

    voltear(cadena, indice + 1);

    cout << cadena[indice];
}

void Voltear_Cadena::mostrarVoltear() {
    string cadena;

    cout << "Cadena a voltear: ";
    cin >> cadena;

    voltear(cadena);
}

