#include <iostream>
//
// Created by cland on 20/05/2025.
//
// {1,4,2,3,7,8,5} divide el tamanio/2
// el salto sera en este caso de 3 en tres y va poniendo el mas mayor hasta la derecha y el
// mas menor hasta la izqyierda y vuelve a hacer el salto que ahora sea de 1 EN 1
using namespace std;
#include "ShellSort.h"



void ShellSort::shellsort(int a[], int tam) {
    int paso, i,j,temp;

    paso = tam/2;
    while (paso > 0) {
        for (i = paso; i < tam; i++) {
            temp = a[i];
            for (j =i; j >= paso; j-=paso) {
                if (a[j-paso] > temp) {
                    a[j] = a[j-paso];
                } else {
                    break;
                }
            }
            a[j] = temp;
        }
        paso = paso/2;
    }
}

void ShellSort::ejecutar() {
    cout << "Arreglo desordenado:"<<endl;
    for (int i=0;i<longitud;++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    shellsort(array, longitud);

    cout << "Arreglo ordenado:"<<endl;
    for (int i=0;i<longitud;++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}