#include "Numero_Reverso.h"

#include <iostream>
#include <ostream>

using namespace std;

void Numero_Reverso::reverso(int num) {
    if (num == 0) return;

    cout << num % 10;
    reverso(num / 10);
}

void Numero_Reverso::mostrarReverso() {
    int num;

    cout << "Numero reverso: ";
    cin >> num;

    reverso(num);
}
