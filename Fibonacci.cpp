#include "Fibonacci.h"
#include <iostream>

using namespace std;

int Fibonacci::fibonacci(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;

    return fibonacci(num - 1) + fibonacci(num - 2);  // Llamada recursiva
}

void Fibonacci::fibonacci_iterativo() {
    int n;

    cout << "Dame un numero para la serie Fibonacci: ";
    cin >> n;  // Leer número desde la consola

    mostrarSerie(n);
}

void Fibonacci::mostrarSerie(int n) {
    cout << "La serie Fibonacci hasta " << n << " es: ";

    for (int i = 0; i <= n; ++i) {
        cout << fibonacci(i) << " ";
    }

    cout << endl;
}
