#include "FilaEspera.h"
#include <iostream>

using namespace std;

int main() {
    bool band = true;

    while (band) {
        cout << "*** TIENDA ***" << endl;
        cout << endl;

        cout << "1.- Agregar cliente" << endl;
        cout << "2.- Atender cliente" << endl;
        cout << "3.- Ver cantidad de clientes" << endl;
        cout << "4.- Mostrar al primer cliente (sin atenderlo)" << endl;
        cout << "5.- Salir" << endl;
        cout << endl;

        cout << "Elije una opcion: ";
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                band = false;
                break;
            default:
                cout << "opcion invalido" << endl;
        }

    }

    return 0;
}