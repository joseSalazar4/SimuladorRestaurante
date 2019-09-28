#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "listamesas.h"
#include "cajathread.h"
#include "listameseros.h"
#include "CocineroThread.h"
#include "lavaplatosthread.h"
#include "manejadorcomensales.h"
#include "generadorpersonasthread.h"

struct Restaurante
{
public:
    Caja * caja;
    ListaMesas * mesas;
    CajaThread cajaThread;
    ListaMeseros * meseros;
    Lavaplatos * lavaplatos;
    int cantMeseros, cantMesas;
    LavaplatosThread lavaplatosThread;
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread generadorPersonas;
    Cocina * principal, * pasteleria, * ensaladas;
    QMutex * mutexPasteleria , *mutexCocinaFuerte , * mutexEnsaladas, * mutexLavaplatos, * mutexCaja, * mutexManejador;

    Restaurante(int cantidadCocineros,int cantidadMeseros, int cantidadMesas, int cantMesasMesero, QMutex * _mutexCaja, QMutex *  _mutexLavaplatos,QMutex * _mutexCocina, QMutex * _mutexEnsaladas,QMutex*  _mutexPasteleria, QMutex * _mutexManejador){

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
        generadorPersonas.__init__(manejadorComensales,mutexManejador);
        generadorPersonas.start();

        for(int i = 0;i<cantidadMesas;i++){
            Mesa * mesaAux = new Mesa(QString::number(i+1));
            mesas->insertarFinal(mesaAux);
        }

        qDebug()<<"Ya creo mesas";

        for(int i = 0;i<cantidadMeseros;i++){
            qDebug()<<cantidadMeseros;
            Mesero * mesero = new Mesero(cantMesasMesero);
            MeseroThread meseroT;
            qDebug()<<"antes del Init ";

            meseroT.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);

            meseros->insertarFinal(mesero);
            qDebug()<<"inserto el mesero al final ";
            meseroT.start();
            qDebug()<<"le dio strt ";

            qDebug()<<"inicio el thread de mesero"+QString::number(i);
        }

        qDebug()<<"voy a lavarplats";

        lavaplatosThread.__init__(lavaplatos, _mutexLavaplatos);
        qDebug()<<"sali de  lavarplats";

    }
    void Iniciar();
    bool asignarMesa(ListaComensales * lista);   ///ASIGNE MESAS PIENSE QUIEN LLAMA EL METODO A DONDE VEA WINDOW.CPP HKUNA MATATA


};

#endif // RESTAURANTE_H
