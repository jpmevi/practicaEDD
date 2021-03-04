#include "Caja.h"
#include <iostream>
using namespace std;


Caja::Caja(int numeroCaja, float tiempoServicio,float tiempoRestante, bool estadoLibre, int codigoCliente, int codigoCarreta)
{
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->tiempoRestante = tiempoRestante;
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
float Caja::getTiempoRestante()
{
    return tiempoRestante;
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

void Caja::setEstadoLibre(bool flag) {
    this->estadoLibre = flag;
}

void Caja::setTiempoRestante(float tiempo) {
    this->tiempoRestante = tiempo;
}

void Caja::setCodigoCliente(int codigo) {
    this->codigoCliente = codigo;
}

void Caja::setCodigoCarreta(int codigo) {
    this->codigoCarreta = codigo;
}

void Caja::vaciarCaja() {
    this->setEstadoLibre(true);
    this->setCodigoCliente(0);
   this->setCodigoCarreta(0);
   this->setTiempoRestante(this->tiempoServicio);
}