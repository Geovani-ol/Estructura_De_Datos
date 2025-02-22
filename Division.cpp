#include "Division.h"
#include <iostream>

using namespace std;

int Division::division(int num1, int num2) {
    if (num1 < num2) return 0;

    return 1 + division(num1-num2, num2);
}

void Division::mostrarDivision() {
    int divisor, dividendo;

    cout << "Digite el numero dividendo: ";
    cin >> dividendo;
    cout << "Digite el numero divisor: ";
    cin >> divisor;

    cout << "Resultado: " << division(dividendo, divisor) << endl;
}
