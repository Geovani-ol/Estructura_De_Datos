#include "Anagramas.h"
#include <iostream>
#include <cstring>

using namespace std;

bool Anagramas::anagrama(const char palabra1[], const char palabra2[]) {
    int len1 = strlen(palabra1);
    int len2 = strlen(palabra2);

    if (len1 != len2) {
        return false;
    }

    char arr1[len1 + 1];
    char arr2[len2 + 1];

    strcpy(arr1, palabra1);
    strcpy(arr2, palabra2);

    ordenar_arreglo(arr1, len1, 0);
    ordenar_arreglo(arr2, len2, 0);

    for (int i = 0; i < len1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

void Anagramas::ordenar_arreglo(char arr[], int n, int index) {
    if (index == n - 1) {
        return;
    }

    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[index]) {
            swap(arr[i], arr[index]);
        }
    }

    ordenar_arreglo(arr, n, index + 1);
}


void Anagramas::mostrarAnagrama() {
    string cadena1, cadena2;

    cout << "Ingrese la primera palabra: ";
    cin >> cadena1;
    const char* palabra1 = cadena1.c_str();

    cout << "Ingrese la segunda palabra: ";
    cin >> cadena2;
    const char* palabra2 = cadena2.c_str();

    if (anagrama(palabra1, palabra2)) {
        cout << "Si son palabras anagramas" << endl;
    } else {
        cout << "No son palabras anagramas" << endl;
    }
}


