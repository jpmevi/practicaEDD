#pragma once
#include "Caja.h"
class ListaDoble
{
public:
    Caja* cajaInicio;
    Caja* cajaFin;
    int totalElementos;
    ListaDoble();
    void push(Caja* caja);
    void borrar(int id);
    int empty();
    bool comprobarNumero(int);
     
};

