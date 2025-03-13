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
    void ejecutar();
};



#endif //PILA_DINAMICA_H
