#pragma once
#include "Cliente.h"
class ListaCircular
{
public:
    Cliente* objetoInicio;
    Cliente* objetoFin;
    int totalElementos;
    ListaCircular();
    void push(Cliente* cliente);
    Cliente* borrar(int id);
    int empty();
};

