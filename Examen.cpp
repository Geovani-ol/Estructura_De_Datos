// Opción 2

#include "Examen.h"
#include <iostream>

using namespace std;

int Examen::examen(int num1, int num2, int mcd) {
    int div, div2, mcd2;

    if (num1 > num2) {
        div = num1;
        div2 = num2;
    } else {
        div = num2;
        div2 = num1;
    }

    mcd2 = div % div2;

    if (mcd < mcd2) {
        mcd = mcd2;
    }
    div = div / div2;


    if (div % div2 == 0) {
        return mcd;
    }

    return examen(div, div2, mcd);

}

void Examen::mostrarExamen() {
    int num1, num2, mcd;

    cout << "Ingrese un numero entero: ";
    cin >> num1;
    cout << "Ingrese otro numero entero: ";
    cin >> num2;

    if (num1 > num2) {
        mcd = num1 % num2;
    } else {
        mcd = num2 % num1;
    }

    cout << "El MCD es: " << examen(num1, num2, mcd) << endl;
}
