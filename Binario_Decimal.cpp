#include "Binario_Decimal.h"
#include <iostream>
#include <math.h>

using namespace std;

int Binario_Decimal::binario_decimal(int num, int potencia) {
    if (num == 0) {
        return num;
    }
    int digito = num % 10;
    int p = digito * (pow(2, potencia));
    return p + binario_decimal(num / 10, ++potencia);
}

void Binario_Decimal::mostrar_decimal() {
    int num;

    cout << "Numero binario a convertir: ";
    cin >> num;

    cout << binario_decimal(num) << endl;
}


