#ifndef COLACLIENTES_H
#define COLACLIENTES_H

#include "listacomensales.h"

class ColaComensal
{
public:
    ListaComensales * frente;
    int maximo = 20, cantMesasActivas = 0;

    ColaComensal()
    {
         frente = nullptr;
    }

    // encabezados de funcion
    void encolar (ListaComensales  * dato);
    ListaComensales * desencolar ();
    ListaComensales * verFrente();
    bool vacia();
    void imprimir();
};

#endif // COLACLIENTES_H
