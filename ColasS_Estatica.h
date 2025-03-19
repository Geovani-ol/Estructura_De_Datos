#ifndef COLASS_ESTATICA_H
#define COLASS_ESTATICA_H



class ColasS_Estatica {
private:
    static const int MAX = 5;
    int arr[MAX]{};
    int frente;
    int final;
public:
    ColasS_Estatica();
    bool empty();
    bool full();
    void enqueue(int valor);
    void dequeue();
    void ejecutar();
};



#endif //COLASS_ESTATICA_H
