#include "arboles.h"
#include <iostream>

using namespace std;

Arboles::Arboles() : raiz(nullptr) {};

void Arboles::insertar(int dato, Nodo *&nodo) {
    if (nodo == nullptr) {
        nodo = new Nodo(dato);
        cout << "Se inserto un nuevo dato: " << dato << endl;
    } else if (dato < nodo -> valor) {
        insertar(dato, nodo -> izq);
    } else {
        insertar(dato, nodo -> der);
    }
}

void Arboles::destruir(Nodo *&nodo) {
    if (nodo == nullptr) {
        return;
    }

    destruir(nodo -> izq);
    destruir(nodo -> der);
    delete nodo;
    nodo = nullptr;
}

void Arboles::ejecutar() {
    insertar(10, raiz);
    insertar(8, raiz);
    insertar(9, raiz);
    insertar(12, raiz);
    insertar(11, raiz);
    insertar(13, raiz);

    destruir(raiz);
}
