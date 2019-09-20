#include "lavaplatosthread.h"

LavaplatosThread::LavaplatosThread()
{

}

void LavaplatosThread::run()
{
    while (activo)
    {
        if(lavaplatos->vacia()) sleep(1);
        else{
            lavar(lavaplatos->desencolar()->plato);
            sleep(tiempoSleep);
        }

        //Cuando se presione el botón de Inactivo
        while (pausa)
            sleep(1);
    }
}

void LavaplatosThread::lavar(Plato * plato){
    int tiempoLimpieza = 0;
    while(tiempoLimpieza<plato->tiempoLavado){
        tiempoLimpieza++;
        sleep(1);
    }
    plato->limpio = true;
    lavaplatos->platosLavados++;
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
