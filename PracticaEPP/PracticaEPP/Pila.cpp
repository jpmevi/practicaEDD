#include "Pila.h"
#include "Carreta.h"
#include <iostream>
using namespace std;


Pila ::Pila()
{
    
}

void Pila::push(Carreta* carreta) {
    if (carretaInicio == nullptr && carretaFinal == nullptr) {
        carretaFinal = carreta;
        carretaInicio = carreta;
        cout << "Carreta ingresada con numero: " << carreta->getNumeroCarreta() << endl;
    }
    else {
        carreta->siguiente = carretaInicio;
        carretaInicio = carreta;
        cout << "Carreta ingresada con numero: " << carreta->getNumeroCarreta() << endl;
    }
}

Carreta* Pila::pop() {
    if (carretaInicio != nullptr && carretaFinal != nullptr) {
        Carreta* aux = carretaInicio;
        if (carretaInicio == carretaFinal) {
            carretaInicio = nullptr;
            carretaFinal = nullptr;
        }
        else {
            carretaInicio = carretaInicio->siguiente;
        }
        return aux;
    }
    else {
        cout << "Lista vacia"<<endl;
    }
}



void Pila::mostrarCarretas() {
    Carreta* aux = carretaInicio;
    while (aux->siguiente != nullptr) {
        cout << "Numero de carreta: " << aux->getNumeroCarreta() << endl;
        aux = aux->siguiente;
    }
    cout << "Numero de carreta: " << aux->getNumeroCarreta() << endl;
}

bool Pila::empty() {
    if (carretaInicio == nullptr && carretaFinal == nullptr) {
        return true;
    }
    return false;
}

bool Pila::comprobarNumero(int numero) {
    Carreta* aux = carretaInicio;
    while (aux != nullptr) {
        if (aux->getNumeroCarreta() == numero) {
            return true;
        }
        else
        {
            aux = aux->siguiente;

        }

    }
    return false;
}