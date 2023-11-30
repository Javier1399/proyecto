#include "Gerente.h"
using namespace std;

Gerente::Gerente(const string& nombre, int id, int horas, double sueldo)
    : Trabajador(nombre, id, horas), sueldo(sueldo) {}

double Gerente::calcularSueldo() const {
    return sueldo;
}

double Gerente::getSueldo() const {
    return sueldo;
}

void Gerente::setSueldo(double nuevoSueldo) {
    sueldo = nuevoSueldo;
}

