#ifndef ANAGRAMAS_H
#define ANAGRAMAS_H
#include <string>

using namespace std;

class Anagramas {
public:
    bool anagrama(string cadena, string cadena2, size_t indice = 0);
    void mostrarAnagrama();
};



#endif //ANAGRAMAS_H
