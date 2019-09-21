#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "lavaplatos.h"
#include "cocina.h"
#include "caja.h"
#include "listameseros.h"
#include "listamesas.h"

class Restaurante
{
    Caja * caja;
    ListaMesas * mesas;
    ListaMeseros * meseros;
    Lavaplatos * lavaplatos;
    Cocina * principal, * pasteleria, * ensaladas;

    Restaurante(int cantidadCocineros){
        caja = new Caja();
        mesas = new ListaMesas();
        meseros = new ListaMeseros();
        lavaplatos = new Lavaplatos();

        Cocinero * cocineroPostres = new Cocinero("postres");
        Cocinero * cocineroEnsaladas = new Cocinero("postres");

        principal = new Cocina("fuerte");
        principal = new Cocina("ensaladas", cocineroEnsaladas);
        principal = new Cocina("pasteleria", cocineroPostres);


        if(cantidadCocineros == 3){
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            Cocinero * cocineroFuerte2 = new Cocinero("fuerte");
            Cocinero * cocineroFuerte3= new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
            principal->cocinero1 = cocineroFuerte2;
            principal->cocinero1 = cocineroFuerte3;
        }
        else if (cantidadCocineros == 2){
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            Cocinero * cocineroFuerte2 = new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
            principal->cocinero1 = cocineroFuerte2;
        }
        else{
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
        }
    }

    void Iniciar();
};

#endif // RESTAURANTE_H
