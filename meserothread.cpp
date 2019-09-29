#include "meserothread.h"

void MeseroThread::__init__(Mesero* _mesero, QMutex * pmutexCaja,QMutex * pmutexLava,QMutex * pmutexcocina,QMutex * pmutexensalada,QMutex * pmutexpasteleria, QMutex * pmutexMesa){
    this->activo = true;
    this->pausa = false;
    this->mesero = _mesero;
    this->mutexCaja = pmutexCaja;
    this->mutexMesa = pmutexMesa;
    this->mutexCocina = pmutexcocina;
    this->mutexLavaplatos = pmutexLava;
    this->mutexEnsaladas = pmutexensalada;
    this->mutexPasteleria = pmutexpasteleria;
}

void MeseroThread::run(){
    while(activo){
        mutexMesa->lock();
        if(mesero->revisarMesas()!= nullptr)
            mesero->pedirOrdenes(mesero->revisarMesas());
        mutexMesa->unlock();
        sleep(1);
    }
}


void MeseroThread::pausar(){
    this->pausa = true;
}

void MeseroThread::continuar()
{
    this->pausa = false;
}
