#ifndef COCINA_H
#define COCINA_H

#include"qstring.h"
#include "Cocinero.h"
struct Cocina
{
    QString tipo;
    Solicitud * frente;
    Cocinero * cocinero1, * cocinero2, * cocinero3;
    //Usamos solo 1 cocinero para pasteleria y ensaladas

    Cocina(QString _tipo, Cocinero * c1){
        tipo = _tipo;
        cocinero1 = c1;
        frente = nullptr;
        cocinero2 = cocinero3 = nullptr;

   }

    Cocina(QString _tipo, Cocinero * c1, Cocinero * c2, Cocinero * c3){
        tipo = _tipo;
        cocinero1 = c1;
        cocinero2 = c2;
        cocinero3 = c3;
        frente = nullptr;

   }

   void encolar (Solicitud * dato);
   Solicitud * desencolar ();
   Solicitud * verFrente();
   bool vacia();

};

#endif // COCINA_H
