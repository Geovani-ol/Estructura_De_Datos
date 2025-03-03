#ifndef ANAGRAMAS_H
#define ANAGRAMAS_H
#include <string>

using namespace std;

class Anagramas {
public:
    bool anagrama(const char palabra1[], const char palabra2[]);
    void ordenar_arreglo(char arr[], int n, int index);
    void mostrarAnagrama();
};



#endif //ANAGRAMAS_H
