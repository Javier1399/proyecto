#include "Gerente.h"

Gerente::Gerente(std::string nombre, int id, int horas, double sueldo)
    : Trabajador(nombre, id, horas), sueldo(sueldo) {}

double Gerente::calcularSueldo() const {
    return sueldo;
}
