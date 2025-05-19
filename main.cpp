#include <iostream>

using namespace std;

int main() {
    int n = 5;
    int v[5] = {5, 26, 16, 2, 8};
    int ordenada[v];

    for (int i = 0; i < n; i++) {
        ordenada[i] = v[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ordenada[j] > ordenada[j + 1]) {
                int temp = ordenada[j];
                ordenada[j] = ordenada[j + 1];
                ordenada[j + 1] = temp;
            }
        }
    }

    for (int x : ordenada) {
        cout << x << " ";
    }
    return 0;
}