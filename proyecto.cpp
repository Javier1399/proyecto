#include "proyecto.h"

Proyecto::Proyecto(std::string nombre) : nombre(nombre) {}

void Proyecto::agregarTrabajador(Trabajador* trabajador) {
    trabajadores.push_back(trabajador);
}




