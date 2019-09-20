#ifndef Comensal_h
#define Comensal_h

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "mesero.h"
#include "qstring.h"
#include "Solicitud.h"
#include "listaplatos.h"

struct Comensal
{
    Mesero * meseroActivo;
    ListaPlatos * listaPlatos;
    QString nombre, comidaActual;
    Comensal * siguiente, * anterior;
    int cuentaAPagar,probabilidadPedir;

    Comensal(QString _nombre) nombre : _nombre;

    bool comer();
    void dejarMesa();
    void pedirCuenta();
    void llamarMesero();
    Plato * escogerPlato();
    Solicitud * pedirPostre(int porcentajeACumplir);
    Solicitud * pedirEntrada(int porcentajeACumplir);
    Solicitud * pedirPlatoFuerte(int porcentajeACumplir);
};

#endif // SOLICITUD_H
