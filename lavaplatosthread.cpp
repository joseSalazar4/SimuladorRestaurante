#include "lavaplatosthread.h"

LavaplatosThread::LavaplatosThread()
{

}

void LavaplatosThread::__init__(Lavaplatos * lava , QMutex * mut){
    this->lavaplatos = lava;
    this->mutex = mut;
    pausa = false;
    activo = true;
}

void LavaplatosThread::run()
{
    while (activo)
    {
        mutex->tryLock(10);
        if(lavaplatos->vacia()){
            sleep(1);
            lavaplatosInfo->setText("No hay platos por lavar");
            mutex->unlock();
        }
        else{
            //lavar
            lavar(lavaplatos->desencolar()->plato);
            lavaplatosInfo->setText("Lavando...");
            mutex->unlock();
            sleep(tiempoSleep);
        }

        //Cuando se presione el botón de Inactivo
        while (pausa){
            sleep(1);
            lavaplatosInfo->setText("Tomando un descansito...");

        }
    }
}

void LavaplatosThread::lavar(Plato * plato){
    int tiempo = plato->tiempoLavado;
    while(tiempo>0){
        lavaplatosInfo->setText(QString::number(tiempo));
        tiempo--;
        sleep(1);
    }
    plato->limpio = true;
    lavaplatos->platosLavados++;

    //llevar control de que se ha cocinado.
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
