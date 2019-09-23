#include "Solicitud.h"

Solicitud::Solicitud(int _destino , int _accion, Plato * _plato)
{
    plato = _plato;
    accion = _accion;
    destino = _destino;
    siguiente = nullptr;
}

Solicitud::Solicitud(){
    plato = nullptr;
    accion = -1;
    destino = -1;
    siguiente = nullptr;
}
