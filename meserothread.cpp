#include "meserothread.h"

void MeseroThread::__init__(Mesero* _mesero,ListaMesas * mesas, QMutex * pmutexCaja,QMutex * pmutexLava,QMutex * pmutexcocina,QMutex * pmutexensalada,QMutex * pmutexpasteleria, QMutex * pmutexMesa){
    this->activo = true;
    this->pausa = false;
    this->mesero = _mesero;
    this->mesero->mesas = mesas;
    this->mesero->activo = true;
    this->mutexCaja = pmutexCaja;
    this->mutexMesa = pmutexMesa;
    this->mutexCocina = pmutexcocina;
    this->mutexLavaplatos = pmutexLava;
    mesero->colaPeticiones = new Cola();
    this->mutexEnsaladas = pmutexensalada;
    this->mutexPasteleria = pmutexpasteleria;
    this->mesero->cantMesas = mesero->mesas->largo;
}

void MeseroThread::run(){
    Mesa * mesa_revisada;
    while(activo){

        // We check if any table needs assistance
        mutexMesa->lock();
        mesa_revisada=mesero->revisarMesas();
        if(mesa_revisada!= nullptr){
            etiqueta->setToolTip("Pidiendo ordenes de mesa #"+mesa_revisada->ID);
            qDebug()<<"Pidiendo ordenes de mesa #"+mesa_revisada->ID;
            mesero->pedirOrdenes(mesa_revisada);
            if(mesa_revisada->tipoPedido==5) mesa_revisada->tipoPedido = 1;
        }
        mutexMesa->unlock();

        // Then we give that order to the corresponding place (kitchen or cashier)
        etiqueta->setToolTip("Revisando si hay ordenes por colocar");
        colocarOrden();
        sleep(tiempoSleep);
        llevarOrdenes();
        sleep(tiempoSleep);
    }
}


void MeseroThread::colocarOrden(){
    int tipo_orden;
    if(!mesero->colaPeticiones && !mesero->colaPeticiones->vacia() && mesero->colaPeticiones->frente->primerNodo && mesero->colaPeticiones->frente->primerNodo->plato){
        tipo_orden = mesero->colaPeticiones->frente->primerNodo->tipo;
        switch (tipo_orden) {
            case 1:{
                mutexEnsaladas->lock();
                qDebug()<<"VAMOS A PONER UN ensalada";
                etiqueta->setToolTip("Colocando una orden en ensaladas");
                mesero->ensaladas->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexEnsaladas->unlock();
                break;
            }

            case 2:{
                mutexCocina->lock();

                qDebug()<<"VAMOS A PONER UN PLATO FUere";
                etiqueta->setToolTip("Colocando una orden en la cocina de platos fuertes");
                mesero->cocina->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexCocina->unlock();
                break;
            }

            case 3:{
                mutexPasteleria->lock();
                qDebug()<<"VAMOS A PONER UN postre";
                etiqueta->setToolTip("Colocando una orden Postres");
                mesero->pasteleria->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexPasteleria->unlock();
                break;
            }

            case 4:{
                mutexCaja->lock();
                etiqueta->setToolTip("Colocando una orden en la caja");
                mesero->caja->colaCuentasPorHacer->encolar(mesero->colaPeticiones->desencolar());
                mutexCaja->unlock();
                break;
            }
            default:{
                qDebug()<<"Hubo una orden con tipo pedido erroneo";
                break;
            }
        }
    }
    qDebug()<<"No hay nada en la cola";
}



