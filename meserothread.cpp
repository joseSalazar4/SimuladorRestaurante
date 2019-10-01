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
    int tipo_orden;
    Mesa*mesa_revisada;
    while(activo){

        // We check if any table needs assistance
        mutexMesa->lock();
        mesa_revisada=mesero->revisarMesas();
        if(mesa_revisada!= nullptr)
           mesero->pedirOrdenes(mesa_revisada);
        mutexMesa->unlock();

        // Then we ...
        // todo: entregar orden en la cocina respectiva
        tipo_orden=mesero->colaPeticiones->frente->primerNodo->tipo;
        switch (tipo_orden) {
        case 1:
            mutexEnsaladas->lock();
            // ...
            mutexEnsaladas->unlock();
            break;
        case 2:
            mutexCocina->lock();
            // ...
            mutexCocina->unlock();
            break;
        case 3:
            mutexPasteleria->lock();
            // ...
            mutexPasteleria->unlock();
            break;
        case 4:
            mutexCaja->lock();
            // ...
            mutexCaja->unlock();
            break;
        default:
            // ...
            break;
        }
        qDebug()<<mesero->nombre+" reportandose al trabajo";
        sleep(10);
    }
}


void MeseroThread::pausar(){
    this->pausa = true;
}

void MeseroThread::continuar()
{
    this->pausa = false;
}
