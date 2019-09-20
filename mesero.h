#ifndef MESERO_H
#define MESERO_H
#include <QtCore>
#include <QLabel>
#include <QPixmap>

#include "listamesas.h"
#include "pila.h"
#include "cocina.h"

struct Mesero
{
public:
    bool activo;
    int cantMesas;
    QString nombre;
    ListaMesas * mesas;   //Tendrá la posibilidad de que un mesero atienda a las 20 mesas
    Pila pilaPeticiones;
    Cocina * pasteleria, * ensaladas, * cocina;

    Mesero(int _cantMesas){
        activo = true;
        cantMesas = _cantMesas;

    }

    void pedirOrdenes(Mesa * mesa);
    void llevarComida();
    void llevarCuenta();
    void llevarOrdenCocina();
    void llevarPlatosALavar();
    void recibirOrden(Solicitud * sol);
    Mesa * revisarMesas();
};

#endif // MESERO_H
