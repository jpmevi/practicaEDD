#include <string>
#pragma once
class Caja
{
private:
    int numeroCaja;
    float tiempoServicio;
    bool estadoLibre;
    int codigoCliente;
    int codigoCarreta;

public:
    Caja* siguiente;
    Caja* anterior;
    Caja(int, float, bool, int, int);
    int getNumeroCaja();
    float getTiempoServicio();
    bool getEstadoLibre();
    int getCodigoCliente();
    int getCodigoCarreta();
};

