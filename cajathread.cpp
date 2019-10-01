#include "cajathread.h"

CajaThread::CajaThread()
{

}

void CajaThread::__init__(QLabel* _etiqueta, Caja * _caja, QMutex * mutx){
    caja = _caja;
    this->activo = true;
    this->pausa = false;
    this->mutexCaja = mutx;
    imagenCaja = _etiqueta;
    imagenCaja->setToolTip("No hay cuentas por calcular");
}

void CajaThread::run(){
    while(activo){
        mutexCaja->lock();
        if(!caja->vacia()){
            int mesaActual = caja->frente->numeroMesa;  //Tons si hay solicitudes que saque todas hasta que haya otra mesa
            this->imagenCaja->setToolTip("Calculando cuenta de la mesa #"+QString::number(mesaActual));
            while(caja->desencolar()->numeroMesa == mesaActual){
                caja->frente->cuenta = caja->calcularCuenta();
                //llamarMesero ^ DARLE cuenta
                sleep(tiempoSleep);
            }
        }
        mutexCaja->unlock();
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
