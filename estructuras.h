#include <cstdlib>
#include <iostream>

using namespace std;




// estructura nodo para lista simple
struct Nodo {
       int dato; // parte de datos
       
       Nodo* siguiente;// puntero para enlazar nodos
       // constructor
       
       Nodo(int d) 
       {
                dato = d; // asigna los datos 
                siguiente = NULL; // sig es null
       }
 
      void imprimir();
       
};


struct Pila {
       // solo con pN es suficiente
       Nodo *tope;
       
       Pila()
       {
                    tope = NULL;
       }
       
       // encabezados de funcion
       void push (int dato);
       Nodo* pop (void);
       Nodo* peek(void);
       bool empty(void);
       void imprimir(void);
};

struct Cola {
       // solo con pN es suficiente
       Nodo *frente;
       
       Cola()
       {
            frente = NULL;
       }
       
       // encabezados de funcion
       void encolar (int dato);
       Nodo* desencolar (void);
       Nodo* verFrente(void);
       bool vacia(void);
       void imprimir(void);
};

