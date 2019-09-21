#ifndef MEDIADOR_H
#define MEDIADOR_H

#include "qstring.h"
#include "componente.h"



class Mediador
{
public:
    Mediador();
    void notificar( QString evento );
};

#endif // MEDIADOR_H
