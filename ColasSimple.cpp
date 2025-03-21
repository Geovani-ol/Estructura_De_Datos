#include "ColasSimple.h"
#include <iostream>

using namespace std;

ColasSimple::ColasSimple() {
    final = -1;
    frente = -1;
}

bool ColasSimple::empty() {
    if (final == -1 && frente == -1) {
        return true;
    }

    return false;
}

bool ColasSimple::full() {
    return (final == MAX -1);
}

void ColasSimple::enqueue(int valor) {
    if (full()) {
        cout << "Error: La cola esta llena" << endl;
    } else {
        if (frente == -1) {
            frente = 0;
        }

        ++final;
        arr[final] = valor;
        cout << "Valor insertado" << endl;
    }
}

void ColasSimple::dequeue() {
    if (empty()) {
        cout << "Error: La cola esta vacia" << endl;
    } else {
        for (int i = frente; i < final; ++i) {
            arr[i] = arr[i+1];
        }

        --final;
        if (final == -1) {
            frente = -1;
        }
        cout << "Se elimino el valor" << endl;
    }
}

void ColasSimple::show() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        for (int i = frente; i <= final; ++i) {
            cout << arr[i] << endl;
        }

        cout << endl;
    }
}

void ColasSimple::top() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        cout << "El frente de la cola es: " << arr[frente] << endl;
    }
}


void ColasSimple::ejecutar() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    show();
    top();
    dequeue();
    dequeue();
    show();
    top();
}
