#ifndef COLACIRCULARD_H
#define COLACIRCULARD_H

struct Nodo {
    int valor;
    Nodo * sig;
};

class ColaCircularD {
private:
    Nodo * frente;
    Nodo * final;
public:
    ColaCircularD();
    bool empty();
    void enqueue(int val);
    void dequeue();
    void show();
    void destroy();
    void ejecutar();
};



#endif //COLACIRCULARD_H
