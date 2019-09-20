#ifndef COCINA_H
#define COCINA_H

#include "Solicitud.h"
#include"qstring.h"
#include "Cocinero.h"
struct Cocina
{
    QString tipo;
    Solicitud * frente;
    Cocinero * cocinero1, * cocinero2, * cocinero3;
    //Usamos solo 1 cocinero para pasteleria y ensaladas

    Cocina(QString _tipo){
        frente = nullptr;
        tipo = _tipo;
        if(tipo!="fuerte") cocinero2 = cocinero3 = nullptr;

   }

   void encolar (Solicitud * dato);
   Solicitud * desencolar ();
   Solicitud * verFrente();
   bool vacia();

};

#endif // COCINA_H
