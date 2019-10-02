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



        qDebug()<<mesero->nombre+" reportandose al trabajo";
        sleep(tiempoSleep);
    }
}


void MeseroThread::pausar(){
    this->pausa = true;
}

void MeseroThread::continuar()
{
    this->pausa = false;
}

void MeseroThread::colocarOrden(){
    int tipo_orden;
    if(mesero->colaPeticiones && mesero->colaPeticiones->frente && mesero->colaPeticiones->frente->primerNodo && mesero->colaPeticiones->frente->primerNodo->plato->vacio){
        tipo_orden = mesero->colaPeticiones->frente->primerNodo->tipo;
        switch (tipo_orden) {
            case 1:{
                mutexEnsaladas->lock();
                ListaSolicitudes * listaOrdenes =  mesero->colaPeticiones->desencolar();
                Solicitud * tmp = listaOrdenes->primerNodo;
                for(int i = 0; i<listaOrdenes->largo;i++){
                    mesero->ensaladas->encolar(tmp);
                    tmp = tmp->siguiente;
                }
                mutexEnsaladas->unlock();
                break;
            }

            case 2:{
                mutexCocina->lock();
                ListaSolicitudes * listaOrdenes =  mesero->colaPeticiones->desencolar();
                Solicitud * tmp = listaOrdenes->primerNodo;
                for(int i = 0; i<listaOrdenes->largo;i++){
                    mesero->cocina->encolar(tmp);
                    tmp = tmp->siguiente;
                }
                mutexCocina->unlock();
                break;
            }

            case 3:{
                mutexPasteleria->lock();
                ListaSolicitudes * listaOrdenes =  mesero->colaPeticiones->desencolar();
                Solicitud * tmp = listaOrdenes->primerNodo;
                for(int i = 0; i<listaOrdenes->largo;i++){
                    mesero->pasteleria->encolar(tmp);
                    tmp = tmp->siguiente;
                }
                mutexPasteleria->unlock();
                break;
            }

            case 4:{
                mutexCaja->lock();
                ListaSolicitudes * listaOrdenes =  mesero->colaPeticiones->desencolar();
                Solicitud * tmp = listaOrdenes->primerNodo;
                for(int i = 0; i<listaOrdenes->largo;i++){
                    mesero->caja->encolar(tmp);
                    tmp = tmp->siguiente;
                }
                mutexCaja->unlock();
                break;
            }

            default:{

                break;
            }
        }
    }
}
