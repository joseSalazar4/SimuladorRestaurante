#include"CocineroThread.h"


CocineroThread::CocineroThread(){
    //El constructor no permite los enlaces que deseamos
}
void CocineroThread::run()
{
    while (activo)
    {
        if(cocinero->cocina->vacia()) sleep(1);
        else{
            cocinar(cocinero->recogerPedido());
            sleep(1);
        }

        //Cuando se presione el botón de Inactivo
        while (pausa)
            sleep(1);
    }
}

void CocineroThread::cocinar(Plato * plato){
    if(plato){
        sleep(static_cast<unsigned int>(plato->tiempoCocina));
        plato->vacio=false;
        cocinero->colocarOrdenLista(plato);
        sleep(tiempoSleep);
    }

}

void CocineroThread::pausar()
{
    this->pausa = true;
}

void CocineroThread::continuar()
{
    this->pausa = false;
}


void CocineroThread::establecerSleep(unsigned int nuevoTemp){
    tiempoSleep = nuevoTemp;
}
