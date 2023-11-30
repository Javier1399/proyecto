#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include <vector>
#include "Proyecto.h"

class Departamento {
public:
    std::string nombre;
    std::vector<Proyecto> proyectos;

    Departamento(std::string nombre);

    void agregarProyecto(Proyecto proyecto);
};

#endif // DEPARTAMENTO_H
