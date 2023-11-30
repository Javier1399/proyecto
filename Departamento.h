#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include <vector>
#include "Proyecto.h"
using namespace std;

class Departamento {
private:
    string nombre;
    vector<Proyecto> proyectos;

public:
    Departamento(const string& nombre);
    std::string obtenerNombre() const;
    void establecerNombre(const string& nuevoNombre);
    void agregarProyecto(const Proyecto& proyecto);
    std::vector<Proyecto>& obtenerProyectos();
};

#endif 

