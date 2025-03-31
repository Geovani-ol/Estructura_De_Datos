#include "Listas.h"
#include <iostream>

using namespace std;

Listas::Listas() : cabeza(nullptr) {}       // Constructor

Listas::~Listas() {         // Destructor
    Nodo * aux = cabeza;
    Nodo * siguiente;


    while (aux !=nullptr) {
        siguiente = aux -> sig;
        delete aux;
        aux = siguiente;
    }
}


bool Listas::empty() {
    return cabeza == nullptr;
}

void Listas::insertarFinal(int val) {
    Nodo * nuevo = new Nodo(val);

    if (empty()) {
        cabeza = nuevo;
    } else {
        Nodo * aux = cabeza;

        while (aux -> sig != nullptr) {
            aux = aux -> sig;
        }

        aux -> sig = nuevo;
    }

    cout << "Se inserto un dato: " << val << endl;
}

void Listas::insertarPosicion(int val, int posicion) {
    Nodo * nuevo = new Nodo(val);

    if (posicion == 1) {
        nuevo -> sig = cabeza;
        cabeza = nuevo;
        return;
    }

    Nodo * aux = cabeza;
    int contador = 1;

    while (aux != nullptr && contador < posicion - 1) {
        aux = aux -> sig;
        ++contador;
    }

    if (aux == nullptr) {
        cout << "La posicion esta fuera de rango" << endl;
        return;
    }

    nuevo -> sig = aux -> sig;
    aux -> sig = nuevo;
    cout << "Se inserto un nodo: " << val << endl;
}

void Listas::eliminarPosicion(int posicion) {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo * aux = cabeza;

    if (posicion == 1) {
        cabeza = cabeza -> sig;
        delete aux;
        return;
    }

    Nodo * anterior = nullptr;
    int contador = 1;

    while (aux != nullptr && contador < posicion) {
        anterior = aux;
        aux = aux -> sig;
        ++contador;
    }

    if (aux == nullptr) {
        cout << "La posicion esta fuera de rango" << endl;
        return;
    }

    anterior -> sig = aux -> sig;
    delete aux;
}

void Listas::mostrar() {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
    } else {
        Nodo * aux = cabeza;

        while (aux != nullptr) {
            cout << aux -> valor << " ";
            aux = aux -> sig;
        }

        cout << endl;
    }
}

void Listas::buscar(int val) {
    if (empty()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo * aux = cabeza;
    int contador = 1;
    bool encontrado = false;

    while (aux != nullptr) {
        if (aux -> valor == val) {
            cout << "Valor encontrado: " << val << " En posicion: " << contador << endl;
            encontrado = true;
        }

        aux = aux -> sig;
        ++contador;
    }

    if (!encontrado) {
        cout << "Valor no encontrado en la lista" << endl;
    }
}

void Listas::ejecutar() {
    insertarFinal(10);
    insertarFinal(30);
    insertarPosicion(20, 2);
    mostrar();
    buscar(20);
    insertarFinal(20);
    mostrar();
    buscar(20);
    eliminarPosicion(2);
    mostrar();
    eliminarPosicion(1);
    mostrar();
}
