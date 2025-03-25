#include "Bicolas.h"
#include <iostream>

using namespace std;

Bicolas::Bicolas() {
    frente = nullptr;
    final = nullptr;
}

bool Bicolas::empty() {
    return (frente == nullptr && final == nullptr);
}

void Bicolas::enqueueFinal(int val) {
    Nodo * aux = new Nodo();
    aux -> valor = val;
    aux -> sig = nullptr;
    aux -> ant = nullptr;

    if (empty()) {
        frente = aux;
        final = aux;
    } else {
        final -> sig = aux;
        aux -> ant = final;
        final = aux;
    }

    cout << "Se ingreso el valor:" << val << endl;
}

void Bicolas::dequeueFinal() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        Nodo * aux = final;
        final = final -> ant;

        if (final != nullptr) {
            final -> sig = nullptr;
        } else {
            frente = nullptr;
        }

        delete aux;
    }
}

void Bicolas::enqueueFrente(int val) {
    Nodo * aux = new Nodo();
    aux -> valor = val;
    aux -> sig = frente;
    aux -> ant = nullptr;

    if (empty()) {
        frente = aux;
        final = aux;
    } else {
        frente -> ant = aux;
        frente = aux;
    }

    cout << "Se ingreso el valor:" << val << endl;
}

void Bicolas::dequeueFrente() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        Nodo * aux = frente;
        frente = frente -> sig;

        if (frente != nullptr) {
            frente -> ant = nullptr;
        } else {
            final = nullptr;
        }

        delete aux;
    }
}

void Bicolas::ejecutar() {

}

