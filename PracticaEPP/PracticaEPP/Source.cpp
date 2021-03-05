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
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <thread>
#include <Windows.h>
#include "Graphviz.h"
using namespace std;

void crearCliente(int cantClientes, int clientesTotales);
void ingresarCarretas(int carretas);
Carreta* sacarCarreta();
void asignarCarreta(int cantcola);
void asignarClientesComprando(int cantComprando, int cantClientes, int cantCarretas);
void asignarClientesPagando(int cantPagando, int cantComprando, int cantClientes, int cantCarretas);
void asignarCajas(int cantCajas);
Caja* asignarClienteACaja();
Cliente* sacarClienteDeCompras();
bool guardarCarreta(Carreta* carreta);
void atenderEnCaja(Caja* caja);
void restarTiempo();
Cola* cola = new Cola();
Cola* colaPagos = new Cola();
Pila* pila1 = new Pila();
Pila* pila2 = new Pila();
Graphviz *grafo = new Graphviz();
ListaCircular *listaCircular = new ListaCircular();
ListaDoble* listaDoble = new ListaDoble();
ofstream file("archivo.dot");
std::string colaPagosString = "";
std::string pilastring = "";
std::string pilastring2 = "";
std::string colastring = "";
std::string listaCircularstring = "";

int main() {
    
    file << "digraph G {\n";
    file << " rankdir = TB;\n";    
    int clienteColaCarreta, carretas, clientesComprando, clientesColaPagos, cajas, contador = 1, clientesTotales;
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
    clientesTotales = clienteColaCarreta;
    ingresarCarretas(carretas);
    asignarCajas(cajas);
    asignarClientesComprando(clientesComprando, clienteColaCarreta, carretas);
    asignarClientesPagando(clientesColaPagos, clientesComprando, clienteColaCarreta, carretas);
    while (true) { 
        crearCliente(clienteColaCarreta,clientesTotales);
        asignarCarreta(clienteColaCarreta);
    Cliente* cliente1 = sacarClienteDeCompras();
    if (cliente1 != nullptr) {
        colaPagos->push(cliente1);
        Caja* caja = asignarClienteACaja();
        if (caja != nullptr) {
            atenderEnCaja(caja);
        }
    }
    else {
        restarTiempo();
        Caja* aux = listaDoble->cajaInicio;
        bool flag = false;
        while (aux != nullptr) {
            if (!aux->getEstadoLibre()) {
                flag = true;
                break;
            }
            aux = aux->siguiente;
        }
        atenderEnCaja(aux);
    }
    cout << "Cuantos nuevos clientes entraran?" << endl;
    cin >> clienteColaCarreta;
    contador = contador + 1;
    clientesTotales = clientesTotales + clienteColaCarreta;
    cout << "######### Paso " << contador << " #########" << endl;
    
    }
    _getch();
    return 0;
}



void crearCliente(int cantClientes,int clientesTotales) {
    file << "subgraph cluster_1 {\n";
    file << "node [shape=record, width=.1, height=.1];\n";
    file << "style=filled;\n";
    file << "color=lightgrey;\n";
    file << "label = \" Cola clientes \";\n";
   
    Cliente* cliente;
    for (int i = 0; i < cantClientes; i++)
    {
        int random = (rand() % cantClientes) + 1+clientesTotales;
        if (cola->empty()) {
             cliente = new Cliente(random, nullptr);
        }
        else {
            
            while (cola->comprobarNumero(random))
            {
                random = (rand() % cantClientes ) + 1+clientesTotales;
            }
             cliente = new Cliente(random, nullptr);
        }
        cola->push(cliente);
        if (i + 1 == cantClientes) {
            colastring = colastring + std::to_string(cliente->getNumeroCliente());
        }
        else {
            colastring = colastring+ std::to_string(cliente->getNumeroCliente()) + " | " ;
        }
    }
    file << "nd2 [label = \" " + colastring + "  \" , height = 4]; \n";
    file << "}\n";
}

