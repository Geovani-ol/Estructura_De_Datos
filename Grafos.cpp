#include "Grafos.h"
#include <iostream>

using namespace std;

Grafos::Grafos() : principio(nullptr) {}

Vertice * Grafos::obtenerVertice(string nombre) {
    Vertice * temp = principio;

    while (temp != nullptr) {
        if (temp -> nombre == nombre) {
            return temp;
        }

        temp = temp -> sig;
    }

    return nullptr;
}

void Grafos::insertarVertice(string nombre) {
    if (obtenerVertice(nombre) != nullptr) {
        cout << "Ya existe ese vertice!" << endl;
        return;
    }

    Vertice * nuevo = new Vertice(nombre);

    if (principio == nullptr) {
        principio = nuevo;
    } else {
        Vertice * temp = principio;

        while (temp -> sig != nullptr) {
            temp = temp -> sig;
        }

        temp -> sig = nuevo;

    }
}
