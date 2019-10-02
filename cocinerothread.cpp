#include "cocinerothread.h"

void CocineroThread::run()
{
    while (activo)
    {
        mutex->lock();
        if(cocina->colaOrdenesNoListas->verFrente()){
            Solicitud * orden = cocina->colaOrdenesNoListas->desencolar()->primerNodo;
            Plato * plato = orden->plato;
            while(orden){
            tiempoSleep = static_cast <unsigned int> (plato->tiempoCocina);
            while(0<tiempoSleep){
                tiempoRestante->setText(QString::number(tiempoSleep));
                tiempoRestante->repaint();
                tiempoSleep--;
                sleep(1);
            }
            cocinar(plato);
            sleep(1);
            orden = orden->siguiente;
            }
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
        ListaSolicitudes * listaAux = new ListaSolicitudes();
        //Generamos una lista pa que devuelva esa papa
        listaAux->primerNodo = cocinero->colocarOrdenLista(plato);
        cocina->colaOrdenesListas->encolar(listaAux);
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
