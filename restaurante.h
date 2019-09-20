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

    Restaurante(){
        caja = new Caja();
        mesas = new ListaMesas();
        meseros = new ListaMeseros();
        lavaplatos = new Lavaplatos();
        principal = new Cocina("fuerte");
        principal = new Cocina("ensaladas");
        principal = new Cocina("pasteleria");
    }

    void Iniciar();
};

#endif // RESTAURANTE_H
