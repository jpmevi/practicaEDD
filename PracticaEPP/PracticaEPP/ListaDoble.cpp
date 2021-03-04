#include "ListaDoble.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
using namespace std;

ListaDoble::ListaDoble() {
    this->cajaInicio = this->cajaFin = nullptr;
    this->totalElementos = 0;
}

void ListaDoble::push(Caja* caja) {
    if (empty() == 1) {
        this->cajaInicio = this->cajaFin = caja;
        
    }
    else {
        if (caja->getNumeroCaja() <= cajaInicio->getNumeroCaja()) {
            caja->siguiente = cajaInicio;
            cajaInicio->anterior = caja;
            cajaInicio = caja;
        }
        else if (caja->getNumeroCaja() >= cajaFin->getNumeroCaja()) {
            cajaFin->siguiente = caja;
            caja->anterior = cajaFin;
            cajaFin = caja;
        }
        else {
            Caja* aux = cajaInicio;
            while (aux->siguiente != nullptr) {
                if (caja->getNumeroCaja() >= aux->getNumeroCaja()) {
                    break;
                }
                aux = aux->siguiente;
            }
            Caja* siguiente = aux->siguiente;
            aux->siguiente = caja;
            caja->anterior = aux;
            caja->siguiente = siguiente;
            siguiente->anterior = caja;
        }
    }
    this->totalElementos = this->totalElementos + 1;
    cout << "Caja ingresada con numero: " << caja->getNumeroCaja() << endl;
}

void ListaDoble::borrar(int id) {
    if (this->empty() == 1) {
        cout << "Lista Circular Vacia";
    }
    else {

        if (this->cajaInicio == this->cajaFin && this->cajaInicio->getNumeroCaja() == id) {
            this->cajaInicio = this->cajaFin = nullptr;
        }
        else {
            if (this->cajaInicio->getNumeroCaja() == id) {
                this->cajaInicio = this->cajaInicio->siguiente;
            }
            else if (this->cajaFin->getNumeroCaja() == id) {
                this->cajaFin = this->cajaFin->anterior;
            }
            else {
                Caja* aux = this->cajaInicio;
                while (aux->siguiente != nullptr) {
                    if (aux->getNumeroCaja() == id) {
                        break;
                    }
                    aux = aux->siguiente;
                }
                Caja* anterior = aux->anterior;
                Caja* siguiente = aux->siguiente;
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
            }

        }
        totalElementos = totalElementos - 1;
    }
}

int ListaDoble::empty() {
    if (this->cajaInicio == nullptr && this->cajaFin == nullptr) {
        return 1;
    }
    else {
        return 0;
    }
}

bool ListaDoble::comprobarNumero(int numero) {
    Caja* aux = cajaInicio;
    while (aux != nullptr) {
        if (aux->getNumeroCaja() == numero) {
            return true;
        }
        else
        {
            aux = aux->siguiente;

        }

    }
    return false;
}