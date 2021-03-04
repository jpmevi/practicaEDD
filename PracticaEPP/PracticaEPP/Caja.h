#include <string>
#pragma once
class Caja
{
private:
    int numeroCaja;
    float tiempoServicio;
    float tiempoRestante;
    bool estadoLibre;
    int codigoCliente;
    int codigoCarreta;

public:
    Caja* siguiente;
    Caja* anterior;
    Caja(int, float,float, bool, int, int);
    int getNumeroCaja();
    float getTiempoServicio();
    float getTiempoRestante();
    bool getEstadoLibre();
    void setEstadoLibre(bool);
    void setCodigoCliente(int);
    void setCodigoCarreta(int);
    int getCodigoCliente();
    int getCodigoCarreta();
    void vaciarCaja();
    void setTiempoRestante(float);
};

