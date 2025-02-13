#include <iostream>
#include "Par_Impar.h"

using namespace std;

bool Par_Impar::esPar(int num) {
    if (num == 0) return true;
    return esImpar(num - 1);
}

bool Par_Impar::esImpar(int num) {
    if (num == 0) return false;
    return esPar(num - 1);
}

void Par_Impar::verificarNumero(int num) {
    if (esImpar(num)) {
        cout << num << " es impar" << endl;
    } else {
        cout << num << " es par" << endl;
    }
}