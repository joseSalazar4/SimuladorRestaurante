#include "colacomensales.h"
#include "qdebug.h"

void ColaComensal::encolar (ListaComensales * dato){
    qDebug()<<"Voy a encolar unos comensales";
    largo++;
    qDebug()<<largo;
    if (vacia())
        frente = final = dato;
    else{
        final->siguienteLista = dato;
        final = final->siguienteLista;
    }
    qDebug()<<frente;
}


ListaComensales* ColaComensal::desencolar(){
    ListaComensales * lista = frente;
    largo--;
    if (!vacia()){
        frente = frente->siguienteLista;
        lista->siguienteLista = nullptr;
    }
    return lista;
}

bool ColaComensal::vacia ()
{
    if (frente == nullptr)
        return true;
    else
        return false;
}


ListaComensales * ColaComensal::verFrente()
{
    return frente;
}

