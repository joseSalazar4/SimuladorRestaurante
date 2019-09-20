//
// Created by mikom on 8/28/2019.
//
#ifndef PASTELERIA_INGREDIENTE_H
#define PASTELERIA_INGREDIENTE_H

#include <string>
#include <iostream>
using namespace std;

struct Ingrediente {

    int cantidad;
    string nombre, unidadMedida;

    Ingrediente(string s, int c, string u){
        nombre = s;
        cantidad = c;
        unidadMedida = u;
    }
    Ingrediente(){
        nombre = unidadMedida = "";
        cantidad = 0;
    }
};


#endif //PASTELERIA_INGREDIENTE_H
