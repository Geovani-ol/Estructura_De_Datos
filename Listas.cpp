#include "Listas.h"
#include <iostream>

using namespace std;

Listas::Listas() : cabeza(nullptr) {}

bool Listas::empty() {
    return cabeza == nullptr;
}

void Listas::insertarFinal(int val) {
    Nodo * nuevo = new Nodo(val);

    if (empty()) {
        cabeza = nuevo;
    } else {
        Nodo * aux = cabeza;

        while (aux -> sig != nullptr) {
            aux = aux -> sig;
        }

        aux -> sig = nuevo;
    }

    cout << "Se inserto un dato: " << val << endl;
}

void Listas::insertarPosicion(int val, int posicion) {
    Nodo * nuevo = new Nodo(val);

    if (posicion == 0) {
        nuevo -> sig = cabeza;
        cabeza = nuevo;
        return;
    }

    Nodo * aux = cabeza;
    int contador = 0;

    while (aux != nullptr && contador < posicion) {
        aux = aux -> sig;
        ++contador;
    }

    if (aux == nullptr) {
        cout << "La posición esta fuera de rango" << endl;
        return;
    }


}




