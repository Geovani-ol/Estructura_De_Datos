#ifndef PILA_H
#define PILA_H



class Pila {
private:
    static const int MAX = 5;
    int valores[MAX]{};
    int posicion;

public:
    Pila();
    bool vacia() const;
    bool llena() const;
    void push(int valor);
    int pop();
    int top() const;
    void mostrar() const;
    void ejecutar();
};



#endif //PILA_H
