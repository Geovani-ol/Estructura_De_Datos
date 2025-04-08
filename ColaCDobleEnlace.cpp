#include "ColaCDobleEnlace.h"
#include <iostream>

using namespace std;

ColaCDobleEnlace::ColaCDobleEnlace(): cabeza(nullptr) {};

bool ColaCDobleEnlace::empty() {
    return cabeza == nullptr;
}

void ColaCDobleEnlace::insertarFinal(int dato) {
    Nodo * nuevo = new Nodo(dato);

    if (empty()) {
        cabeza = nuevo;
        cabeza -> sig = cabeza;
        cabeza -> ant = cabeza;
        return;
    }

    Nodo * aux = cabeza -> ant;

    aux -> sig = nuevo;
    nuevo -> sig = cabeza;
    nuevo -> ant = aux;
    cabeza -> ant = nuevo;

    cout << "Se inserto un dato al final: " << dato << endl;
}

void ColaCDobleEnlace::eliminarFinal() {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    if (cabeza -> ant == cabeza) {
        delete cabeza;
        cabeza = nullptr;
        cout << "Se elimino la cabeza" << endl;
        return;
    }

    Nodo * aux = cabeza -> ant;
    aux -> ant -> sig = cabeza;
    cabeza -> ant = aux -> ant;
    cout << "Se elimino un valor: " << aux -> valor << endl;
    delete aux;
}

int ColaCDobleEnlace::size() {
    if (empty()) {
        return 0;
    }

    Nodo * aux = cabeza;
    int contador = 1;

    while (aux -> sig != nullptr) {
        aux = aux -> sig;
        ++contador;
    }

    return contador;
}

void ColaCDobleEnlace::insertarPosicion(int dato, int posicion) {
    if (posicion > size()) {
        cout << "Fuera de rango, insertando al final...." << endl;
        insertarFinal(dato);
        return;
    }

    Nodo * nuevo = new Nodo(dato);

    if (posicion == 1) {
        nuevo -> sig = cabeza;
        cabeza -> ant -> sig = nuevo;
        nuevo -> ant = cabeza -> ant;
        cabeza -> ant = nuevo;
        cabeza = nuevo;

        cout << "Se inserto un nuevo dato: " << dato << endl;
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
    nuevo -> sig -> ant = nuevo;
    nuevo -> ant = aux;

    cout << "Se inserto un nuevo dato: " << dato << endl;
}
