#ifndef FILAESPERA_H
#define FILAESPERA_H

struct Nodo {
    int dato;
    Nodo * sig;
};

class FilaEspera {
private:
    Nodo * frente;
    Nodo * final;
public:
    FilaEspera();
    bool empty();
};



#endif //FILAESPERA_H
