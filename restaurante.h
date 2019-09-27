#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "caja.h"
#include "cocina.h"
#include "lavaplatos.h"
#include "listamesas.h"
#include "listameseros.h"
#include "manejadorcomensales.h"
#include "generadorpersonasthread.h"

struct Restaurante
{
public:
    Caja * caja;
    ListaMesas * mesas;
    ListaMeseros * meseros;
    Lavaplatos * lavaplatos;
    int cantMeseros, cantMesas;
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread generadorPersonas;
    Cocina * principal, * pasteleria, * ensaladas;

    Restaurante(int cantidadCocineros,int cantidadMeseros, int cantidadMesas, int cantMesasMesero){
        caja = new Caja();
        mesas = new ListaMesas();
        meseros = new ListaMeseros();
        lavaplatos = new Lavaplatos();
        manejadorComensales = new ManejadorComensales();

        Cocinero * cocineroPostres = new Cocinero("postres");
        Cocinero * cocineroEnsaladas = new Cocinero("postres");

        principal = new Cocina("fuerte");
        principal = new Cocina("pasteleria", cocineroPostres);
        principal = new Cocina("ensaladas", cocineroEnsaladas);


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

        generadorPersonas.__init__(manejadorComensales);

        generadorPersonas.start();

        for(int i = 0;i<cantidadMeseros;i++){
            Mesero * mesero = new Mesero(cantMesasMesero);
            MeseroThread * meseroT = new MeseroThread();
            meseroT->__init__(mesero);
            meseros->insertarFinal(meseroT);
            //crear los hilos de los meseros y darles start fuera del while a todos
        }
        for(int i = 0;i<cantidadMesas;i++){
            Mesa * mesaAux = new Mesa(QString::number(i));
            mesas->insertarFinal(mesaAux);

    }
}
    void Iniciar();
    bool asignarMesa(ListaComensales * lista);


};

#endif // RESTAURANTE_H
