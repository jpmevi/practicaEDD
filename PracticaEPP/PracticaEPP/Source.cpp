#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Caja.h"
#include "Carreta.h"
#include "Pila.h"
#include <string>
using namespace std;


int main() {
    Carreta *caarreta1=new Carreta(50);
    Carreta *caarreta2 = new Carreta(20);
    Carreta *caarreta3 = new Carreta(30);
    Carreta *caarreta4 = new Carreta(10);
    Pila* pilaCarreta=new Pila();
    pilaCarreta->push(caarreta1);
    pilaCarreta->push(caarreta2);
    pilaCarreta->push(caarreta3);
    pilaCarreta->push(caarreta4);
    pilaCarreta->mostrarCarretas();
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