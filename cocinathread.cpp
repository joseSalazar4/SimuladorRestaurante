#include "cocinathread.h"



void CocinaThread::__init__(QMutex * pmutexCocina,Cocina * pCocina){
    this->cocina = pCocina;
    this->pausa = false;
    this->activo = true;
    this->mutexCocina = pmutexCocina;
}

Cocinero * CocinaThread::buscarCocineroDisponible(){
    if(cocinero1) return cocinero1;
    else if(cocinero2) return cocinero2;
    else if(cocinero3) return cocinero3;
    else return nullptr;
}

void CocinaThread::pausar()
{
    this->pausa = true;
}

void CocinaThread::continuar()
{
    this->pausa = false;
}
