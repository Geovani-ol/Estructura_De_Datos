#ifndef COLACICLICAE_H
#define COLACICLICAE_H

const int MAX = 5;

class ColaCircularE {
private:
    int arr[MAX];
    int frente;
    int final;

public:
    ColaCircularE();
    bool empty();
    bool full();
    void enqueue(int valor);
    void dequeue();
    void show();
    void top();
    void ejecutar();
};



#endif //COLACICLICAE_H
