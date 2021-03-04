#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Caja.h"
#include "Carreta.h"
#include "Cliente.h"
#include "Cola.h"
#include "Pila.h"
#include "ListaCircular.h"
#include "ListaDoble.h"
#include <string>
using namespace std;

void crearCliente(int cantClientes);
void ingresarCarretas(int carretas);
Carreta* sacarCarreta();
void asignarCarreta(int cantcola);
void asignarClientesComprando(int cantComprando, int cantClientes, int cantCarretas);
void asignarClientesPagando(int cantPagando, int cantComprando, int cantClientes, int cantCarretas);
void asignarCajas(int cantCajas, int cantClientes, int cantComprando,  int clientesPagos, int cantCarretas);
Cliente* sacarClienteDeCompras();
Cola* cola = new Cola();
Cola* colaPagos = new Cola();
Pila* pila1 = new Pila();
Pila* pila2 = new Pila();
ListaCircular *listaCircular = new ListaCircular();
ListaDoble* listaDoble = new ListaDoble();

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
    cout << "######### Paso " << 1 << " #########" << endl;
    crearCliente(clienteColaCarreta);
    ingresarCarretas(carretas);
    asignarClientesComprando(clientesComprando, clienteColaCarreta,carretas);
    asignarClientesPagando(clientesColaPagos, clientesComprando, clienteColaCarreta, carretas);
    asignarCajas(cajas, clienteColaCarreta, clientesComprando, clientesColaPagos, carretas);
    asignarCarreta(clienteColaCarreta);
    Cliente* cliente1 = sacarClienteDeCompras();
    _getch();
    return 0;
}



void crearCliente(int cantClientes) {
    Cliente* cliente;
    for (int i = 0; i < cantClientes; i++)
    {
        int random = (rand() % cantClientes) + 1;
        if (cola->empty()) {
             cliente = new Cliente(random, nullptr);
        }
        else {
            
            while (cola->comprobarNumero(random))
            {
                random = (rand() % cantClientes) + 1;
            }
             cliente = new Cliente(random, nullptr);
        }
        cola->push(cliente);
        cout << "Cliente ingresado con numero: " << cliente->getNumeroCliente() << endl;
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
       
        if (pila1->empty() && pila2->empty()) {
            cout << "No hay carretas cliente en espera" << endl;
        }
        else {
            Carreta* carreta = sacarCarreta();
            Cliente* cliente = cola->pop();
            cliente->setCarreta(carreta);
            cout << "El cliente #" << cliente->getNumeroCliente() << " Retiro la carreta #" << cliente->getCarreta()->getNumeroCarreta() << endl;
            listaCircular->push(cliente);
            int random = (rand() % 100) + 1;
            if (listaCircular->comprobarNumero(random)) {
                Cliente* clientePagos = listaCircular->borrar(random);
                colaPagos->push(clientePagos);
                cout << "El cliente #" << cliente->getNumeroCliente() << " Esta comprando con la carreta #" << cliente->getCarreta()->getNumeroCarreta() << endl;
            }
        }
    }
}

void asignarClientesComprando(int cantComprando, int cantClientes,int cantCarretas) {
    Cliente* cliente;
for (int i = 0; i < cantComprando; i++)
{


    int random = (rand() % cantComprando) + 1+cantClientes;
    int carreta = (rand() % cantComprando) + 1 + cantCarretas*2+i;
    Carreta* carretaObj = new Carreta(carreta);
    if (listaCircular->empty()) {
        cliente = new Cliente(random,carretaObj);
    }
    else {

        while (listaCircular->comprobarNumero(random))
        {
            random = (rand() % cantComprando) + 1 + cantClientes;
        }
        cliente = new Cliente(random, carretaObj);
    }
    listaCircular->push(cliente);
}
}

void asignarClientesPagando(int cantPagando, int cantComprando, int cantClientes, int cantCarretas) {
    Cliente* cliente;
    for (int i = 0; i < cantPagando; i++)
    {


        int random = (rand() % cantPagando) + 1 + cantClientes+cantComprando+i;
        int carreta = (rand() % cantPagando) + 1 + cantCarretas * 2 + i+cantComprando;
        Carreta* carretaObj = new Carreta(carreta);
        if (colaPagos->empty()) {
            cliente = new Cliente(random, carretaObj);
        }
        else {

            while (colaPagos->comprobarNumero(random))
            {
                random = (rand() % cantPagando) + 1 + cantClientes + cantComprando + i;
            }
            cliente = new Cliente(random, carretaObj);
        }
        colaPagos->push(cliente);
        cout << "Cliente ingresado en la cola de pagos con #" << cliente->getNumeroCliente() << endl;
    }
}
void asignarCajas(int cantCajas,int cantClientes,int cantComprando,int clientesPagos,int cantCarretas) {
    Caja* caja;
    for (int i = 0; i < cantCajas; i++)
    {
        int random = (rand() % 100) + 1;
        int tiempo = (rand() % 5) + 1;
        if (listaDoble->empty()) {
            caja = new Caja(random, tiempo, true, 0, 0);
        }
        else {

            while (listaDoble->comprobarNumero(random))
            {
                random = (rand() % 100) + 1;
            }
            caja = new Caja(random, tiempo, true, 0,0);
        }
        listaDoble->push(caja);
    }
}

Cliente* sacarClienteDeCompras() {
    int totalClientes = listaCircular->totalElementos;
    srand((int)time(0));
    int random = (rand() % 100) + 1;
    if (random <= totalClientes) {
        Cliente* cliente = listaCircular->borrar(random);
        return cliente;
    }
    else {
        cout << "No se hizo nada porque el numero random fue " << random << " y se esperaba un numero menos de " << totalClientes << endl;
        return nullptr;
    }

}