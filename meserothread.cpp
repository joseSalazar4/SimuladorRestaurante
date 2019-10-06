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
    sleep(4);
    while(activo){
        // We check if any table needs assistance
        mutexMesa->tryLock(10);
        mesa_revisada = mesero->revisarMesas();
        if(mesa_revisada!= nullptr){
            etiqueta->setToolTip("Pidiendo ordenes de mesa #"+mesa_revisada->ID);
            mesero->pedirOrdenes(mesa_revisada);
            if(mesa_revisada->tipoPedido==5) mesa_revisada->tipoPedido = 1;
        }
        mutexMesa->unlock();
        etiqueta->setToolTip("Revisando si hay ordenes por colocar");
        colocarOrden();
        sleep(1);
        llevarOrdenes();

        sleep(tiempoSleep);

        while(pausa){
            this->etiqueta->setToolTip("Tomando un descansito...");
            sleep(1);
        }
    }
}


void MeseroThread::colocarOrden(){
    int tipo_orden;
    if(mesero->colaPeticiones && (!mesero->colaPeticiones->vacia()) && (!mesero->colaPeticiones->frente->estaVacia()) && (mesero->colaPeticiones->frente->primerNodo->plato) && (!mesero->colaPeticiones->frente->primerNodo->plato->vacio)){
        tipo_orden = mesero->colaPeticiones->frente->primerNodo->tipo;
        switch (tipo_orden) {
            case 1:{
                mutexEnsaladas->tryLock(10);
                etiqueta->setToolTip("Colocando una orden en ensaladas");
                mesero->ensaladas->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexEnsaladas->unlock();
                break;
                }

            case 2:{
                mutexCocina->tryLock(10);
                etiqueta->setToolTip("Colocando una orden en la cocina de platos fuertes");
                mesero->cocina->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexCocina->unlock();
                break;
                }

            case 3:{
                mutexPasteleria->tryLock(10);
                etiqueta->setToolTip("Colocando una orden Postres");
                mesero->pasteleria->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexPasteleria->unlock();
                break;
                 }
            case 4:{
                mutexCaja->tryLock(10);
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
}



void MeseroThread::llevarOrdenes(){
    //We check all the kitchens one by one

    //BUSCANDO EN ENSALADAS
    mutexEnsaladas->tryLock(10);
    if (!mesero->ensaladas->colaOrdenesListas->vacia()){
        Solicitud * sol = mesero->ensaladas->colaOrdenesListas->frente->primerNodo;
        while(sol){
            if(sol->responsable == mesero->nombre) break;
            sol = sol->siguiente;
        }
        if(sol){
            etiqueta->setToolTip("Llevando una orden a una mesa");
            QString meseroCorrespondiente = mesero->ensaladas->colaOrdenesListas->frente->primerNodo->responsable;
            QString nombreCliente = mesero->ensaladas->colaOrdenesListas->frente->primerNodo->cliente;
            QString numMesa = mesero->ensaladas->colaOrdenesListas->frente->primerNodo->mesaDestino;
            Mesa * mesaAux =  mesero->mesas->primerNodo;
            Plato * plato = mesero->ensaladas->colaOrdenesListas->frente->primerNodo->plato;
            Solicitud * solicitud = new Solicitud();
            //Ya no debo usar el mutex porque ya no haré nada en la cola tons lo suelto.
            mutexEnsaladas->unlock();
            //bool
            while(mesaAux){
                if(mesaAux->ID == numMesa && meseroCorrespondiente == mesero->nombre) break;
                mesaAux = mesaAux->siguiente;
            }

            ComensalThread * clienteThread = mesaAux->listaComensales->primerNodo;
            while(clienteThread){
                clienteThread->mutexComensal->tryLock(10);
                qDebug()<<"Cliente: "+clienteThread->comensal->nombre+" se compara con"+nombreCliente;
                if(clienteThread->comensal->nombre == nombreCliente){
                    this->sleep(tiempoSleep);
                    etiqueta->setToolTip("Cliente obtuvo su plato");
                    clienteThread->comensal->imagenPersona->setToolTip("Tengo mi comida");
                    clienteThread->comensal->plato = plato;
                    solicitud->tipo = 1;
                    solicitud->plato = plato;
                    solicitud->cliente = nombreCliente;
                    solicitud->mesaDestino = mesaAux->ID;
                    mesaAux->pilaPlatosSucios->push(solicitud);
                    break;
                }
                clienteThread->mutexComensal->unlock();
                clienteThread = clienteThread->siguiente;
            }
            mesero->ensaladas->atendido++;
            mesero->ensaladas->colaOrdenesListas->desencolar();
            return;
        }
    }
    else mutexEnsaladas->unlock();

    //BUSCANDO EN PLATOS FUERTES
    mutexCocina->tryLock(10);
    if(!mesero->cocina->colaOrdenesListas->vacia()){
        Solicitud * sol = mesero->cocina->colaOrdenesListas->frente->primerNodo;
        while(sol){
            if(sol->responsable == mesero->nombre) break;
            sol = sol->siguiente;
        }
        if(sol){
            etiqueta->setToolTip("Llevando una orden a una mesa");
            QString nombreCliente = mesero->cocina->colaOrdenesListas->frente->primerNodo->cliente;
            QString numMesa = mesero->cocina->colaOrdenesListas->frente->primerNodo->mesaDestino;
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
                clienteThread->mutexComensal->tryLock(10);
                if(clienteThread->comensal->nombre == nombreCliente){
                    this->sleep(tiempoSleep);
                    etiqueta->setToolTip("Cliente obtuvo su plato");
                    clienteThread->comensal->plato = (plato);
                    solicitud->plato = plato;
                    solicitud->cliente = nombreCliente;
                    solicitud->mesaDestino = mesaAux->ID;
                    mesaAux->pilaPlatosSucios->push(solicitud);
                    break;
                }
                clienteThread->mutexComensal->unlock();
                clienteThread = clienteThread->siguiente;
            }
            mesero->cocina->atendido++;
            mesero->cocina->colaOrdenesListas->desencolar();
            return;
        }
    }
    else mutexCocina->unlock();

    //BUSCANDO EN PASTELERIA
    mutexPasteleria->tryLock(10);
    if(!mesero->pasteleria->colaOrdenesListas->vacia()){
        Solicitud * sol = mesero->pasteleria->colaOrdenesListas->frente->primerNodo;
        while(sol){
            if(sol->responsable == mesero->nombre) break;
            sol = sol->siguiente;
        }
        if(sol){
            etiqueta->setToolTip("Llevando una orden a una mesa");
            QString nombreCliente = mesero->pasteleria->colaOrdenesListas->frente->primerNodo->cliente;
            QString numMesa = mesero->pasteleria->colaOrdenesListas->frente->primerNodo->mesaDestino;
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
                clienteThread->mutexComensal->tryLock(10);
                if(clienteThread->comensal->nombre == nombreCliente){
                    this->sleep(tiempoSleep);
                    etiqueta->setToolTip("Cliente obtuvo su plato");
                    clienteThread->comensal->plato = plato;
                    solicitud->plato = plato;
                    solicitud->cliente = nombreCliente;
                    solicitud->mesaDestino = mesaAux->ID;
                    mesaAux->pilaPlatosSucios->push(solicitud);
                    break;
                }
                clienteThread->mutexComensal->unlock();
                clienteThread = clienteThread->siguiente;
            }
            mesero->pasteleria->atendido++;
            mesero->pasteleria->colaOrdenesListas->desencolar();
            return;
        }
    }
    else mutexPasteleria->unlock();
}

void MeseroThread::pausar(){
    this->pausa = true;
}

void MeseroThread::continuar(){
    this->pausa = false;
}
