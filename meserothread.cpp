#include "meserothread.h"

MeseroThread::MeseroThread()
{

}

void MeseroThread::__init__(QLabel* _etiqueta, Mesero* _mesero){
    this->mesero = _mesero;
    this->etiqueta = _etiqueta;
    this->activo = true;
    this->pausa = false;
    this->semaforo.release();
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
