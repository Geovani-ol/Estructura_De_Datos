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
    ~Listas();
    bool empty();
    void insertarFinal(int val);
    void insertarPosicion(int val, int posicion);
    void eliminarPosicion(int posicion);
    void mostrar();
    void buscar(int val);
    void ejecutar();
};



#endif //LISTAS_H
