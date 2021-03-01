#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Caja.h"
#include "Carreta.h"
#include "Cliente.h"
#include "Cola.h"
#include "Pila.h"
#include "ListaCircular.h"
#include <string>
using namespace std;


int main() {
    ListaCircular* listacir= new ListaCircular();
    Carreta* caarreta1=new Carreta(50);
    Cliente *cliente1 =new Cliente(10,caarreta1);
    Cliente* cliente2 = new Cliente(20,caarreta1);
    Cliente* cliente3 = new Cliente(30,caarreta1);
    Cliente* cliente5 = new Cliente(50,caarreta1);
    Cola* cola = new Cola();
    Pila* pilaCarreta=new Pila();
    cola->push(cliente1);
    cola->push(cliente2);
    Cliente* cliente=cola->pop();
    cola->push(cliente);
    cout << cliente->getNumeroCliente()<<"     "<< cliente->getCarreta()->getNumeroCarreta() << endl;
    listacir->push(cliente);
    Cliente* clientecir=listacir->borrar(10);
    cout << clientecir->getNumeroCliente() << "     " << clientecir->getCarreta()->getNumeroCarreta() << endl;
    int clientes, cajas, carretas;
    cout << "Cuantos clientes entraran?" << endl;
    cin >> clientes;
    cout << "Cuantas cajas estaran disponibles?" << endl;
    cin >> cajas;
    cout << "Cuantas carretas estaran disponibles?" << endl;
    cin >> carretas;
    _getch();
    return 0;
}