#ifndef MEDIADOR_H
#define MEDIADOR_H

#include "qstring.h"
#include "componente.h"

class Componente;

class Mediador
{
public:
    Mediador();
    void notificar(Componente comp, QString evento );
};

#endif // MEDIADOR_H
