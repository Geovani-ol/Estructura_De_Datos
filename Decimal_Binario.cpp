#include "Decimal_Binario.h"
#include <iostream>

using namespace std;

void Decimal_Binario::decimal_binario(int num) {
    if (num == 0) return;

    decimal_binario(num / 2);
    cout << num % 2;
}

void Decimal_Binario::mostrarDecimalBinario() {
    int num;

    cout << "Numero decimal: ";
    cin >> num;

    decimal_binario(num);
}

