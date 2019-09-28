#include "meserothread.h"

MeseroThread::MeseroThread()
{

}

void MeseroThread::__init__(Mesero* _mesero, QMutex * pmutexCaja,QMutex * pmutexLava,QMutex * pmutexcocina,QMutex * pmutexensalada,QMutex * pmutexpasteleria){
    this->mesero = _mesero;
    this->activo = true;
    this->pausa = false;
    this->mutexCaja = pmutexCaja ;
    this->mutexCocina = pmutexcocina;
    this->mutexEnsaladas = pmutexensalada;
    this->mutexLavaplatos = pmutexLava;
    this->mutexPasteleria = pmutexpasteleria;

}

void MeseroThread::run(){
    while(activo){
        if(mesero->revisarMesas()!= nullptr)
            mesero->pedirOrdenes(mesero->revisarMesas());
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
