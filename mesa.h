#ifndef MESA_H
#define MESA_H

#include <qstring.h>
#include "Comensal.h"
struct Mesa
{
    QString ID;
    bool Ocupada;
    int tipoPedido; //1 Entrada 2 Plato fuerte 3 postre 4 cuenta
    Comensal * comensal1, * comensal2, * comensal3, * comensal4, * comensal5, * comensal6;
    Mesero * meseroActivo;
    Mesa(QString _id, Mesero * mesero){
        meseroActivo = mesero;
        ID = _id;
       comensal1 = comensal2 = comensal3 = comensal4 = comensal5 = comensal6 = nullptr;
    }
    bool estaOcupada();
};

#endif // MESA_H
