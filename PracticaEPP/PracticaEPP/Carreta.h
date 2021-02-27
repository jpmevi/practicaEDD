#pragma once
class Carreta
{
private:
    int numeroCarreta;

public:
    Carreta* siguiente;
    Carreta(int);
    int getNumeroCarreta();
    void setNumeroCarreta(int);
};

