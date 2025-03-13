#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila() {
    posicion = -1;
}

bool Pila::vacia() const {
    return posicion == -1;
}

bool Pila::llena() const {
    return posicion == MAX - 1;
}

void Pila::push(int valor) {
    if (llena()) {
        cout << "Error: La pila está llena." << endl;
        return;
    }
    valores[++posicion] = valor;
}

int Pila::pop() {
    if (vacia()) {
        cout << "Error: La pila está vacía." << endl;
        return -1;
    }
    return valores[posicion--];
}

int Pila::top() const {
    if (vacia()) {
        cout << "Error: La pila está vacía." << endl;
        return -1;
    }
    return valores[posicion];
}

void Pila::mostrar() const {
    if (vacia()) {
        cout << "La pila está vacía." << endl;
        return;
    }
    cout << "Elementos de la pila: ";
    for (int i = 0; i <= posicion; i++) {
        cout << valores[i] << " ";
    }
    cout << endl;
}

void Pila::ejecutar() {
    cout << "Agregando elementos a la pila..." << endl;
    push(10);
    push(20);
    push(30);
    mostrar();

    cout << "Elemento en la cima: " << top() << endl;

    cout << "Sacando un elemento: " << pop() << endl;
    mostrar();
}
