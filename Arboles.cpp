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
    cout << nodo -> valor << " ";
    inorden(nodo -> der);
}

void Arboles::posorden(Nodo *&nodo) {
    if (nodo == nullptr) {
        return;
    }

    posorden(nodo -> izq);
    posorden(nodo -> der);
    cout << nodo -> valor << " ";
}

void Arboles::preorden(Nodo *&nodo) {
    if (nodo == nullptr) {

        return;
    }

    cout << nodo -> valor << " ";
    preorden(nodo -> izq);
    preorden(nodo -> der);
}

Nodo *Arboles::sucesor(Nodo* nodo) {
    while (nodo -> izq != nullptr) {
        nodo = nodo -> izq;
    }

    return nodo;
}

Nodo *Arboles::eliminar(Nodo* nodo, int valor){
    if (nodo == nullptr) {
        cout << "No se encontro el nodo" << endl;
        return nullptr;
    } else if (valor < nodo -> valor) {
        nodo -> izq = eliminar(nodo -> izq, valor);
    } else if (valor > nodo -> valor) {
        nodo -> der = eliminar(nodo -> der, valor);
    } else {
        // Caso 1 -> no tiene ningun hijo
        if (nodo -> izq == nullptr && nodo -> der == nullptr) {
            delete nodo;
            return nullptr;
        } else if (nodo -> der == nullptr) {  // Caso 2 -> tiene una hoja
            Nodo * temp = nodo -> izq;
            delete nodo;
            return temp;
        } else if (nodo -> izq == nullptr) {
            Nodo * temp = nodo -> der;
            delete nodo;
            return temp;
        } else {
            Nodo * temp = sucesor(nodo -> der);
            nodo -> valor = temp -> valor;
            nodo -> der = eliminar(nodo -> der, temp -> valor);
            return nodo;
        }
    }
}

void Arboles::ejecutar() {
    insertar(10, raiz);
    insertar(8, raiz);
    insertar(9, raiz);
    insertar(12, raiz);
    insertar(11, raiz);
    insertar(13, raiz);
    cout << endl << "Inorden: " << endl;
    inorden(raiz);
    cout << endl << "Posorden: " << endl;
    posorden(raiz);
    cout << endl << "Preorden: " << endl;
    preorden(raiz);
    cout << endl;
    eliminar(raiz, 10);
    cout << endl << "Inorden: " << endl;
    inorden(raiz);
    destruir(raiz);
}
