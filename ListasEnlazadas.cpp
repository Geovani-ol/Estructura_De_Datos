#include "ListasEnlazadas.h"
#include <iostream>

using namespace std;

ListasEnlazadas::ListasEnlazadas() : cabeza(nullptr), cola(nullptr) {}


bool ListasEnlazadas::empty() {
    return cabeza == nullptr;
}

void ListasEnlazadas::insertarFinal(int dato) {
    Nodo * nuevo = new Nodo(dato);

    if (empty()) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola -> sig = nuevo;
        nuevo -> ant = cola;
        cola = nuevo;
    }

    cout << "Se inserto un dato: " << dato << endl;

}

int ListasEnlazadas::numeroNodos() {
    if (empty()) {
        return 0;
    } else {
        Nodo * aux = cabeza;
        int contador = 1;

        while (aux -> sig != nullptr) {
            aux = aux -> sig;
            ++contador;
        }

        return contador;
    }
}

void ListasEnlazadas::insertarPosicion(int dato, int posicion) {
    int tamano = numeroNodos();

    if (tamano < posicion) {
        cout << "Posicion esta fuera de rango, insertando al final...." << endl;
        insertarFinal(dato);
        return;
    }

    Nodo * nuevo = new Nodo(dato);

    if (posicion == 1) {
        nuevo -> sig = cabeza;
        cabeza -> ant = nuevo;
        cabeza = nuevo;

        cout << "Se insert un dato: " << dato << endl;
        return;
    }

    Nodo * aux = cabeza;
    int contador = 1;

    while (aux != nullptr && contador < posicion - 1) {
        aux = aux -> sig;
        ++contador;
    }

    nuevo -> sig = aux -> sig;
    nuevo -> ant = aux;
    aux -> sig = nuevo;

    if (aux -> sig != nullptr) {
        nuevo -> sig -> ant = nuevo;
    }
}


void ListasEnlazadas::ejecutar() {

}