void ingresarCarretas(int carretas) {
    
    file << "subgraph cluster_0 {\n";
    file << "node [shape=record, width=.1, height=.1];\n";
    file << "style=filled;\n";
    file << "color=lightgrey;\n";
    file << "label = \" Pilas Carretas \";\n";
    
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
        if (i + 1 == carretas) {
            pilastring = pilastring + std::to_string(random);
        }
        else {
            pilastring = std::to_string(random) + " | " + pilastring;
        }
                            
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
        if (i+1==carretas) {
            pilastring2 = pilastring2 +std::to_string(random) ;
        }
        else {
            pilastring2 = std::to_string(random) + " | " + pilastring2;
        }
       
    }
    file << "nd0 [label = \" " + pilastring + "  \" , height = 4]; \n";
    file << "nd1 [label = \" " + pilastring2 + "  \" , height = 4]; \n";
    file << "}\n";
    
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
   
    
    int inicio, fin;
    file << "subgraph cluster_2 {\n";
    file << "node [shape=record, width=.1, height=.1];\n";
    file << "style=filled;\n";
    file << "color=lightgrey;\n";
    file << "label = \" Lista Compras \";\n";
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
            if (i == 0) {
                inicio = cliente->getNumeroCliente();
            }
            if (i + 1 == cantcola) {
                listaCircularstring = listaCircularstring + std::to_string(cliente->getNumeroCliente());
                fin = cliente->getNumeroCliente();
            }
            else {
                listaCircularstring = listaCircularstring +std::to_string(cliente->getNumeroCliente()) + " | ";
            }
            int random = (rand() % 100) + 1;
            if (listaCircular->comprobarNumero(random)) {
                Cliente* clientePagos = listaCircular->borrar(random);
                colaPagos->push(clientePagos);
                cout << "El cliente #" << cliente->getNumeroCliente() << " Esta comprando con la carreta #" << cliente->getCarreta()->getNumeroCarreta() << endl;
               
                if (i + 1 == cantcola) {
                    colaPagosString = colaPagosString + std::to_string(cliente->getNumeroCliente());
                }
                else {
                    colaPagosString = colaPagosString + std::to_string(cliente->getNumeroCliente()) + " | ";
                }
            }
        }
    }
    file << "nd3 [label = \"" + listaCircularstring + "\" , height = 4]; \n";
    file << "}\n";
    file << "}\n";
    file.close();
    system("dot -Tpng archivo.dot -o imagen.png");
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
   
    file << "subgraph cluster_3 {\n";
    file << "node [shape=record, width=.1, height=.1];\n";
    file << "style=filled;\n";
    file << "color=lightgrey;\n";
    file << "label = \" ColaPagos \";\n";
    
    
    for (int i = 0; i < cantPagando; i++)
    {


        int random = (rand() % cantPagando) + 1 + cantClientes+cantComprando+i;
        int carreta = (rand() % cantPagando) + 1 + cantCarretas * 2 + i+cantComprando;
        Carreta* carretaObj = new Carreta(carreta);
        if (colaPagos->empty()) {
            cliente = new Cliente(random, carretaObj);
        }
        else {

                random = (rand() % cantPagando) + 1 + cantClientes + cantComprando + i;

            cliente = new Cliente(random, carretaObj);
        }
        colaPagos->push(cliente);
        if (i + 1 == cantPagando) {
            colaPagosString = colaPagosString + std::to_string(cliente->getNumeroCliente());
        }
        else {
            colaPagosString = colaPagosString + std::to_string(cliente->getNumeroCliente()) + " | ";
        }
        cout << "Cliente ingresado en la cola de pagos con #" << cliente->getNumeroCliente() << endl;
        Caja* caja2 = asignarClienteACaja();
        if (caja2 != nullptr) {
            atenderEnCaja(caja2);
        }
       
    }
    file << "nd4 [label = \"" + colaPagosString + "\" , height = 4]; \n";
    file << "}\n";
    
}
void asignarCajas(int cantCajas) {
    Caja* caja;
    std::string listaCajasString = "";
    file << "subgraph cluster_5 {\n";
    file << "node [shape=record, width=.1, height=1];\n";
    file << "style=filled;\n";
    file << "color=lightgrey;\n";
    file << "label = \" ListaCajas \";\n";
    for (int i = 0; i < cantCajas; i++)
    {
        int random = (rand() % cantCajas) + 1;
        int tiempo = (rand() % 5) + 1;
        if (listaDoble->empty()) {
            caja = new Caja(random, tiempo,tiempo, true, 0, 0);
        }
        else {

            while (listaDoble->comprobarNumero(random))
            {
                random = (rand() % cantCajas) + 1;
            }
            caja = new Caja(random, tiempo,tiempo, true, 0,0);
        }
        listaDoble->push(caja);
        listaCajasString.append("\"" "Caja: "+ std::to_string(caja->getNumeroCaja()) + "Carreta: " + std::to_string(caja->getCodigoCarreta()) + "disponible: " + std::to_string(caja->getEstadoLibre()) + "\"");
        
        
    }
    file << listaCajasString;
    file << "}\n";
}

