#include "TrabajadorBase.h"
using namespace std;

TrabajadorBase::TrabajadorBase(const std::string& nombre, int id, int horas)
    : Trabajador(nombre, id, horas) {}

double TrabajadorBase::calcularSueldo() const {
    return sueldo_base;
}

