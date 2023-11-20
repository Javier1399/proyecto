#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>
#include <vector>
#include "trabajador.h"

class Proyecto {
public:
    std::string nombre;
    std::vector<Trabajador*> trabajadores;

    Proyecto(std::string nombre);

    void agregarTrabajador(Trabajador* trabajador);
};

#endif 
