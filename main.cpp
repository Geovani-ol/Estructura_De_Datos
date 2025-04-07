#include "FilaEspera.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    FilaEspera filaEspera;
    bool band = true;

    while (band) {
        cout << endl << "*** TIENDA ***" << endl;
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
        cout << endl;

        switch (opcion) {
            case 1: {
                cout << "** Agregar cliente **" << endl;
                cout << "Ingresa el nombre del cliente:  ";
                string nombre;
                cin >> nombre;
                filaEspera.enqueue(nombre);
                break;
            }
            case 2:
                filaEspera.dequeue();
                break;
            case 3:
                filaEspera.show();
                break;
            case 4:
                filaEspera.showOne();
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