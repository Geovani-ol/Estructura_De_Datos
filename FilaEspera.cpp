#include "FilaEspera.h"
#include <iostream>

using namespace std;

FilaEspera::FilaEspera() : frente(nullptr), final(nullptr) {}

FilaEspera::~FilaEspera() {
    while (!empty()) {
        dequeue();
    }

    cout << "Memoria liberada" << endl;
}


bool FilaEspera::empty() {
    return (frente == nullptr && final == nullptr);
}

void FilaEspera::enqueue(string persona) {
    Nodo * aux = new Nodo();
    aux -> dato = persona;
    aux -> sig = nullptr;

    if (empty()) {
        frente = aux;
    } else {
        final -> sig = aux;
    }

    final = aux;
    cout << "Se ha agregado a un cliente" << endl;
}

void FilaEspera::dequeue() {
    cout << "** Atender cliente **" << endl;

    if (empty()) {
        cout << "Lo siento, no hay clientes a quien atender" << endl;
        return;
    }

    Nodo * aux = frente;
    frente = frente -> sig;

    if (frente == nullptr) {
        final = nullptr;
    }

    cout << "Se ha atendido al cliente: " << aux -> dato << endl;
    delete aux;
}

void FilaEspera::show() {
    cout << "** Clientes **" << endl;

    if (empty()) {
        cout << "Lo siento, no hay clientes" << endl;
        return;
    }

    Nodo * aux = frente;
    int contador = 1;

    while (aux != nullptr) {
        cout << contador << ".- " << aux -> dato << endl;
        aux = aux -> sig;
        ++contador;
    }

    cout << endl << "Son: " << contador - 1 << " cliente/s" << endl;
}

void FilaEspera::showOne() {
    cout << "** Primer cliente **" << endl;

    if (empty()) {
        cout << "Lo siento, no hay clientes" << endl;
        return;
    }

    cout << "El primer cliente es: 1.- " << frente -> dato << endl;
}
