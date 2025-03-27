#ifndef LISTAS_H
#define LISTAS_H

struct Nodo {
    int valor;
    Nodo * sig;

    explicit Nodo(int x) : valor(x), sig(nullptr) {}
};

class Listas {
private:
    Nodo * cabeza;
public:
    Listas();
    bool empty();
    void insertarFinal(int val);
    void insertarPosicion(int val, int posicion);
};



#endif //LISTAS_H
