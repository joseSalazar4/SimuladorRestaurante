#ifndef COCINA_H
#define COCINA_H

#include"qstring.h"
#include "cocinero.h"
#include "cola.h"
struct Cocina
{
    QString tipo;
    Cola * colaOrdenesNoListas, * colaOrdenesListas;
    Cocinero * cocinero1, * cocinero2, * cocinero3;
    //Usamos solo 1 cocinero para pasteleria y ensaladas

    Cocina(QString _tipo, Cocinero * c1){
        tipo = _tipo;
        cocinero1 = c1;
        colaOrdenesNoListas = new Cola();
        colaOrdenesListas= new Cola() ;
        cocinero2 = cocinero3 = nullptr;

    }
    Cocina(QString _tipo){
        tipo = _tipo;
        colaOrdenesNoListas = new Cola();
        colaOrdenesListas= new Cola() ;
    }

    Cocina(QString _tipo, Cocinero * c1, Cocinero * c2, Cocinero * c3){
        tipo = _tipo;
        cocinero1 = c1;
        cocinero2 = c2;
        cocinero3 = c3;
        colaOrdenesNoListas = new Cola();
        colaOrdenesListas= new Cola() ;
   }

};

#endif // COCINA_H
