#include "cajathread.h"

CajaThread::CajaThread()
{

}

void CajaThread::__init__(Caja * _caja, QMutex * mutx, QLabel * img, QLabel * cajaInf){
    caja = _caja;
    this->activo = true;
    this->pausa = false;
    this->mutexCaja = mutx;
    imagenCaja = img;
    cajaInfo = cajaInf;
    cajaInfo->setText("No hay cuentas por calcular");
}

void CajaThread::run(){
    while(activo){
        mutexCaja->tryLock(10);
        if(!caja->colaCuentasPorHacer->vacia()){
            QString mesaActual = caja->colaCuentasPorHacer->frente->primerNodo->mesaDestino;  //Tons si hay solicitudes que saque todas hasta que haya otra mesa
            cajaInfo->setText("Calculando cuenta de la mesa #"+mesaActual);
            while(caja->colaCuentasPorHacer->desencolar()->primerNodo->mesaDestino == mesaActual){
                caja->calcularCuenta();
                sleep(tiempoSleep);
            }
        }
        cajaInfo->setText("No hay cuentas");
        mutexCaja->unlock();
        while(pausa){
            cajaInfo->setText("Tomando un descansito...");
            sleep(1);
        }
    }
}

void CajaThread::pausar(){
    this->pausa = true;
}

void CajaThread::continuar(){
    mutexCaja->tryLock(10);
    this->pausa = false;
    mutexCaja->unlock();
}

void CajaThread::establecerSleep(unsigned int nuevoTemp){
    tiempoSleep = nuevoTemp;
}
