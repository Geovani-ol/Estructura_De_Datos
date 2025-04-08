#ifndef COLACDOBLEENLACE_H
#define COLACDOBLEENLACE_H

struct Nodo {
    int valor;
    Nodo * sig;
    Nodo * ant;

    explicit Nodo(int dato): valor(dato), sig(nullptr), ant(nullptr) {};
};

class ColaCDobleEnlace {
private:
    Nodo * cabeza;
public:
    ColaCDobleEnlace();
    bool empty();
    void insertarFinal(int dato);
    void eliminarFinal();
    int size();
    void insertarPosicion(int dato, int posicion);
};



#endif //COLACDOBLEENLACE_H
