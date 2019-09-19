#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "lavaplatos.h"
#include "cocina.h"
#include "caja.h"
#include "listameseros.h"
#include "listamesas.h"

class Restaurante
{
    ListaMesas mesas;
    ListaMeseros meseros;
    Caja caja;
    Cocina principal, pasteleria, ensaladas;
    Lavaplatos lavaplatos;

    Restaurante();
    void Iniciar();
};

#endif // RESTAURANTE_H
