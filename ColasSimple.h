#ifndef COLASS_ESTATICA_H
#define COLASS_ESTATICA_H

const int MAX = 5;

class ColasSimple {
private:
    int arr[MAX];
    int frente;
    int final;

public:
    ColasSimple();
    bool empty();
    bool full();
    void enqueue(int valor);
    void dequeue();
    void show();
    void top();
    void ejecutar();
};



#endif //COLASS_ESTATICA_H
