#include <string>
#pragma once
class Caja
{
private:
    int numeroCaja;
    float tiempoServicio;
    bool estadoLibre;
    std::string codigoCliente;
    int codigoCarreta;

public:
    Caja(int, float, bool, std::string, int);
    int getNumeroCaja();
    float getTiempoServicio();
    bool getEstadoLibre();
    std::string getCodigoCliente();
    int getCodigoCarreta();
};

