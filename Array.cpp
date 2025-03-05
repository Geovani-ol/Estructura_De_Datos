#include "Array.h"
#include <iostream>

using namespace std;

void Array::array() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* puntero = arr;

    // *(puntero + 3) = 7;


    for (int i = 4; i >= 0; i--) {
        cout << *(puntero + i) << endl;
    }
}
