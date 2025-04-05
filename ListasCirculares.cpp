#include "ListasCirculares.h"
#include <iostream>

using namespace std;

ListasCirculares::ListasCirculares() : cabeza(nullptr) {}

ListasCirculares::~ListasCirculares() {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo * aux = cabeza;
    Nodo * siguiente = nullptr;

    do {
        siguiente = aux -> sig;
        delete aux;
        aux = siguiente;
    } while (aux != cabeza);

    cout << "Se libero la memoria" << endl;
}


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
        int contador = 1;

        while (aux -> sig != cabeza) {
            ++contador;
            aux = aux -> sig;
        }

        return contador;
    }
}

void ListasCirculares::insertarPosicion(int dato, int posicion) {
    if (posicion > size()) {
        cout << "Posicion fuera de rango, insertando al final..." << endl;
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

void ListasCirculares::mostrar() {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo * aux = cabeza;

    do {
        cout << aux -> valor << " ";
        aux = aux -> sig;
    } while (aux != cabeza);

    cout << endl;
}

void ListasCirculares::eliminarValor(int dato) {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo * aux = cabeza;
    int contador = 1;

    do {
        if (aux -> valor == dato) {
            eliminarPosicion(contador);
            return;
        }

        aux = aux -> sig;
        ++contador;
    } while (aux != cabeza);

    cout << "Valor no encontrado" << endl;
}


void ListasCirculares::ejecutar() {
    insertarFinal(10);
    insertarFinal(20);
    insertarFinal(30);
    insertarPosicion(25, 4);
    mostrar();
    eliminarValor(40);
    mostrar();
}
