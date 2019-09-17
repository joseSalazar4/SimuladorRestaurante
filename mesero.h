#ifndef MESERO_H
#define MESERO_H
#include <QtCore>
#include <QLabel>
#include <QPixmap>

#include "mesa.h"
#include "pila.h"

struct Mesero
{
public:
    int cantMesas;
    bool activo;
    Mesa * mesas[20];   //Tendrá la posibilidad de que un mesero atienda a las 20 mesas
    QString nombre;
    Pila pilaPeticiones;
    Mesero(int _cantMesas){
        activo = true;
        cantMesas = _cantMesas;
    }

    void pedirOrdenes(int numMesa);
    void llevarComida();
    void llevarCuenta();
    void llevarOrdenCocina();
    void llevarPlatosALavar();
    void recibirOrden(Solicitud * sol);
};

#endif // MESERO_H
