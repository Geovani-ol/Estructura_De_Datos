#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

using namespace std;

class Quicksort {
private:
    vector<int> arr;
public:
    void ejecutar();
    void quicksort(vector<int>& a, int inicio, int fin);
};



#endif //QUICKSORT_H
