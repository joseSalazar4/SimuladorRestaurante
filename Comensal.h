#ifndef Comensal_h
#define Comensal_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "qstring.h"
#include "Solicitud.h"
#include "mesero.h"
struct Comensal
{
    Mesa * mesa;
    int cuentaAPagar;
    Mesero * meseroActivo;
    QString nombre, comidaActual;
    Comensal(QString _nombre, Mesa * _mesa){
        //TODO no se que variables debe llevar un comensal.
        QString nombre = _nombre;
        mesa = _mesa;
        meseroActivo = mesa->meseroActivo;
    }

    bool comer();
    void dejarMesa();
    void pedirCuenta();
    void llamarMesero();
    Solicitud * pedirPostre(int porcentajeACumplir);
    Solicitud * pedirEntrada(int porcentajeACumplir);
    Solicitud * pedirPlatoFuerte(int porcentajeACumplir);

};

#endif // SOLICITUD_H
