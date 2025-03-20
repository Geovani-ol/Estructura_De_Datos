#include "ColasS_Estatica.h"
#include <iostream>

using namespace std;

ColasS_Estatica::ColasS_Estatica() {
    final = -1;
    frente = -1;
}

bool ColasS_Estatica::empty() {
    if (final == -1 && frente == -1) {
        return true;
    }

    return false;
}

bool ColasS_Estatica::full() {
    return (final == MAX -1);
}

void ColasS_Estatica::enqueue(int valor) {
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

void ColasS_Estatica::dequeue() {
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

void ColasS_Estatica::show() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        for (int i = frente; i <= final; ++i) {
            cout << arr[i] << endl;
        }

        cout << endl;
    }
}

void ColasS_Estatica::top() {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        cout << "El frente de la cola es: " << arr[frente] << endl;
    }
}


void ColasS_Estatica::ejecutar() {
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
