#ifndef COLACLIENTES_H
#define COLACLIENTES_H

#include "listacomensales.h"

class ColaComensal
{
public:
    ListaComensales * frente, * final;
    int maximo = 20, cantMesasActivas = 0;

    ColaComensal()
    {
        frente = final = nullptr;
    }

    // encabezados de funcion
    void encolar (ListaComensales  * dato);
    ListaComensales * desencolar ();
    ListaComensales * verFrente();
    bool vacia();
    void imprimir();
};

#endif // COLACLIENTES_H
