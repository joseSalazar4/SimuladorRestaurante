#ifndef PLATO_H
#define PLATO_H

#include "qstring.h"
struct Plato
{
    Plato * siguiente;

    bool limpio, vacio;
    int ID, precio, tiempoCocina,tiempoLavado;
    QString nombre, tipo;
    Ingredientes Ingredientes[10]; //TODO Hacer listaSimple

    Plato(QString _tipo, QString _nombre,int _ID, int _precio, int _tiempoCocina, int _tiempoLavado,Ingredientes _Ingredientes){
        ID = _ID;
        precio = _precio;
        tiempoCocina= _tiempoCocina;
        tiempoLavado= _tiempoLavado;
        nombre= _nombre;
        tipo= _tipo;
        Ingredientes = _Ingredientes;
    }

};

#endif // PLATO_H
