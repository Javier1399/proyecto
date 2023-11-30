#include "Departamento.h"
using namespace std;
Departamento::Departamento(const string& nombre) : nombre(nombre) {}

string Departamento::obtenerNombre() const {
    return nombre;
}

void Departamento::establecerNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Departamento::agregarProyecto(const Proyecto& proyecto) {
    proyectos.push_back(proyecto);
}

vector<Proyecto>& Departamento::obtenerProyectos() {
    return proyectos;
}
