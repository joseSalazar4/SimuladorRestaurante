#include "comensalthread.h"

ComensalThread::ComensalThread()
{

}

void ComensalThread::pausar()
{
    this->pausa = true;
}

void ComensalThread::continuar()
{
    this->pausa = false;
}

void ComensalThread::__init__(QMutex * mutexCom, QLabel * label, Comensal * comens){
    imagenComensal = label;
    mutexComensal = mutexCom;
    comensal = comens;

}
