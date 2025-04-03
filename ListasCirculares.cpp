#include "ListasCirculares.h"
#include <iostream>

using namespace std;

ListasCirculares::ListasCirculares() : cabeza(nullptr) {}

bool ListasCirculares::empty() {
    return cabeza == nullptr;
}

void ListasCirculares::insertarFinal(int dato) {
    Nodo * nuevo = new Nodo(dato);

    if (empty()) {
        cabeza = nuevo;
        cabeza -> sig = cabeza;
    } else {
        Nodo * aux = cabeza;

        while (aux -> sig != cabeza) {
            aux = aux -> sig;
        }

        aux -> sig = nuevo;
        nuevo -> sig = cabeza;
        cout << "Se inserto un dato: " << dato << endl;
    }
}

void ListasCirculares::eliminarFinal() {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    if (cabeza -> sig == cabeza) {
        delete cabeza;
        cabeza = nullptr;
        cout << "Se elimino la cabeza" << endl;
        return;
    }

    Nodo * aux = cabeza;

    while (aux -> sig -> sig != cabeza) {
        aux = aux -> sig;
    }

    Nodo * ultimo = aux -> sig;
    aux -> sig = cabeza;
    delete ultimo;
    cout << "Se elimino un dato" << endl;
}

int ListasCirculares::size() {
    if (empty()) {
        return 0;
    } else {
        Nodo * aux = cabeza;
        int contador = 0;

        while (aux -> sig != cabeza) {
            ++contador;
            aux = aux -> sig;
        }

        return contador;
    }
}

void ListasCirculares::insertarPosicion(int dato, int posicion) {
    if (posicion > size()) {
        cout << "Posicion fuera de rango, insertando al final";
        insertarFinal(dato);
        return;
    }

    Nodo * nuevo = new Nodo(dato);

    if (posicion == 1) {
        Nodo * aux = cabeza;

        while (aux -> sig != cabeza) {
            aux = aux -> sig;
        }

        nuevo -> sig = cabeza;
        aux -> sig = nuevo;
        cabeza = nuevo;
        cout << "Se insert un dato: " << dato << endl;
        return;
    }

    int contador = 1;
    Nodo * aux = cabeza;

    while (contador < posicion - 1) {
        aux = aux -> sig;
        ++contador;
    }

    nuevo -> sig = aux -> sig;
    aux -> sig = nuevo;
    cout << "Se insert un dato: " << dato << endl;
}

void ListasCirculares::eliminarPosicion(int posicion) {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    if (posicion > size()) {
        cout << "Posicion fuera de rango, eliminando al final";
        eliminarFinal();
        return;
    }

    if (posicion == 1) {
        if (cabeza -> sig == cabeza) {
            delete cabeza;
            cabeza = nullptr;
            cout << "Se elimino la cabeza" << endl;
        } else {
            Nodo * aux = cabeza;

            while (aux -> sig != cabeza) {
                aux = aux -> sig;
            }

            Nodo * primero = cabeza;
            cabeza = cabeza -> sig;
            delete primero;
            aux -> sig = cabeza;
            cout << "Se elimino un dato" << endl;
        }

        return;
    }

    Nodo * aux = cabeza;
    Nodo * anterior;
    int contador = 1;

    while (contador < posicion) {
        anterior = aux;
        aux = aux -> sig;
        ++contador;
    }

    anterior -> sig = aux -> sig;
    delete aux;
    cout << "Se elimino un dato" << endl;
}