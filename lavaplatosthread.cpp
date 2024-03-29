#include "lavaplatosthread.h"

LavaplatosThread::LavaplatosThread()
{

}

void LavaplatosThread::__init__(Lavaplatos * lava , QMutex * mut){
    this->lavaplatos = lava;
    this->mutex = mut;
}

void LavaplatosThread::run()
{
    while (activo)
    {
        mutex->lock();
        if(lavaplatos->vacia()){
            sleep(1);
            mutex->unlock();
        }
        else{
            lavar(lavaplatos->desencolar()->plato);
            mutex->unlock();
            sleep(tiempoSleep);
        }

        //Cuando se presione el botón de Inactivo
        while (pausa)
            sleep(1);
    }
}

void LavaplatosThread::lavar(Plato * plato){
    while(plato->tiempoLavado>0){
        sleep(1);
    }
    plato->limpio = true;
    lavaplatos->platosLavados++;

    Solicitud * nueva = new Solicitud();
    nueva->plato = plato;
    inventarioOrdenes->encolar(nueva);
}

void LavaplatosThread::pausar()
{
    this->pausa = true;
}

void LavaplatosThread::continuar()
{
    this->pausa = false;
}

void LavaplatosThread::establecerSleep(unsigned int nuevoTemp){
    tiempoSleep = nuevoTemp;
}
