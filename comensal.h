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
    ListaPlatos * listaPlatos;
    QString nombre, comidaActual;
    Comensal *  siguiente, * anterior;
    int cuentaAPagar,probabilidadPedir, numeroMesa;

    Comensal(QString _nombre){
        nombre = _nombre;
        comidaActual = "";
        siguiente = anterior = nullptr;
        cuentaAPagar = numeroMesa = probabilidadPedir = 90;
    }

    bool comer();
    void dejarMesa();
    void llamarMesero();
    QString generarNombre();
    Solicitud * pedirCuenta();
    Plato * escogerPlato(int t);
    Solicitud * pedirPostre(int porcentajeACumplir);
    Solicitud * pedirEntrada(int porcentajeACumplir);
    Solicitud * pedirPlatoFuerte(int porcentajeACumplir);

};

#endif // SOLICITUD_H
