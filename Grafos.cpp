#include "Grafos.h"
#include <iostream>

using namespace std;

Grafos::Grafos() : principio(nullptr) {}

Grafos::~Grafos() {
    Vertice * v = principio;

    while (v != nullptr) {
        Arista * a = v -> ari;

        while (a != nullptr) {
            Arista * tempA = a;
            a = a -> sig;
            delete tempA;
        }

        Vertice * tempV = v;
        v = v -> sig;
        delete tempV;
    }

    cout << "Se libero la memoria" << endl;
}


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

    cout << "Se inserto un vertice " << nombre << endl;
}

void Grafos::insertarArista(string origen, string destino) {
    Vertice * vorigen = obtenerVertice(origen);
    Vertice * vdestino = obtenerVertice(destino);

    if (vorigen == nullptr || vdestino == nullptr) {
        cout << "Uno o ambos vertices no existen" << endl;
        return;
    }

    Arista * nuevaOrigen = new Arista(vdestino);
    nuevaOrigen -> sig = vorigen -> ari;
    vorigen -> ari = nuevaOrigen;

    Arista * nuevaDestino = new Arista(vorigen);
    nuevaDestino -> sig = vdestino -> ari;
    vdestino -> ari = nuevaDestino;

    cout << "Se inserto la arista de " << origen << " y " << destino << endl;
}

void Grafos::listaAdyacencia() {
    Vertice * v = principio;

    while (v != nullptr) {
        cout << v -> nombre << " -> ";
        Arista * a = v -> ari;

        while (a != nullptr) {
            cout << a -> dest -> nombre << " ";
            a = a -> sig;
        }

        cout << endl;
        v = v -> sig;
    }

    cout << endl;
}

void Grafos::ejecutar() {
    insertarVertice("A");
    insertarVertice("B");
    insertarVertice("C");
    insertarArista("A", "B");
    insertarArista("A", "C");
    listaAdyacencia();
}