void MeseroThread::llevarOrdenes(){
    //We check all the kitchens one by one

    mutexEnsaladas->lock();
    if (!mesero->ensaladas->colaOrdenesListas->vacia()){
        etiqueta->setToolTip("Llevando una orden a una mesa");
        QString nombreCliente = mesero->ensaladas->colaOrdenesListas->frente->primerNodo->cliente;
        int numMesa = mesero->ensaladas->colaOrdenesListas->frente->primerNodo->numeroMesa;
        Mesa * mesaAux =  mesero->mesas->primerNodo;
        Plato * plato = mesero->ensaladas->colaOrdenesListas->frente->primerNodo->plato;
        Solicitud * solicitud = new Solicitud();

        //Ya no debo usar el mutex porque ya no haré nada en la cola tons lo suelto.
        mutexEnsaladas->unlock();

        while(mesaAux){
            if(mesaAux->ID == numMesa) break;
            mesaAux = mesaAux->siguiente;
        }

        ComensalThread * clienteThread = mesaAux->listaComensales->primerNodo;

        while(clienteThread){
            clienteThread->mutexComensal->lock();
            if(clienteThread->comensal->nombre == nombreCliente){
                this->sleep(tiempoSleep);
                etiqueta->setToolTip("Cliente obtuvo su plato");
                clienteThread->comensal->plato = plato;
                solicitud->plato = plato;
                mesaAux->pilaPlatosSucios->push(solicitud);
                break;
            }
            clienteThread = clienteThread->siguiente;
        }
        clienteThread->mutexComensal->lock();
        return;
    }
    else mutexEnsaladas->unlock();

    mutexCocina->lock();
    if(!mesero->cocina->colaOrdenesListas->vacia()){
        etiqueta->setToolTip("Llevando una orden a una mesa");
        QString nombreCliente = mesero->cocina->colaOrdenesListas->frente->primerNodo->cliente;
        int numMesa = mesero->cocina->colaOrdenesListas->frente->primerNodo->numeroMesa;
        Mesa * mesaAux =  mesero->mesas->primerNodo;
        Plato * plato = mesero->cocina->colaOrdenesListas->frente->primerNodo->plato;
        Solicitud * solicitud = new Solicitud();

        //Ya no debo usar el mutex porque ya no haré nada en la cola tons lo suelto.
        mutexCocina->unlock();

        while(mesaAux){
            if(mesaAux->ID == numMesa) break;
            mesaAux = mesaAux->siguiente;
        }

        ComensalThread * clienteThread = mesaAux->listaComensales->primerNodo ;
        while(clienteThread){
            clienteThread->mutexComensal->lock();
            if(clienteThread->comensal->nombre == nombreCliente){
                this->sleep(tiempoSleep);
                etiqueta->setToolTip("Cliente obtuvo su plato");
                clienteThread->comensal->plato = (plato);
                solicitud->plato = plato;
                mesaAux->pilaPlatosSucios->push(solicitud);
                break;
            }
            clienteThread = clienteThread->siguiente;
        }
        clienteThread->mutexComensal->lock();
        return;
    }
    else mutexCocina->unlock();

    mutexPasteleria->lock();
    if(!mesero->pasteleria->colaOrdenesListas->vacia()){
        etiqueta->setToolTip("Llevando una orden a una mesa");
        QString nombreCliente = mesero->pasteleria->colaOrdenesListas->frente->primerNodo->cliente;
        int numMesa = mesero->pasteleria->colaOrdenesListas->frente->primerNodo->numeroMesa;
        Mesa * mesaAux =  mesero->mesas->primerNodo;
        Plato * plato = mesero->pasteleria->colaOrdenesListas->frente->primerNodo->plato;
        Solicitud * solicitud = new Solicitud();

        //Ya no debo usar el mutex porque ya no haré nada en la cola tons lo suelto.
        mutexPasteleria->unlock();

        while(mesaAux){
            if(mesaAux->ID == numMesa) break;
            mesaAux = mesaAux->siguiente;
        }
        ComensalThread * clienteThread = mesaAux->listaComensales->primerNodo ;
        while(clienteThread){
            clienteThread->mutexComensal->lock();
            if(clienteThread->comensal->nombre == nombreCliente){
                this->sleep(tiempoSleep);
                etiqueta->setToolTip("Cliente obtuvo su plato");
                clienteThread->comensal->plato = plato;
                solicitud->plato = plato;
                mesaAux->pilaPlatosSucios->push(solicitud);
                break;
            }
            clienteThread = clienteThread->siguiente;
        }
        clienteThread->mutexComensal->lock();
        return;
    }
    else mutexPasteleria->unlock();
}

void MeseroThread::pausar(){
    this->pausa = true;
}

void MeseroThread::continuar()
{
    this->pausa = false;
}
