#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "listamesas.h"
#include "cajathread.h"
#include "listameseros.h"
#include "cocinerothread.h"
#include "lavaplatosthread.h"
#include "meserothread.h"
#include "manejadorcomensales.h"
#include "generadorpersonasthread.h"

struct Restaurante {
public:

    Caja * caja;
    ListaMesas * mesas;
    CajaThread cajaThread;
    ListaMeseros * meseros;
    Lavaplatos * lavaplatos;
    LavaplatosThread lavaplatosThread;
    MeseroThread * arrayMeserosThread[20];
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread generadorPersonas;
    Cocina * principal, * pasteleria, * ensaladas;
    int cantMeseros, cantCocineros, cantMesas, cantMesasPorMesero,tiempoGen1,tiempoGen2,mesasSobrantes = 0;
    QMutex * mutexPasteleria , *mutexCocinaFuerte , * mutexEnsaladas, * mutexLavaplatos, * mutexCaja, * mutexManejador;

    Restaurante(int cantidadCocineros,int cantidadMeseros, int cantidadMesas, int cantMesasMesero,int tiempoGen1,int tiempoGen2, QMutex * _mutexCaja, QMutex *  _mutexLavaplatos,QMutex * _mutexCocina, QMutex * _mutexEnsaladas,QMutex*  _mutexPasteleria, QMutex * _mutexManejador){

        this->mutexCaja = _mutexCaja;
        this->mutexCocinaFuerte = _mutexCocina;
        this->mutexEnsaladas = _mutexEnsaladas;
        this->mutexManejador = _mutexManejador;
        this->mutexPasteleria = _mutexPasteleria;
        this->mutexLavaplatos = _mutexLavaplatos;


        caja = new Caja();
        mesas = new ListaMesas();
        meseros = new ListaMeseros();
        lavaplatos = new Lavaplatos();
        manejadorComensales = new ManejadorComensales();

        Cocinero * cocineroPostres = new Cocinero("postres");
        Cocinero * cocineroEnsaladas = new Cocinero("postres");

        principal = new Cocina("fuerte");
        pasteleria = new Cocina("pasteleria", cocineroPostres);
        ensaladas = new Cocina("ensaladas", cocineroEnsaladas);


        if(cantidadCocineros == 3){
            Cocinero * cocineroFuerte3= new Cocinero("fuerte");
            Cocinero * cocineroFuerte2 = new Cocinero("fuerte");
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
            principal->cocinero1 = cocineroFuerte2;
            principal->cocinero1 = cocineroFuerte3;

        }

        else if (cantidadCocineros == 2){
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            Cocinero * cocineroFuerte2 = new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
            principal->cocinero1 = cocineroFuerte2;
        }

        else{
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
        }

        cantMesas = cantidadMesas;
        cantMeseros = cantidadMeseros;

        for(int i = 0;i<cantidadMeseros;i++){

        }
        generadorPersonas.__init__(manejadorComensales,mutexManejador, tiempoGen1, tiempoGen2);
        generadorPersonas.listaMesas = this->mesas;
        generadorPersonas.start();

        if(cantMesas%cantMeseros != 0) mesasSobrantes = cantMesas-(cantMesasMesero*(cantMeseros-1));

        if(mesasSobrantes == 0){
            for(int i = 0;i<cantidadMeseros;i++){
                Mesero * mesero = new Mesero(cantMesasMesero);
                MeseroThread * meseroThread = new MeseroThread();
                ListaMesas * listaMesasAsignada = new ListaMesas();

                for(int j = 0;j<cantMesasMesero;j++){
                    Mesa * mesaAux = new Mesa("Mesa #"+QString::number(j+1));
                    //insertamos en la lista total de mesas
                    mesas->insertarFinal(mesaAux);
                    //insertamos en la lista que se asignará a cada mesero y que tiene las mesas que le corresponden
                    listaMesasAsignada->insertarFinal(mesaAux);
                }

                meseroThread->__init__(mesero, listaMesasAsignada, mutexPasteleria, mutexEnsaladas, mutexCocinaFuerte, mutexLavaplatos,mutexCaja, mutexManejador);
                qDebug()<<"init al mesero #"+QString::number(i);
                arrayMeserosThread[i] = meseroThread;
                meseros->insertarFinal(mesero);
            }

            qDebug()<<"pongo a correr los hilos de mesero";
            for(int i = 0;i<cantidadMeseros;i++){
                arrayMeserosThread[i]->mesero->nombre = "Mesero #"+QString::number(i);
                arrayMeserosThread[i]->start();
            }

        }

        qDebug()<<"init al thread de lavarplatos";
        lavaplatosThread.__init__(lavaplatos, _mutexLavaplatos);
        lavaplatosThread.start();
    }
    void Iniciar();
    bool asignarMesa(ListaComensales * lista);   ///ASIGNE MESAS PIENSE QUIEN LLAMA EL METODO A DONDE VEA WINDOW.CPP HKUNA MATATA


};

#endif // RESTAURANTE_H
