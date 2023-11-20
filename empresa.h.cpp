#ifndef EMPRESA_H
#define EMPRESA_H

#include <vector>
#include "departamento.h"

class Empresa {
public:
    std::vector<Departamento> departamentos;
    std::vector<Trabajador*> trabajadores;

    void agregarDepartamento(Departamento departamento);
};

#endif


