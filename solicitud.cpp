#include "solicitud.h"

Solicitud::Solicitud(int _destino , int _accion, Plato * _plato)
{
    numeroMesa = 0;
    plato = _plato;
    accion = _accion;
    destino = _destino;
    siguiente = nullptr;
}

Solicitud::Solicitud(){
    numeroMesa = 0;
    plato = nullptr;
    accion = -1;
    destino = -1;
    siguiente = nullptr;
}
