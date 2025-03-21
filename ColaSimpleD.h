#ifndef COLASENCILLAD_H
#define COLASENCILLAD_H

struct Nodo {
    int valor;
    Nodo * sig;
};

class ColaSimpleD {
private:
    Nodo * frente;
    Nodo * final;
public:
    ColaSimpleD();
    bool empty();
    void enqueue(int valor);
    void dequeue();
    void show();
    void destroy();
    void ejecutar();
};



#endif //COLASENCILLAD_H
