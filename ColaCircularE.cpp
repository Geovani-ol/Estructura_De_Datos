#include "ColaCircularE.h"
#include <iostream>

using namespace std;

ColaCircularE::ColaCircularE() {
    frente = -1;
    final = -1;
}

bool ColaCircularE::empty() {
    return (frente == -1 && final == -1);
}

bool ColaCircularE::full() {
    return ((final + 1) % MAX == frente);
}

void ColaCircularE::enqueue(int valor) {
    if (full()) {
        cout << "Error: La cola esta llena" << endl;
    } else {
        if (frente == -1) {
            frente = 0;
        }

        final = (final + 1) % MAX;
        arr[final] = valor;
        cout << "Se inserto un valor: " << valor << endl;
    }
}

void ColaCircularE::dequeue() {
    if (empty()) {
        cout << "Error: La cola esta vacia" << endl;
    } else {
        if (frente == final) {
            frente = final = -1;
        } else {
            frente = (frente + 1) % MAX;
        }

        cout << "Se elimino un valor" << endl;
    }
}

void ColaCircularE::show() {
    if (empty()) {
        cout << "Error: La cola esta vacia" << endl;
    } else {
        int i = frente;

        while (i != final) {
            cout << arr[i] << endl;
            i = (i + 1) % MAX;
        }

        cout << arr[final] << endl;
    }
}

void ColaCircularE::top() {
    if (empty()) {
        cout << "Error: La cola esta vacia" << endl;
    } else {
        cout << "El frente de la cola es: " << arr[frente] << endl;
    }
}


void ColaCircularE::ejecutar() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    show();
    top();
    dequeue();
    dequeue();
    dequeue();
    show();
    top();
    enqueue(40);
    top();
}


