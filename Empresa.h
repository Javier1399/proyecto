#ifndef EMPRESA_H
#define EMPRESA_H

#include <vector>
#include "Departamento.h"
#include "Trabajador.h"

using namespace std;

class Empresa {
private:
    vector<Departamento> departamentos;
    vector<Trabajador*> trabajadores;

public:
    void agregarDepartamento(const Departamento& departamento);
    const vector<Departamento>& obtenerDepartamentos() const;
    Departamento& obtenerDepartamento(int index);
    vector<Trabajador*>& obtenerTrabajadores();
    void agregarTrabajador(Trabajador* trabajador);
    void eliminarTrabajadores();

};

#endif
