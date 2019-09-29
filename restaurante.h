#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "listamesas.h"
#include "cajathread.h"
#include "listameseros.h"
#include "CocineroThread.h"
#include "lavaplatosthread.h"
#include "listameserothreads.h"
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
    MeseroThread meserosThread[20];
    ListaMeseroThreads * listaMeserosThread;
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread generadorPersonas;
    Cocina * principal, * pasteleria, * ensaladas;
    MeseroThread mesero1,mesero2,mesero3,mesero4,mesero5,mesero6,mesero7,mesero8,mesero9,mesero10,mesero11,mesero12,mesero13,mesero14,mesero15,mesero16,mesero17,mesero18,mesero19,mesero20;
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
        generadorPersonas.__init__(manejadorComensales,mute, tiempoGen1, tiempoGen2);
        generadorPersonas.listaMesas = this->mesas;
        generadorPersonas.start();

        for(int i = 0;i<cantidadMesas;i++){
            Mesa * mesaAux = new Mesa(QString::number(i+1));
            mesas->insertarFinal(mesaAux);
        }

        qDebug()<<"Ya creo mesas";

        for(int i = 0;i<cantidadMeseros;i++){
            qDebug()<<cantidadMeseros;
            Mesero * mesero = new Mesero(cantMesasMesero);
            qDebug()<<"inserto el mesero al final THREAD ACA CREO QUE SE CAYO ";
            meseros->insertarFinal(mesero);
        }

//        mesero1.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero1.start();
//        mesero2.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero2.start();
//        mesero3.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero3.start();
//        mesero4.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero4.start();
//        mesero5.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero5.start();
//        mesero6.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero6.start();
//        mesero7.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero7.start();
//        mesero8.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero8.start();
//        mesero9.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero9.start();
//        mesero10.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero10.start();
//        mesero11.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero11.start();
//        mesero12.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero12.start();
//        mesero13.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero13.start();
//        mesero14.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero14.start();
//        mesero15.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero15.start();
//        mesero16.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero16.start();
//        mesero17.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero17.start();
//        mesero18.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero18.start();
//        mesero19.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero19.start();
//        mesero20.__init__(mesero,mutexPasteleria,mutexEnsaladas,mutexCocinaFuerte,mutexLavaplatos,mutexCaja);
//        mesero20.start();

        qDebug()<<"voy a LAVAAAAAAAAR";

        lavaplatosThread.__init__(lavaplatos, _mutexLavaplatos);
        qDebug()<<"sali de  lavarplats";

    }

    void Iniciar();
    MeseroThread * crearNuevo();
    bool asignarMesa(ListaComensales * lista);   ///ASIGNE MESAS PIENSE QUIEN LLAMA EL METODO A DONDE VEA WINDOW.CPP HKUNA MATATA


};

#endif // RESTAURANTE_H
