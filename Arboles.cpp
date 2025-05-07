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

void Arboles::inorden(Nodo *&nodo) {
    if (nodo == nullptr) {
        return;
    }

    inorden(nodo -> izq);
    cout << nodo -> valor << " " << endl;
    inorden(nodo -> der);
}

void Arboles::posorden(Nodo *&nodo) {
    if (nodo == nullptr) {
        return;
    }

    posorden(nodo -> izq);
    posorden(nodo -> der);
    cout << nodo -> valor << " " << endl;
}

void Arboles::preorden(Nodo *&nodo) {
    if (nodo == nullptr) {
        return;
    }

    cout << nodo -> valor << " " << endl;
    preorden(nodo -> izq);
    preorden(nodo -> der);
}

void Arboles::ejecutar() {
    insertar(10, raiz);
    insertar(8, raiz);
    insertar(9, raiz);
    insertar(12, raiz);
    insertar(11, raiz);
    insertar(13, raiz);

    cout << "Inorden: " << endl;
    inorden(raiz);

    cout << "Posorden: " << endl;
    posorden(raiz);

    cout << "Preorden: " << endl;
    preorden(raiz);

    destruir(raiz);
}
