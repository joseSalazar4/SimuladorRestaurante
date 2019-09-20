#ifndef LISTAMESAS_H
#define LISTAMESAS_H

#include"mesa.h"
class ListaMesas
{
public:
    Mesa * primerNodo;
    ListaMesas(){
        primerNodo = nullptr;
    }
};

#endif // LISTAMESAS_H
