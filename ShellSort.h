//
// Created by cland on 20/05/2025.
//

#ifndef SHELLSORT_H
#define SHELLSORT_H



class ShellSort {
private:
    int array[8] = {8,2,5,9,1,6,4,3};
    int longitud = sizeof(array)/sizeof(array[0]);
public:
    void ejecutar();

    void shellsort(int a[], int tam);
};



#endif //SHELLSORT_H