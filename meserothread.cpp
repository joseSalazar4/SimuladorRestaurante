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
        if(mesa_revisada!= nullptr)
           mesero->pedirOrdenes(mesa_revisada);
        mutexMesa->unlock();

        // Then we give that order to the corresponding place (kitchen or cashier)
        colocarOrden();
        llevarOrdenes();

        qDebug()<<mesero->nombre+" reportandose al trabajo";
        sleep(tiempoSleep);
    }
}


void MeseroThread::colocarOrden(){
    int tipo_orden;
    if(mesero->colaPeticiones->vacia() && mesero->colaPeticiones->frente && mesero->colaPeticiones->frente->primerNodo && mesero->colaPeticiones->frente->primerNodo->plato->vacio){
        tipo_orden = mesero->colaPeticiones->frente->primerNodo->tipo;
        switch (tipo_orden) {
            case 1:{
                mutexEnsaladas->lock();
                mesero->ensaladas->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexEnsaladas->unlock();
                break;
            }

            case 2:{
                mutexCocina->lock();
                mesero->cocina->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexCocina->unlock();
                break;
            }

            case 3:{
                mutexPasteleria->lock();
                mesero->pasteleria->colaOrdenesNoListas->encolar(mesero->colaPeticiones->desencolar());
                mutexPasteleria->unlock();
                break;
            }

            case 4:{
                mutexCaja->lock();
                mesero->caja->colaCuentasPorHacer->encolar(mesero->colaPeticiones->desencolar());
                mutexCaja->unlock();
                break;
            }
            default:{

                break;
            }
        }
    }
}



void MeseroThread::llevarOrdenes(){
    //We check all the kitchens one by one

    mutexEnsaladas->lock();
    if (!mesero->ensaladas->colaOrdenesListas->vacia()){
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

        Comensal * cliente = mesaAux->listaComensales->primerNodo ;
        while(cliente){
            if(cliente->nombre == nombreCliente){
                this->sleep(tiempoSleep);
                cliente->comer(plato);
                solicitud->plato = plato;
                mesaAux->pilaPlatosSucios->push(solicitud);
                break;
            }
            cliente = cliente->siguiente;
        }
    }
    else mutexEnsaladas->unlock();

    mutexCocina->lock();
    if(!mesero->cocina->colaOrdenesListas->vacia()){
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

        Comensal * cliente = mesaAux->listaComensales->primerNodo ;
        while(cliente){
            if(cliente->nombre == nombreCliente){
                this->sleep(tiempoSleep);
                cliente->comer(plato);
                solicitud->plato = plato;
                mesaAux->pilaPlatosSucios->push(solicitud);
                break;
            }
            cliente = cliente->siguiente;
        }
    }
    else mutexCocina->unlock();

    mutexPasteleria->lock();
    if(!mesero->pasteleria->colaOrdenesListas->vacia()){
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

        Comensal * cliente = mesaAux->listaComensales->primerNodo ;
        while(cliente){
            if(cliente->nombre == nombreCliente){
                this->sleep(tiempoSleep);
                cliente->comer(plato);
                solicitud->plato = plato;
                mesaAux->pilaPlatosSucios->push(solicitud);
                break;
            }
            cliente = cliente->siguiente;
        }
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
