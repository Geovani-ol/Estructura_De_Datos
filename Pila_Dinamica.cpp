#include "Pila_Dinamica.h"
#include <iostream>

using namespace std;

Pila_Dinamica::Pila_Dinamica() {
    pila = nullptr;
}

bool Pila_Dinamica::vacia() {
    if (pila == nullptr) {
        return false;
    } else {
        return true;
    }
}

void Pila_Dinamica::ejecutar() {
}
