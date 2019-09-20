#ifndef LISTAPLATOS_H
#define LISTAPLATOS_H

#include"plato.h"

struct ListaPlatos
{
    int largo;
    Plato * siguiente, * anterior, * primerNodo, * ultimoNodo;
    ListaPlatos(){
        primerNodo = ultimoNodo = nullptr;
    }

    bool estaVacia();
    Plato * buscarPlatoRandomTipo(int tipo);
    void insertarFinal(QString _tipo, QString _nombre,int _ID, int _precio, int _tiempoCocina, int _tiempoLavado,ListaIngredientes * _Ingredientes);
};

#endif // LISTAPLATOS_H
