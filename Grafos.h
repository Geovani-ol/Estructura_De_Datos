#ifndef GRAFOS_H
#define GRAFOS_H
#include <string>

struct Arista;
using namespace std;

struct Vertice {
    string nombre;
    Vertice * sig;
    Arista * ari;

    explicit Vertice(string n) : nombre(n), sig(nullptr), ari(nullptr) {};
};

struct Arista {
    Arista * sig;
    Vertice * dest;

    explicit Arista(Vertice * d) : dest(d), sig(nullptr) {};
};

class Grafos {
private:
    Vertice * principio;
    Vertice * obtenerVertice(string nombre);
public:
    Grafos();
    void insertarVertice(string nombre);
};



#endif //GRAFOS_H
