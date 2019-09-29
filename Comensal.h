#ifndef Comensal_h
#define Comensal_h

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "qstring.h"
#include "Solicitud.h"
#include "listaplatos.h"

struct Comensal
{
    ListaPlatos * listaPlatos;
    QString nombre, comidaActual;
    Comensal *  siguiente, * anterior;
    int cuentaAPagar,probabilidadPedir, numeroMesa;

    Comensal(QString _nombre){
        nombre = _nombre;
        comidaActual = "";
        siguiente = anterior = nullptr;
        cuentaAPagar = numeroMesa = probabilidadPedir = 0;
    }

    bool comer();
    void dejarMesa();
    void llamarMesero();
    Solicitud * pedirCuenta();
    Plato * escogerPlato(int t);
    Solicitud * pedirPostre(int porcentajeACumplir);
    Solicitud * pedirEntrada(int porcentajeACumplir);
    Solicitud * pedirPlatoFuerte(int porcentajeACumplir);
    QString generarNombre();

};

#endif // SOLICITUD_H
