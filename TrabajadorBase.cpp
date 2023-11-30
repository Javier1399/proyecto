#include "TrabajadorBase.h"

 TrabajadorBase::TrabajadorBase(std::string nombre, int id, int horas)
     : Trabajador(nombre, id, horas) {}

 double TrabajadorBase::calcularSueldo() const {
     return sueldo_base;
 }
