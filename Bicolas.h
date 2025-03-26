#ifndef BICOLAS_H
#define BICOLAS_H

struct Nodo {
    int valor;
    Nodo * sig;
    Nodo * ant;
};

class Bicolas {
private:
    Nodo * frente;
    Nodo * final;
public:
    Bicolas();
    bool empty();
    void enqueueFinal(int val);
    void dequeueFinal();
    void enqueueFrente(int val);
    void dequeueFrente();
    void show();
    void destroy();
    void ejecutar();
};



#endif //BICOLAS_H
