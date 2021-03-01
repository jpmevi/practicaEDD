#pragma once
#include "Cliente.h"
class Cola
{
public:
    Cliente* objetoInicio;
    Cliente* objetoFinal;
    Cola();
    void push(Cliente* cliente);
    Cliente* pop();
    void mostrarCola();
    bool empty();
};

