#include "cocinerothread.h"

void CocineroThread::run()
{
    while (activo)
    {
        mutex->lock();
        if(cocina->verFrente()){
            Plato * plato  = cocina->desencolar()->plato;
            tiempoSleep = static_cast <unsigned int> (plato->tiempoCocina);
            while(0<tiempoSleep){
                tiempoSleep--;
                tiempoRestante->setText(QString::number(tiempoSleep));
                tiempoRestante->repaint();
                sleep(1);
            }
            cocinar(plato);
            sleep(1);
        }
        mutex->unlock();
        sleep(1);

        //Cuando se presione el botón de Inactivo
        while (pausa) sleep(1);
    }
}

void CocineroThread:: __init__(QMutex *, QLabel *, Cocinero *, Cocina *){

}

void CocineroThread::cocinar(Plato * plato){
    if(plato){
        plato->vacio=false;
        plato->limpio = false;
        cocina->encolar(cocinero->colocarOrdenLista(plato));
        sleep(tiempoSleep);
    }
    qDebug()<<"ËL PLATO ESTABA VACÍOOOOOOOOOOOOOOOOOOOOOO";
}

void CocineroThread::pausar()
{
    this->pausa = true;
}

void CocineroThread::continuar()
{
    this->pausa = false;
}
