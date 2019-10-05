#include "solicitud.h"

Solicitud::Solicitud(int _destino , int _accion, Plato * _plato)
{
    mesaDestino = "";
    plato = _plato;
    accion = _accion;
    destino = _destino;
    siguiente = nullptr;
}

Solicitud::Solicitud(){
    mesaDestino = "";
    plato = nullptr;
    accion = -1;
    destino = -1;
    siguiente = nullptr;
}
