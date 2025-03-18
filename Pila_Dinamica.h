#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

struct Nodo {
    int valor;
    Nodo* sig;
};

class Pila_Dinamica {
private:
    Nodo* pila;
public:
    Pila_Dinamica();
    bool vacia();
    void push(int valor);
    void pop();
    void mostrar();
    void size();
    void destruir();
    void ejecutar();
};



#endif //PILA_DINAMICA_H
