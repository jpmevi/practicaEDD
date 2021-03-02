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

void crearCliente(int cantClientes);
void ingresarCarretas(int carretas);
Carreta* sacarCarreta();
void asignarCarreta(int cantcola);
void asignarClientesComprando(int cantComprando);
Cola* cola = new Cola();
Pila* pila1 = new Pila();
Pila* pila2 = new Pila();
ListaCircular *listaCircular = new ListaCircular();

int main() {
    
    /*ListaCircular* listacir= new ListaCircular();
    Carreta* caarreta1=new Carreta(50);
    Cliente *cliente1 =new Cliente(10,caarreta1);
    Cliente* cliente2 = new Cliente(20,caarreta1);
    Cliente* cliente3 = new Cliente(30,caarreta1);
    Cliente* cliente5 = new Cliente(50,caarreta1);
    
    Pila* pilaCarreta=new Pila();
    cola->push(cliente1);
    cola->push(cliente2);
    Cliente* cliente=cola->pop();
    cola->push(cliente);
    cout << cliente->getNumeroCliente()<<"     "<< cliente->getCarreta()->getNumeroCarreta() << endl;
    listacir->push(cliente);
    Cliente* clientecir=listacir->borrar(10);
    cout << clientecir->getNumeroCliente() << "     " << clientecir->getCarreta()->getNumeroCarreta() << endl;*/
    int clienteColaCarreta, carretas, clientesComprando,clientesColaPagos,cajas;
    cout << "Cuantos clientes estan en la cola de carretas?" << endl;
    cin >> clienteColaCarreta;
    cout << "Cuantas carretas por pila?" << endl;
    cin >> carretas;
    cout << "Cuantos clientes estan comprando?" << endl;
    cin >> clientesComprando;
    cout << "Cuantos clientes estan en la cola de pagos?" << endl;
    cin >> clientesColaPagos;
    cout << "Cuantas cajas desea?" << endl;
    cin >> cajas;
    crearCliente(clienteColaCarreta);
    ingresarCarretas(carretas);
    asignarCarreta(clienteColaCarreta);
    asignarClientesComprando(clientesComprando);
    _getch();
    return 0;
}



void crearCliente(int cantClientes) {
    Cliente* cliente;
    for (int i = 0; i < cantClientes; i++)
    {
        int random = (rand() % 100) + 1;
        if (cola->empty()) {
             cliente = new Cliente(random, nullptr);
        }
        else {
            
            while (cola->comprobarNumero(random))
            {
                random = (rand() % 100) + 1;
            }
             cliente = new Cliente(random, nullptr);
        }
        cola->push(cliente);
    }
}

void ingresarCarretas(int carretas) {
    Carreta* carreta;
    for (int i = 0; i < carretas; i++)
    {
        int random = (rand() % carretas) + 1;
        if (pila1->empty()) {
            carreta = new Carreta(random);
        }
        else {

            while (pila1->comprobarNumero(random))
            {
                random = (rand() % carretas) + 1;
            }
            carreta = new Carreta(random);
        }
        pila1->push(carreta);
    }
    for (int i = 0; i < carretas; i++)
    {
        int random = (rand() % carretas) + 1 + carretas;
        if (pila2->empty()) {
            carreta = new Carreta(random);
        }
        else {

            while (pila2->comprobarNumero(random))
            {
                random = (rand() % carretas) + 1 + carretas;
            }
            carreta = new Carreta(random);
        }
        pila2->push(carreta);
    }
}

Carreta* sacarCarreta() {
    Carreta* carretaSale;
    if (pila1->empty()==false) {
        carretaSale = pila1->pop();
    }
    else if (pila2->empty() == false) {
        carretaSale = pila2->pop();
    }
    else {
        cout << "Cliente en espera porque no hay carretas" << endl;
        return nullptr;
    }
    return carretaSale;
}

void asignarCarreta(int cantcola) {
    for (int i = 0; i < cantcola; i++)
    {
        cout << "######### Paso " << i << " #########" << endl ;
        if (pila1->empty() && pila2->empty()) {
            cout << "No hay carretas cliente en espera" << endl;
        }
        else {
            Carreta* carreta = sacarCarreta();
            Cliente* cliente = cola->pop();
            cliente->setCarreta(carreta);
            cout << "El cliente #" << cliente->getNumeroCliente() << " Retiro la carreta #" << cliente->getCarreta()->getNumeroCarreta() << endl;
            listaCircular->push(cliente);
        }
    }
}

void asignarClientesComprando(int cantComprando) {
    Cliente* cliente;
for (int i = 0; i < cantComprando; i++)
{


    int random = (rand() % 100) + 1;
    if (listaCircular->empty()) {
        cliente = new Cliente(random, nullptr);
    }
    else {

        while (listaCircular->comprobarNumero(random))
        {
            random = (rand() % 100) + 1;
        }
        cliente = new Cliente(random, nullptr);
    }
    listaCircular->push(cliente);
}
}