#ifndef LISTASCIRCULARES_H
#define LISTASCIRCULARES_H

struct Nodo{
    int valor;
    Nodo * sig;

    Nodo(int dato){
        valor = dato;
        sig = nullptr;
    }
};

class ListasCirculares {
private:
    Nodo * cabeza;
public:
    ListasCirculares();
    bool empty();
    void insertarFinal(int dato);
    void eliminarFinal();
    int size();
    void insertarPosicion(int dato, int posicion);
    void eliminarPosicion(int posicion);
};



#endif //LISTASCIRCULARES_H