Cliente* sacarClienteDeCompras() {
    int totalClientes = listaCircular->totalElementos;
    srand((int)time(0));
    int random = (rand() % 100) + 1;
    if (listaCircular->comprobarNumero(random)) {

            Cliente* cliente = listaCircular->borrar(random);
            return cliente;
      
          
    }
    else {
        cout << "El numero "<<random<<" no existe en la lista o no coincide con el id de un cliente "<< endl;
        return nullptr;
    }
    

}

Caja* asignarClienteACaja() {
    restarTiempo();
    Cliente* cliente = colaPagos->pop();
    Caja* aux = listaDoble->cajaInicio;
    bool flag = false;
    while (aux != nullptr) {
        if (aux->getEstadoLibre()) {
            flag = true;
            break;
        }
        aux = aux->siguiente;
    }
    if (flag) {
        aux->setEstadoLibre(false);
        aux->setCodigoCliente(cliente->getNumeroCliente());
        aux->setCodigoCarreta(cliente->getCarreta()->getNumeroCarreta());
        return aux;

    }
    else {
        cout << "Todas las cajas estan ocupadas" << endl;
        return nullptr;
    }

}

void atenderEnCaja(Caja* caja) {

   
    if (caja!=nullptr) {
        if (caja->getTiempoRestante() != 0) {
            cout << "Cliente: " << caja->getCodigoCliente() << " esperando en la caja " << caja->getNumeroCaja() << "." << endl;
        }
        else {
            Carreta* carreta = new Carreta(caja->getCodigoCarreta());
            cout << "Cliente: " << caja->getCodigoCliente() << " atendido en caja " << caja->getNumeroCaja() << "." << endl;
            caja->vaciarCaja();
            guardarCarreta(carreta);
        }
    }
    
   
}

bool guardarCarreta(Carreta* carreta) {
    srand((int)time(0));
    int pila = (rand() % 2) + 1;
    if (pila == 1) {
        pila1->push(carreta);
        cout << "Carreta " << carreta->getNumeroCarreta() << " guardada en la pila 1" << endl;
    }
    else {
        pila2->push(carreta);
        cout << "Carreta " << carreta->getNumeroCarreta() << " guardada en la pila 2" << endl;
    }
    return true;
}

void restarTiempo() {
    Caja* aux = listaDoble->cajaInicio;
    while (aux != nullptr) {
        if (aux->getTiempoRestante()!=0) {
            aux->setTiempoRestante(aux->getTiempoRestante()-1);
        }
        else {
            aux->setEstadoLibre(true);
        }
        aux = aux->siguiente;
    }
   
}