#include "FilaEspera.h"
#include <iostream>

using namespace std;

FilaEspera::FilaEspera() : frente(nullptr), final(nullptr) {}

bool FilaEspera::empty() {
    return (frente == nullptr && final == nullptr);
}

