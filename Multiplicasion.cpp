#include "Multiplicasion.h"
#include <iostream>

using namespace std;

int Multiplicasion::multiplicasion(int num1, int num2) {
    if (num2 == 0) return 0;

    return num1 + multiplicasion(num1, num2-1);
}

void Multiplicasion::mostrarMultiplicasion() {
    int num1, num2;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "Resultado de la multiplicasion: " << multiplicasion(num1, num2) << endl;
}


