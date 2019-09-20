#ifndef PLATO_H
#define PLATO_H

#include "qstring.h"
#include "listaingredientes.h"
struct  Plato
{
    bool limpio, vacio;
    QString nombre, tipo;
    Plato * siguiente, * anterior;
    ListaIngredientes * Ingredientes; //TODO Hacer listaSimple
    int ID, precio, tiempoCocina,tiempoLavado;

    Plato(){
        siguiente = anterior = nullptr;
    }

    Plato(QString _tipo, QString _nombre,int _ID, int _precio, int _tiempoCocina, int _tiempoLavado,ListaIngredientes * _Ingredientes){
        ID = _ID;
        tipo= _tipo;
        nombre= _nombre;
        precio = _precio;
        tiempoCocina= _tiempoCocina;
        tiempoLavado= _tiempoLavado;
        Ingredientes = _Ingredientes;
        siguiente = anterior = nullptr;
    }
};

#endif // PLATO_H
