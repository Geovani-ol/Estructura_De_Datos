#include "Stack.h"
#include <iostream>
#include <stack>

using namespace std;

void Stack::ejecutar() {
    stack <int> pila;

    cout << "Vacia: " << pila.empty() << endl;
    pila.push(42);
    pila.push(32);
    pila.push(56);

    cout << "Vacia: " << pila.empty() << endl;
    cout << "Tamaño: " << pila.size() << endl;

}
