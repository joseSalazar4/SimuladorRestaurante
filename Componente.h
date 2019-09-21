#ifndef COMPONENTE_H
#define COMPONENTE_H

#include "Mediador.h"

class Mediador;
class Componente
{
public:
    Mediador * mediador;

    Componente();
    Componente(Mediador * _mediador): mediador(_mediador){}

    QString getNombre();
    void setMediador(Mediador mediador);
    void click(){
        mediador->notificar(*this,"cocinar");
    }

};

#endif // COMPONENTE_H
