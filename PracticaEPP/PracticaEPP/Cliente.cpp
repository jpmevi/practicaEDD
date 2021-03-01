#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(int numeroCliente, Carreta* carreta)
{
    this->numeroCliente = numeroCliente;
    this->carreta = carreta;
}

int Cliente::getNumeroCliente()
{
    return numeroCliente;


}

Carreta* Cliente::getCarreta()
{
    return carreta;
}

void Cliente::setNumeroCliente(int numero) {
    this->numeroCliente = numero;
}

void Cliente::setCarreta(Carreta* carreta) {
    this->carreta = carreta;
}