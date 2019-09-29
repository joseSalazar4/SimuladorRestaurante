#ifndef MESERO_H
#define MESERO_H
#include <QtCore>
#include <QLabel>
#include <QPixmap>

#include "cola.h"
#include "cocina.h"
#include "componente.h"
#include "listamesas.h"
#include "lavaplatos.h"

struct Mesero {

public:
    bool activo;
    int cantMesas;
    QString nombre;
    Cola * colaPeticiones;
    Lavaplatos * lavaplatos;
    Mesero * siguiente, * anterior;
    Cocina * pasteleria, * ensaladas, * cocina;
    ListaMesas * mesas;   //Tendrá la posibilidad de que un mesero atienda a las 20 mesas

    Mesero(int _cantMesas){
        activo = true;
        cantMesas = _cantMesas;

    }


    void notificar(Componente, QString);


    void llevarComida();
    void llevarCuenta();
    Mesa * revisarMesas();
    void llevarOrdenCocina();
    void llevarPlatosALavar();
    void pedirOrdenes(Mesa * mesa);
    void recibirOrden(Solicitud * sol);
};

#endif // MESERO_H
