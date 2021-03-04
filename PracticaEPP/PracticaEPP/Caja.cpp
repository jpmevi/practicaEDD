#include "Caja.h"
#include <iostream>
using namespace std;


Caja::Caja(int numeroCaja, float tiempoServicio, bool estadoLibre, int codigoCliente, int codigoCarreta)
{
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->estadoLibre = estadoLibre;
    this->codigoCliente = codigoCliente;
    this->codigoCarreta = codigoCarreta;
}

int Caja::getNumeroCaja()
{
    return numeroCaja;
}
float Caja::getTiempoServicio()
{
    return tiempoServicio;
}
bool Caja::getEstadoLibre()
{
    return estadoLibre;
}
int Caja::getCodigoCliente()
{
    return codigoCliente;
}
int Caja::getCodigoCarreta()
{
    return codigoCarreta;
}

