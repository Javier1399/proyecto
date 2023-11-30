#include "Empresa.h"
using namespace std;

void Empresa::agregarDepartamento(const Departamento& departamento) {
    departamentos.push_back(departamento);
}

const vector<Departamento>& Empresa::obtenerDepartamentos() const {
    return departamentos;
}

Departamento& Empresa::obtenerDepartamento(int index) {
    return departamentos[index];
}

vector<Trabajador*>& Empresa::obtenerTrabajadores() {
    return trabajadores;
}

void Empresa::agregarTrabajador(Trabajador* trabajador) {
    trabajadores.push_back(trabajador);
}

void Empresa::eliminarTrabajadores() {
    for (auto trabajador : trabajadores) {
        delete trabajador;
    }
    trabajadores.clear();
}

