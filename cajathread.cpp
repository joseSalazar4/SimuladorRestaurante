#include "cajathread.h"

CajaThread::CajaThread()
{

}

void CajaThread::__init__(Caja * _caja, QMutex * mutx, QLabel * img){
    caja = _caja;
    this->activo = true;
    this->pausa = false;
    this->mutexCaja = mutx;
    imagenCaja = img;
    imagenCaja->setToolTip("No hay cuentas por calcular");
}

void CajaThread::run(){
    while(activo){
        mutexCaja->lock();
        if(!caja->colaCuentasPorHacer->vacia()){
            int mesaActual = caja->colaCuentasPorHacer->frente->primerNodo->numeroMesa;  //Tons si hay solicitudes que saque todas hasta que haya otra mesa
            imagenCaja->setToolTip("Calculando cuenta de la mesa #"+QString::number(mesaActual));
            while(caja->colaCuentasPorHacer->desencolar()->primerNodo->numeroMesa == mesaActual){
                caja->calcularCuenta();
                sleep(tiempoSleep);
            }
        }
        mutexCaja->unlock();
        imagenCaja->setToolTip("Esperando a que una cuenta llegue");
        while(pausa) sleep(1);
    }
}

void CajaThread::pausar(){
    this->pausa = true;
}

void CajaThread::continuar()
{
    this->pausa = false;
}

void CajaThread::establecerSleep(unsigned int nuevoTemp){
    tiempoSleep = nuevoTemp;
}
