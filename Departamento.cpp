#include "Departamento.h"

Departamento::Departamento(std::string nombre) : nombre(nombre) {}

void Departamento::agregarProyecto(Proyecto proyecto) {
    proyectos.push_back(proyecto);
}
