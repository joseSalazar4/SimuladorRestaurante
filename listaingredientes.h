#ifndef LISTAINGREDIENTES_H
#define LISTAINGREDIENTES_H

#include"ingrediente.h"

struct ListaIngredientes
{
    int largo = 0;
    Ingrediente * primerNodo, * ultimoNodo;

    ListaIngredientes(){
        primerNodo = ultimoNodo = nullptr;
    }

    bool estaVacia();
    void insertarFinal(Ingrediente * ingredienteNuevo);
};

#endif // LISTAINGREDIENTES_H
