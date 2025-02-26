#include <iostream>

using namespace std;

void cambio(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 9;

    cout << "Antes de cambiar x: " << x << endl;
    cout << "Antes de cambiar y: " << y << endl;

    cambio(&x, &y);

    cout << "Cambio de x: " << x << endl;
    cout << "Cambio de y: " << y << endl;

    return 0;
}
