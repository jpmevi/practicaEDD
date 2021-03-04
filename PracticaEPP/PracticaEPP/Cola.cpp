#include "Cola.h"
#include <iostream>
#include<stdlib.h>
#include <conio.h>
using namespace std;

Cola::Cola() {

}
void Cola::push(Cliente* cliente) {
    if (objetoInicio == nullptr && objetoFinal == nullptr) {
        objetoInicio = cliente;
        objetoFinal = cliente;
        
    }
    else {
        objetoFinal->siguiente = cliente;
        objetoFinal = cliente;
        
    }

}

Cliente* Cola::pop() {
 if (objetoInicio != nullptr && objetoFinal != nullptr) {
        Cliente* aux = objetoInicio;
        objetoInicio = objetoInicio->siguiente;
        return aux;
    }
    else {
        cout << "Cola vacia" << endl;
    }
}

bool Cola::empty() {
    if (objetoInicio == nullptr || objetoFinal == nullptr) {
        return true;
    }
    return false;
}

bool Cola::comprobarNumero(int numero) {
    Cliente* aux = objetoInicio;
    while (aux != nullptr) {
        if (aux->getNumeroCliente() == numero) {
            return true;
        }
        else
        {
            aux = aux->siguiente;
            
        }
       
    }
    return false;
}

