#include "Anagramas.h"
#include <iostream>
#include <string>

using namespace std;

bool Anagramas::anagrama(string cadena1, string cadena2, size_t indice) {
    if (cadena1.length() != cadena2.length()) return false;
    if (indice >= cadena1.length()) return true;

    char c = cadena1[indice];

    for (char ch: cadena2) {

        if (ch == c) {
            return anagrama(cadena1, cadena2, ++indice);
        }

    }

    return false;
}

void Anagramas::mostrarAnagrama() {
    string cadena1, cadena2;

    cout << "Ingrese la primera palabra: ";
    cin >> cadena1;
    cout << "Ingrese la segunda palabra: ";
    cin >> cadena2;

    if (anagrama(cadena1, cadena2)) {
        cout << "Si son palabras anagramas" << endl;
    } else {
        cout << "No son palabras anagramas" << endl;
    }
}


