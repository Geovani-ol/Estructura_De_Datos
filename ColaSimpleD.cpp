#include "ColaSimpleD.h"
#include <iostream>

using namespace std;

ColaSimpleD::ColaSimpleD() {
    frente = nullptr;
    final = nullptr;
}

bool ColaSimpleD::empty() {
    return (final == nullptr && frente == nullptr);
}

void ColaSimpleD::enqueue(int x) {
    Nodo * aux = new Nodo();
    aux->valor = x;
    aux->sig = nullptr;

    if (empty()) {
        frente = aux;
    } else {
        final->sig = aux;
    }

    final = aux;
    cout << "Se inserto un valor: " << x << endl;
}

void ColaSimpleD::dequeue() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        Nodo * aux = frente;
        frente = frente->sig;

        if (frente == nullptr) {
            final = nullptr;
        }

        delete aux;
    }
}

void ColaSimpleD::show() {
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

void ColaSimpleD::destroy() {
    while (!empty()) {
        dequeue();
    }
}


void ColaSimpleD::ejecutar() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    show();
    dequeue();
    dequeue();
    show();
    destroy();
}


