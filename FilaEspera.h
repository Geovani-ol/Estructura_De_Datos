#ifndef FILAESPERA_H
#define FILAESPERA_H
#include <string>

using namespace std;

struct Nodo {
    string dato;
    Nodo * sig;
};

class FilaEspera {
private:
    Nodo * frente;
    Nodo * final;
public:
    FilaEspera();
    ~FilaEspera();
    bool empty();
    void enqueue(string persona);
    void dequeue();
    void show();
    void showOne();
};



#endif //FILAESPERA_H
