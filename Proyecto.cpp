#include "Proyecto.h"
using namespace std;
Proyecto::Proyecto(const string& nombre) : nombre(nombre) {}

string Proyecto::obtenerNombre() const {
    return nombre;
}

void Proyecto::establecerNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Proyecto::agregarTrabajador(Trabajador* trabajador) {
    trabajadores.push_back(trabajador);
}

std::vector<Trabajador*>& Proyecto::obtenerTrabajadores() {
    return trabajadores;
}

