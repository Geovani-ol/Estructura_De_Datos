#include "Factorial.h"
#include <iostream>

using namespace std;

int Factorial::factorial(int num) {
    if (num == 0) {
        return 1;
    }

    return factorial2(num);
}

int Factorial::factorial2(int num) {
    return num * factorial(num - 1);
}

void Factorial::mostrarFactorial() {
    int num;

    cout << "Dame un numero: ";
    cin >> num;

    cout << "El factorial de " << num << " es: " << factorial(num) << endl;
}



