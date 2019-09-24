#include "generadorpersonasthread.h"
#include "qdebug.h"


int GeneradorPersonasThread::generadorNumRandom(int rango1, int rango2){
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = (rand() % rango1) + (rango2-rango1);
    return r;
}

int GeneradorPersonasThread::generadorNumRandom(int rango1){
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = (rand() % rango1)+1;
    return r;
}

void GeneradorPersonasThread::__init__(){
    pausa = false;
    activo = true;

}

GeneradorPersonasThread::GeneradorPersonasThread()
{
    tiempoGeneracion = tiempoGeneracion1 = cantidadGenerada = 0;
}

ListaComensales * GeneradorPersonasThread::generarPersonas(){
    ListaComensales * lista = new ListaComensales();
    int personasCreadas = generadorNumRandom(1,6);
    qDebug()<< personasCreadas;
    for(int i = 0; i < personasCreadas; i++){
        Comensal * nuevo = new Comensal("Marco"+QString::number(i));
        lista->insertarFinal(nuevo);
    }
    return lista;
}

void GeneradorPersonasThread::run(){
    while(activo){
        qDebug()<< "entre al RUUUN";
        manejadorComensales->semaforo.release();
        manejadorComensales->semaforo.acquire();
        qDebug()<< "Pasé el acquire";
        manejadorComensales->colaClientesEnEspera->encolar(generarPersonas());
        manejadorComensales->semaforo.release();
        sleep(1);
        while(pausa){
            sleep(1);
        }
    }
}


void GeneradorPersonasThread::pausar()
{
    this->pausa = true;
}

void GeneradorPersonasThread::continuar()
{
    this->pausa = false;
}
