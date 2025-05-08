#ifndef ARBOLES_H
#define ARBOLES_H

struct Nodo {
    int valor;
    Nodo * izq;
    Nodo * der;

    explicit Nodo (int dato) : valor(dato), izq(nullptr), der(nullptr) {}
};

class Arboles {
private:
    Nodo * raiz;
public:
    Arboles();
    void insertar(int dato, Nodo*& nodo);
    void destruir(Nodo*& nodo);
    void inorden(Nodo*& nodo);
    void posorden(Nodo*& nodo);
    void preorden(Nodo*& nodo);
    Nodo* sucesor(Nodo* nodo);
    Nodo* eliminar(Nodo* nodo, int valor);
    void ejecutar();
};



#endif //ARBOLES_H
