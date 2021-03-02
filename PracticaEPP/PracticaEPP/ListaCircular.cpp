#include "ListaCircular.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <thread>
using namespace std;

ListaCircular::ListaCircular() {
    this->objetoInicio = nullptr;
    this->objetoFin = nullptr;
    this->totalElementos = 0;
}

void ListaCircular::push(Cliente* cliente) {
    if (empty() == 1) {
        objetoInicio = cliente;
        objetoFin = cliente;
        objetoInicio->siguiente = objetoFin;
        objetoInicio->anterior = objetoFin;
        objetoFin->siguiente = objetoInicio;
        objetoFin->anterior = objetoInicio;
        if (cliente->getCarreta() != nullptr) {
            cout << "Cliente #" << cliente->getNumeroCliente() << " Esta comprando con carreta #" << cliente->getCarreta()->getNumeroCarreta() << endl;
        }
        else {
            cout << "Cliente #" << cliente->getNumeroCliente() << " Esta comprando " << endl;
        }
    }
    else {
        objetoFin->siguiente = cliente;
        cliente->anterior = objetoFin;
        cliente->siguiente = objetoInicio;
        objetoFin = cliente;
        if (cliente->getCarreta()!=nullptr) {
            cout << "Cliente #" << cliente->getNumeroCliente() << " Esta comprando con carreta #" << cliente->getCarreta()->getNumeroCarreta() << endl;
        }
        else {
            cout << "Cliente #" << cliente->getNumeroCliente() << " Esta comprando " << endl;
        }
        
    }
    this->totalElementos = this->totalElementos + 1;
}

Cliente* ListaCircular::borrar(int id) {
    if (empty() == 1) {
        cout << "Lista Circular Vacia";
    }
    else {
        Cliente* auxiliar;
        if (objetoInicio == objetoFin && objetoInicio->getNumeroCliente() == id) {
            auxiliar = objetoInicio;
            objetoInicio = objetoFin = nullptr;

        }
        else {
            if (objetoInicio->getNumeroCliente() == id) {
                auxiliar = objetoInicio;
                objetoFin = objetoInicio->siguiente;
                objetoInicio->siguiente = objetoFin;
                objetoInicio = objetoInicio->siguiente;
            }
            else if (objetoFin->getNumeroCliente() == id) {
                auxiliar = objetoFin;
                objetoFin = objetoFin->anterior;
                objetoFin->siguiente = objetoInicio;
                objetoInicio->anterior = objetoFin;

            }
            else {
                Cliente* aux = objetoInicio;
                while (aux->siguiente != nullptr) {
                    if (aux->getNumeroCliente() == id) {
                        break;
                    }
                    aux = aux->siguiente;
                }
                Cliente* anterior = aux->anterior;
                Cliente* siguiente = aux->siguiente;
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
                auxiliar = aux;
            }

        }
        this->totalElementos = this->totalElementos - 1;
        return auxiliar;
    }
}

int ListaCircular::empty() {
    if (objetoInicio == nullptr && objetoFin == nullptr) {
        return 1;
    }
    else {
        return 0;
    }
}

bool ListaCircular::comprobarNumero(int numero) {
    Cliente* aux = objetoInicio;
    while (aux != nullptr) {
        if (aux->getNumeroCliente() == numero) {
            return true;
        }
        else if (aux == objetoFin) {
            return false;
        }
        aux = aux->siguiente;
    }
    return false;
}