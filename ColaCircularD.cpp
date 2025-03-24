#include "ColaCircularD.h"
#include <iostream>

using namespace std;

ColaCircularD::ColaCircularD() {
    frente = nullptr;
    final = nullptr;
}

bool ColaCircularD::empty() {
    return (frente == nullptr && final == nullptr);
}

void ColaCircularD::enqueue(int val) {
    Nodo * aux = new Nodo();
    aux->valor = val;
    aux->sig = nullptr;

    if (empty()) {
        frente = aux;
        final = aux;
        final->sig = frente;
    } else {
        final->sig = aux;
        final = aux;
        final->sig = frente;
    }

    cout << "Se inserto un valor: " << val << endl;
}

void ColaCircularD::dequeue() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        Nodo * aux = frente;

        if (frente == final) {
            frente = final = nullptr;
        } else {
            frente = frente->sig;
            final->sig = frente;
        }

        delete aux;
    }
}

void ColaCircularD::show() { // Aun falta para hacerla cola circular con memoria dinamica
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        Nodo * aux = frente;
        while (aux != nullptr) {
            cout << aux->valor << " ";
            aux = aux->sig;
        }
    }
}

void ColaCircularD::destroy() {
    while (!empty()) {
        dequeue();
    }
}


void ColaCircularD::ejecutar() {
    destroy();
}

