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


QString GeneradorPersonasThread::generarNombre(){
    QString random;
    random = arrayNombres[rand()%10];
    return random;
}
void GeneradorPersonasThread::__init__(ManejadorComensales * maneja, QMutex * mutex, int t1, int t2){
    pausa = false;
    activo = true;
    tiempoGeneracion = t1;
    tiempoGeneracion1 = t2;
    this->mutexManejador = mutex;
    this->manejadorComensales = maneja;
    srand(static_cast<unsigned int>(time(nullptr)));

}

GeneradorPersonasThread::GeneradorPersonasThread()
{
    tiempoGeneracion = tiempoGeneracion1 = cantidadGenerada = 0;
}

ListaComensales * GeneradorPersonasThread::generarPersonas(int personasCreadas ){

    ListaComensales * lista = new ListaComensales();

    for(int i = 0; i < personasCreadas; i++){
        QString nombre = generarNombre()+QString::number(i);
        qDebug()<<nombre;
        Comensal * nuevo = new Comensal(nombre);
        lista->insertarFinal(nuevo);
    }
    qDebug()<<lista->largo;
    qDebug()<<personasCreadas;
    return lista;
}

void GeneradorPersonasThread::run(){

    while(activo){
        int sleepTime = QRandomGenerator::global()->bounded(tiempoGeneracion, tiempoGeneracion1);
        int personasCreadas = QRandomGenerator::global()->bounded(1, 6);
        cantPersonasGeneradas->setText(QString::number(personasCreadas));
        cantPersonasGeneradas->repaint();

        mutexManejador->lock();
        manejadorComensales->colaClientesEnEspera->encolar(generarPersonas(personasCreadas));
        if(listaMesas->buscarDisponibilidad() && manejadorComensales->colaClientesEnEspera->frente != nullptr)
            listaMesas->buscarDisponibilidad()->listaComensales = manejadorComensales->colaClientesEnEspera->desencolar();
        mutexManejador->unlock();

        sleep(static_cast<unsigned int>(sleepTime));
        while(pausa) sleep(1);
    }
}


void GeneradorPersonasThread::pausar(){
    this->pausa = true;
}

void GeneradorPersonasThread::continuar(){
    this->pausa = false;
}
