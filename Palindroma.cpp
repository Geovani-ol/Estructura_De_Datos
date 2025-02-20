#include "Palindroma.h"
#include <iostream>

using namespace std;

bool Palindroma::palindroma(const string &cadena, int inicio, int fin) {
    if (inicio >= fin) return true;

    if (cadena[inicio] != cadena[fin]) return false;

    palindroma(cadena, ++inicio, --fin);
}

void Palindroma::mostrarPalindroma() {
    string palabra;

    cout << "Ingrese la palabra: ";
    cin >> palabra;

    if (palindroma(palabra, 0, palabra.length() - 1)) {
        cout << "Es palindromo" << endl;
    } else {
        cout << "No palindromo" << endl;
    }
}

