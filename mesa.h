#ifndef MESA_H
#define MESA_H

#include <qstring.h>
#include "Comensal.h"
struct Mesa
{
    Mesa * siguiente;
    QString ID;
    int ocupada; //1 es Ocupada 0 es disponible -1 no está disponible del todo
    int tipoPedido; //1 Entrada 2 Plato fuerte 3 postre 4 cuenta
    Comensal * comensal1, * comensal2, * comensal3, * comensal4, * comensal5, * comensal6;
    Mesero * meseroActivo;
    bool pedirAsistencia = true;

    Mesa(QString _id, Mesero * mesero){
        ID = _id;
        meseroActivo = mesero;
        comensal1 = comensal2 = comensal3 = comensal4 = comensal5 = comensal6 = nullptr;
    }

    bool estaOcupada();
};

#endif // MESA_H
