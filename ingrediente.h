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
    string nombre;

    Ingrediente(string s, int c){
        nombre = s;
        cantidad = c;
    }

    Ingrediente(){
        cantidad = 0;
        nombre = "";
    }
};


#endif //PASTELERIA_INGREDIENTE_H
