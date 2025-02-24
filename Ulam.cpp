#include "Ulam.h"
#include <iostream>

using namespace std;

void Ulam::ulam(int num) {
    if (num == 1) {
        cout << num;
        return;
    }

    cout << num << " ";

    if (num % 2 == 0) {
        ulamPar(num);
    } else {
        ulamImpar(num);
    }
}

void Ulam::ulamPar(int num) {
    ulam(num / 2);
}

void Ulam::ulamImpar(int num) {
    ulam(3 * num + 1);
}


void Ulam::mostrarUlam() {
    int num;

    cout << "Dame un numero: ";
    cin >> num;

    cout << "La serie ulam es: ";
    ulam(num);
}


