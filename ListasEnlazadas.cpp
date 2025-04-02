#include "ListasEnlazadas.h"
#include <iostream>

using namespace std;

ListasEnlazadas::ListasEnlazadas() : cabeza(nullptr), cola(nullptr) {
    cout << "Inicializacion de lista" << endl;
}

ListasEnlazadas::~ListasEnlazadas() {
    Nodo * aux = cabeza;
    Nodo * siguiente;

    while (aux != nullptr) {
        siguiente = aux -> sig;
        delete aux;
        aux = siguiente;
    }

    cout << "Se destruyo la lista" << endl;
}


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

    cout << "Se inserto un nuevo dato: " << dato << endl;

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

        if (cabeza != nullptr) {
            cabeza -> ant = nuevo;
        }

        cabeza = nuevo;

        if (cabeza -> sig == nullptr) {
            cola = cabeza;
        }

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

    if (nuevo -> sig != nullptr) {
        nuevo -> sig -> ant = nuevo;
    } else {
        cola = nuevo;
    }

    cout << "Se insert un nuevo dato: " << dato << endl;
}

void ListasEnlazadas::eliminarPosicion(int posicion) {
    if (empty()) {
        cout << "Lista esta vacia." << endl;
        return;
    }

    Nodo * aux = cabeza;

    if (posicion == 1) {
        cabeza = cabeza -> sig;

        if (cabeza != nullptr) {
            cabeza -> ant = nullptr;
        } else {
            cola = nullptr;
        }

        delete aux;
        cout << "Se eliminar un dato: " << endl;
        return;
    }

    int contador = 1;

    while (aux != nullptr && contador < posicion) {
        aux = aux -> sig;
        ++contador;
    }

    if (aux == nullptr) {
        cout << "Posicion fuera de rango" << endl;
        return;
    }

    if (aux -> sig != nullptr) {
        aux -> sig -> ant = aux -> ant;
    }

    if (aux -> ant != nullptr) {
        aux -> ant -> sig = aux -> sig;
    }

    if (aux -> sig == cola) {
        cola = cola -> ant;
    }

    delete aux;
    cout << "Se eliminar un dato: " << endl;
}

void ListasEnlazadas::mostrar() {
    if (empty()) {
        cout << "Lista esta vacia." << endl;
    } else {
        Nodo * aux = cabeza;

        while (aux != nullptr) {
            cout << aux -> valor << " ";
            aux = aux -> sig;
        }

        cout << endl;
    }
}


void ListasEnlazadas::ejecutar() {
    insertarFinal(10);
    insertarFinal(20);
    insertarPosicion(15,  2);
    mostrar();
    eliminarPosicion(3);
    mostrar();
}



