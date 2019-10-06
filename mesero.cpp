#include "mesero.h"

/**
 * @brief Mesero::pedirOrdenes
 * @param mesa to check
 */
void Mesero::pedirOrdenes(Mesa * mesa){
    ComensalThread * comensalThreadAux = mesa->listaComensales->primerNodo;
    comensalThreadAux->mutexComensal->lock();
    Comensal * tmp =  comensalThreadAux->comensal;
    ListaSolicitudes * listaSolicitudes = new ListaSolicitudes();
    for(int i =0; (mesa->listaComensales->largo) > i; i++){
        if(tmp!=nullptr){
            int tipo_pedido=mesa->tipoPedido;
            Solicitud * nueva = new Solicitud();
            tmp = comensalThreadAux->comensal;
            switch(tipo_pedido){
            case 1:
                nueva = tmp->pedirEntrada(tmp->probabilidadPedirEnsalada);
                if(nueva){
                    tmp->llegoComida = true;
                    nueva->tipo = 1;
                    nueva->cliente = tmp->nombre;
                    nueva->mesaDestino = tmp->mesaSentado;
                    nueva->responsable = nombre;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    listaSolicitudes->insertarFinal(nueva);
                    qDebug() << "le meto un plato que tiene esto: "+nueva->plato->nombre;
                }
                else tmp->imagenPersona->setToolTip("Yo no quiero pedir Ensaladas");
                break;
            case 2:
                nueva = tmp->pedirPlatoFuerte(tmp->probabilidadPedirPlatoFuerte);
                if(nueva){
                    tmp->llegoComida = true;
                    nueva->tipo = 2;
                    nueva->cliente = tmp->nombre;
                    nueva->responsable = nombre;
                    nueva->mesaDestino = tmp->mesaSentado;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    listaSolicitudes->insertarFinal(nueva);
                }
                else tmp->imagenPersona->setToolTip("Yo no quiero pedir plato fuerte");
                break;
            case 3:
                nueva = tmp->pedirPostre(tmp->probabilidadPedirPostre);
                if(nueva){
                    tmp->llegoComida = true;
                    nueva->tipo = 3;
                    nueva->cliente = tmp->nombre;
                    nueva->responsable = nombre;
                    nueva->mesaDestino = tmp->mesaSentado;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    listaSolicitudes->insertarFinal(nueva);
                }
                break;
            default:
                nueva = tmp->pedirCuenta();
                if(nueva){
                    nueva->tipo = 4;
                    nueva->cliente = tmp->nombre;
                    nueva->responsable = nombre;
                    nueva->mesaDestino = tmp->mesaSentado;
                    listaSolicitudes->insertarFinal(nueva);
                }
                else tmp->imagenPersona->setToolTip("Yo no quiero pedir postre");
                break;
            }
            comensalThreadAux->comensal->comensalTerminoComer = false;
            comensalThreadAux->mutexComensal->unlock();
            comensalThreadAux = comensalThreadAux->siguiente;
        }
    }
    if(!listaSolicitudes->estaVacia()){
        colaPeticiones->encolar(listaSolicitudes);
        mesa->SolicitandoAsistencia=false;
    }
    mesa->imagen->setToolTip("Se esta pidiendo el tipo de plato #"+QString::number(mesa->tipoPedido));
    mesa->tipoPedido++;
    mesa->SolicitandoAsistencia = false;

}

void Mesero::liberarMesa(Mesa * mesa){
    mesa->vaciarMesa();
}

Mesa * Mesero::revisarMesas(){
    Mesa * tmp = mesas->primerNodo;
    if(tmp == nullptr) return nullptr;
    for(int i =0; i<mesas->largo;i++){
        if(tmp && tmp->tipoPedido==1){
            if (tmp->estaOcupada() && tmp->comensalesTerminaron() ){ //&&tmp->SolicitandoAsistencia && (!tmp->listaComensales->primerNodo->comensal->llegoComida)){
                return tmp;
            }
            tmp = tmp->siguiente;
        }
        else if(tmp && tmp->tipoPedido==2){
            if (tmp->estaOcupada() && tmp->comensalesTerminaron()) {//&&tmp->SolicitandoAsistencia && (!tmp->listaComensales->primerNodo->comensal->llegoComida)){
                return tmp;
            }
            tmp = tmp->siguiente;
        }
        else{
            if (tmp->estaOcupada() && tmp->comensalesTerminaron()){ // tmp->SolicitandoAsistencia && (!tmp->listaComensales->primerNodo->comensal->llegoComida)){
                return tmp;
            }
            tmp = tmp->siguiente;
        }
    }
    return  nullptr;
}

void Mesero::recibirOrden(ListaSolicitudes * sol){
    colaPeticiones->encolar(sol);
}
void Mesero::llevarOrdenCocina(){

}
void Mesero::llevarCuenta(){

}
void Mesero::llevarComida(){

}
void Mesero::llevarPlatosALavar(){

}
