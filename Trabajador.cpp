#include "Trabajador.h"

Trabajador::Trabajador(std::string nombre, int id, int horas)
    : nombre(nombre), id(id), horas_trabajadas(horas) {}

Trabajador::~Trabajador() {}
