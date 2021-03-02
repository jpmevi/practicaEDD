#pragma once
#include "Carreta.h"
class Pila
{

public:
    Carreta* carretaInicio;
    Carreta* carretaFinal;
    Pila();
    void push(Carreta* carreta);
    Carreta* pop();
    void mostrarCarretas();
    bool empty();
    bool comprobarNumero(int);
};

