#include "cocinerothread.h"

void CocineroThread::run()
{
    while (activo){

        mutexCocinero->lock();
        if(cocina->colaOrdenesNoListas->verFrente()){
            Solicitud * orden = cocina->colaOrdenesNoListas->desencolar()->primerNodo;
            mutexCocinero->unlock();
            while(orden){
            Plato * plato = orden->plato;
            tiempoSleep = static_cast <unsigned int> (plato->tiempoCocina);
            while(0<tiempoSleep){
                infoCocina->setText("Cocinando... \n Tiempo Restante: "+QString::number(+tiempoSleep));
                tiempoSleep--;
                sleep(1);
            }
            cocinar(plato);
            sleep(1);
            orden = orden->siguiente;
            }
        }
        else{
            //TODO: METER 3 IMAGENES DE CHEFS PARA LA FUERTE
        //qDebug()<<"La cocina no tiene comida por hacer";
        infoCocina->setText("Sin ordenes por cocinar");
        mutexCocinero->unlock();
        }
        sleep(1);

        //Cuando se presione el botón de Inactivo
        while (pausa) {
            sleep(1);
            infoCocina->setText("Tomando un descansito...");
        }
    }
}

void CocineroThread:: __init__(QMutex * mutex1, QLabel * imagen1,QLabel * infoCoci , Cocinero * cocinero1, Cocina * cocina1){
    this->cocina = cocina1;
    this->mutexCocinero = mutex1;
    this->imagenChef = imagen1;
    this->cocinero = cocinero1;
    this->infoCocina = infoCoci;
    infoCocina->show();
    pausa = false;
    activo = true;
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
    else qDebug()<<"ËL PLATO ESTABA VACÍOOOOOOOOOOOOOOOOOOOOOO";
}

void CocineroThread::pausar()
{
    this->pausa = true;
}

void CocineroThread::continuar()
{
    this->pausa = false;
}
