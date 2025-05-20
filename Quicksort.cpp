#include "Quicksort.h"
#include <iostream>

using namespace std;

void Quicksort::ejecutar() {
    cout << "Arreglo original: " << endl;

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quicksort(arr, 0, arr.size());

    cout << "Arreglo ordenado: " << endl;

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void Quicksort::quicksort(vector<int>& a, int inicio, int fin) {
    if (inicio >= fin) return;

    int i = inicio;
    int d = fin;
    int pivote = a[(inicio + fin) / 2];

    while (i <= d) {
        while (a[i] < pivote) ++i;
        while (a[d] > pivote) --d;

        if (i <= d) {
            swap(a[i], a[d]);
            ++i;
            --d;
        }
    }

    quicksort(a, i, fin);
    quicksort(a, inicio, d);
}
