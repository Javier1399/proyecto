#include "Trabajador.h"
using namespace std;

Trabajador::Trabajador(const string& nombre, int id, int horas)
    : nombre(nombre), id(id), horas_trabajadas(horas) {}

string Trabajador::getNombre() const {
    return nombre;
}

void Trabajador::setNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

int Trabajador::getId() const {
    return id;
}

void Trabajador::setId(int nuevoId) {
    id = nuevoId;
}

int Trabajador::getHorasTrabajadas() const {
    return horas_trabajadas;
}

void Trabajador::setHorasTrabajadas(int nuevasHoras) {
    horas_trabajadas = nuevasHoras;
}

Trabajador::~Trabajador() {}
