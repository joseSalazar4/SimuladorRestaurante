#ifndef Comensal_h
#define Comensal_h

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "qlabel.h"

#include "qstring.h"
#include "solicitud.h"
#include "listaplatos.h"
#include "QRandomGenerator"

struct Comensal
{
    QLabel * imagenPersona;
    bool comensalTerminoComer;
    ListaPlatos * listaPlatos;
    Plato * plato = nullptr;
    QString nombre, comidaActual, mesaSentado;
    Comensal *  siguiente, * anterior;
    int cuentaAPagar,probabilidadPedirPostre,probabilidadPedirPlatoFuerte,probabilidadPedirEnsalada, numeroMesa, tiempoComer1Fuerte, tiempoComer2Fuerte,tiempoComerEnsalada1,tiempoComerEnsalada2,tiempoComerPostre1,tiempoComerPostre2;

    Comensal(QString _nombre, ListaPlatos*listaPlatos): listaPlatos(listaPlatos){
        nombre = _nombre;
        comidaActual = "";
        siguiente = anterior = nullptr;
        listaPlatos = new ListaPlatos();
        comensalTerminoComer = true;
        cuentaAPagar = numeroMesa = 1;
        probabilidadPedirPostre = probabilidadPedirEnsalada = probabilidadPedirPlatoFuerte = 90;
    }

    void dejarMesa();
    QString generarNombre();
    Solicitud * pedirCuenta();
    Plato * comer(Plato * pla);
    Plato * escogerPlato(int t);
    Solicitud * pedirPostre(int porcentajeACumplir);
    Solicitud * pedirEntrada(int porcentajeACumplir);
    Solicitud * pedirPlatoFuerte(int porcentajeACumplir);

};

#endif // SOLICITUD_H
