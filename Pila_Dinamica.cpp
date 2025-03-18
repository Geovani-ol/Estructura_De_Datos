#include "Pila_Dinamica.h"
#include <iostream>

using namespace std;

Pila_Dinamica::Pila_Dinamica() {
    pila = nullptr;
}

bool Pila_Dinamica::vacia() {
    if (pila == nullptr) {
        return true;
    }

    return false;
}

void Pila_Dinamica::push(int valor) {
    Nodo * aux = new Nodo();
    aux->valor = valor;
    aux->sig = pila;
    pila = aux;

    cout << "Valor: " << valor << " se inserto en la pila" << endl;
}

void Pila_Dinamica::pop() {
    if (vacia()) {
        cout << "Pila vacia" << endl;
    } else {
        Nodo * aux = pila;
        pila = pila->sig;
        delete aux;

        cout << "Nodo eliminado" << endl;
    }
}

void Pila_Dinamica::mostrar() {
    if (vacia()) {
        cout << "Pila vacia" << endl;
    } else {
        Nodo * aux = pila;
        cout << "Valores en la pila:" << endl;
        while (aux != nullptr) {
            cout << aux->valor << endl;
            aux = aux->sig;
        }
    }
}

void Pila_Dinamica::size() {
    int contador = 0;

    if (vacia()) {
        cout << "Pila vacia" << endl;
        return;
    }

    Nodo * aux = pila;
    while (aux != nullptr) {
        contador++;
        aux = aux->sig;
    }

    cout << "Size: " << contador << endl;
}


void Pila_Dinamica::destruir() {
    while (!vacia()) {
        pop();
    }
}


void Pila_Dinamica::ejecutar() {
    push(3);
    push(5);
    push(18);
    size();
    mostrar();
    pop();
    size();
    mostrar();
    pop();
    size();
    mostrar();

    destruir();
}
