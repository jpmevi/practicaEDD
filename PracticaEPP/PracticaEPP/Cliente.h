#pragma once
#include "Carreta.h"
class Cliente
{
private:
    int numeroCliente;
    Carreta* carreta;
public:
    Cliente* siguiente;
    Cliente* anterior;
    Cliente(int,Carreta*);
    int getNumeroCliente();
    Carreta* getCarreta();
    void setNumeroCliente(int);
    void setCarreta(Carreta*);
};
