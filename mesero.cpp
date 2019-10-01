#include "mesero.h"

/**
 * @brief Mesero::pedirOrdenes
 * @param mesa to check
 */
void Mesero::pedirOrdenes(Mesa * mesa){
    Comensal * tmp = mesa->listaComensales->primerNodo;
    ListaSolicitudes * listaSolicitudes = new ListaSolicitudes();
    for(int i =0; (mesa->listaComensales->largo) > i; i++){
        if(tmp!=nullptr){
            int tipo_pedido=mesa->tipoPedido;
            Solicitud * nueva;
            switch(tipo_pedido){
            case 1:
                nueva = tmp->pedirEntrada(tmp->probabilidadPedir);
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;

                    listaSolicitudes->insertarFinal(nueva);
                }
                break;
            case 2:
                nueva = tmp->pedirPlatoFuerte(tmp->probabilidadPedir);
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    listaSolicitudes->insertarFinal(nueva);
                }
                break;
            case 3:
                nueva = tmp->pedirPostre(tmp->probabilidadPedir);
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                }
                break;
            default:
                nueva = tmp->pedirCuenta();
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    listaSolicitudes->insertarFinal(nueva);
                }
                mesa->tipoPedido = 1;
                break;
            }

            tmp = tmp->siguiente;
        }
    }
    mesa->pedirAsistencia=false;
    colaPeticiones->encolar(listaSolicitudes);
    mesa->tipoPedido++;
}

void Mesero::liberarMesa(Mesa * mesa){
    mesa->vaciarMesa();

}

/**
 * Method that check if any table needs assistance
 * @brief Mesero::revisarMesas
 * @return the table that needs assistance
 */
Mesa * Mesero::revisarMesas(){
    Mesa * tmp = mesas->primerNodo;
    if(tmp == nullptr) return nullptr;
    for(int i =0; i<mesas->largo;i++){
        if (tmp->estaOcupada() && tmp->pedirAsistencia){
            return tmp;
        }
        tmp = tmp->siguiente;
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
