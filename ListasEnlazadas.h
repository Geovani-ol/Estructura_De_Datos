#ifndef LISTASENLAZADAS_H
#define LISTASENLAZADAS_H

struct Nodo {
    int valor;
    Nodo * sig;
    Nodo * ant;

    explicit Nodo(int dato) : valor(dato), sig(nullptr), ant(nullptr) {}
};

class ListasEnlazadas {
private:
    Nodo * cabeza;
    Nodo * cola;
public:
    ListasEnlazadas();
    ~ListasEnlazadas();
    bool empty();
    void insertarFinal(int dato);
    int numeroNodos();
    void insertarPosicion(int dato, int posicion);
    void eliminarPosicion(int posicion);
    void mostrar();
    void ejecutar();
};



#endif //LISTASENLAZADAS_H
