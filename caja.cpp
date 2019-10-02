#include "caja.h"
#include "qdebug.h"

void Caja::calcularCuenta(){
    int sumaOrdenes = 0;
    if(!colaCuentasPorHacer->vacia()){
        Solicitud * sol = colaCuentasPorHacer->frente->primerNodo;
        while(sol){
            sumaOrdenes+=sol->plato->precio;
            sol = sol->siguiente;
            }

    ListaSolicitudes * listaAux = new ListaSolicitudes;
    Solicitud * sol1 = new Solicitud();
    listaAux->primerNodo = sol1;
    sol1->cuenta =  sumaOrdenes;
    colaCuentasHechas->encolar(listaAux);
    }
    qDebug()<<"\n\nNo hay cuentas y si entro a calcular una\n\n errorrrr ver arriba";
}

