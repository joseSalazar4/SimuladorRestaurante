#ifndef Comensal_h
#define Comensal_h

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "qlabel.h"

#include "qstring.h"
#include "solicitud.h"
#include "listaplatos.h"

struct Comensal
{
    QLabel * imagenPersona;
    bool comensalTerminoComer;
    ListaPlatos * listaPlatos;
    Plato * plato = nullptr;
    QString nombre, comidaActual;
    Comensal *  siguiente, * anterior;
    int cuentaAPagar,probabilidadPedir, numeroMesa, tiempoComer1, tiempoComer2;

    Comensal(QString _nombre){
        nombre = _nombre;
        comidaActual = "";
        siguiente = anterior = nullptr;
        listaPlatos = new ListaPlatos();
        comensalTerminoComer = true;
        cuentaAPagar = numeroMesa = probabilidadPedir = 90;
    }

    void dejarMesa();
    void llamarMesero();
    QString generarNombre();
    Solicitud * pedirCuenta();
    Plato * comer(Plato * pla);
    Plato * escogerPlato(int t);
    Solicitud * pedirPostre(int porcentajeACumplir);
    Solicitud * pedirEntrada(int porcentajeACumplir);
    Solicitud * pedirPlatoFuerte(int porcentajeACumplir);

};

#endif // SOLICITUD_H
