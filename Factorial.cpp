#include "Factorial.h"
#include <iostream>

using namespace std;

int Factorial::factorial(int num) {
    if (num == 0 || num == 1) return 1;

    return num * factorial(num - 1);
}

void Factorial::mostrarFactorial() {
    int n;

    cout << "Numero para factorial: ";
    cin >> n;

    cout << "El factorial de " << n << " es: " << factorial(n) << endl;
}

