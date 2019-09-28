#include "cocinathread.h"

CocinaThread::CocinaThread()
{

}

Cocinero * CocinaThread::buscarCocineroDisponible(){
    if(cocinero1) return cocinero1;
    else if(cocinero2) return cocinero2;
    else if(cocinero3) return cocinero3;
    else return nullptr;
}

void CocineroThread::pausar()
{
    this->pausa = true;
}

void CocineroThread::continuar()
{
    this->pausa = false;
}
