#include "mesero.h"


void Mesero::pedirOrdenes(int numMesa){
    int probabilidadPedir = 0;
    for(int i =0;mesas[numMesa] ;i++){
        if(mesas[numMesa]->comensal1){
           mesas[numMesa]->comensal1->pedirEntrada(probabilidadPedir);
        }
        else{

        }

    }
}

void Mesero::recibirOrden(Solicitud * sol){
    pilaPeticiones.push(sol);
}
void Mesero::llevarOrdenCocina(){

}
void Mesero::llevarCuenta(){

}
void Mesero::llevarComida(){

}
void Mesero::llevarPlatosALavar(){

}

bool Mesero::revisar(){
    for(int i =0; i<cantMesas;i++){
        if (mesas[i]->estaOcupada() && mesas[i]->pedirAsistencia){

        }
    }
}
