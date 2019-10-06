#include "cocinerothread.h"

void CocineroThread::run(){
    while (activo){
        mutexCocinero->tryLock(4);
        if(!cocina->colaOrdenesNoListas->vacia()){
            Solicitud * orden = cocina->colaOrdenesNoListas->desencolar()->primerNodo;
            mutexCocinero->unlock();
            while(orden){
                Plato * plato = orden->plato;
                tiempoSleep = static_cast <unsigned int> (plato->tiempoCocina);
                mutexCocinero->tryLock(4);
                panelInfo->setText("Se han atendido: "+QString::number(cocina->atendido)+"\nSe esta cocinando:\n "+plato->nombre);
                mutexCocinero->unlock();
                while(0<tiempoSleep){
                    infoCocina->setText("Cocinando...\n Tiempo Restante: "+QString::number(+tiempoSleep));
                    tiempoSleep--;
                    sleep(1);
                }
                mutexCocinero->tryLock(10);
                cocinar(plato, orden->cliente, orden->mesaDestino,orden->responsable);
                mutexCocinero->unlock();
                sleep(1); //EL SLEEPTIME CORRECTO DEBE PONERSE ANTES DE LA REVISION
                orden = orden->siguiente;

                //If the button is pressed the chef needs to just do ONE order then change that
                while (pausa) {
                    sleep(1);
                    infoCocina->setText("Tomando un descansito...");
                }
            }
        }
        else{
            infoCocina->setText("Sin ordenes por cocinar");
            panelInfo->setText("Se han atendido: "+QString::number(cocina->atendido)+"\nNo se esta cocinando");
            mutexCocinero->unlock();
        }
        sleep(4);
        //Cuando se presione el botón de Inactivo
        while (pausa) {
            sleep(1);
            infoCocina->setText("Tomando un descansito...");
        }
    }
}

void CocineroThread::__init__(QMutex * mutex1, QLabel * imagen1,QLabel * infoCoci ,QLabel * infoGrande, Cocinero * cocinero1, Cocina * cocina1){
    panelInfo = infoGrande;
    this->cocina = cocina1;
    this->mutexCocinero = mutex1;
    this->imagenChef = imagen1;
    this->cocinero = cocinero1;
    this->infoCocina = infoCoci;
    infoCocina->show();
    pausa = false;
    activo = true;
}

void CocineroThread::cocinar(Plato * plato, QString cliente, QString mesa, QString responsable){
    if(plato){
        plato->vacio=false;
        plato->limpio = false;
        ListaSolicitudes * listaAux = new ListaSolicitudes();
        //Generamos una lista pa que devuelva esa papa
        listaAux->primerNodo = cocinero->colocarOrdenLista(plato);
        listaAux->primerNodo->cliente = cliente;
        listaAux->primerNodo->mesaDestino = mesa;
        listaAux->primerNodo->responsable = responsable;
        cocina->colaOrdenesListas->encolar(listaAux);
        sleep(tiempoSleep);
    }
    else qDebug()<<"ËL PLATO ESTABA VACÍOOOOOOOOOOOOOOOOOOOOOO";
}

void CocineroThread::pausar()
{
    this->mutexCocinero->tryLock(10);
    this->pausa = true;
    mutexCocinero->unlock();
}

void CocineroThread::continuar()
{
    this->mutexCocinero->tryLock(10);
    this->pausa = false;
    mutexCocinero->unlock();

}
