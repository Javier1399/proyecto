#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <string>

class Trabajador {
public:
    std::string nombre;
    int id;
    int horas_trabajadas;

    Trabajador(std::string nombre, int id, int horas);
    virtual double calcularSueldo() const = 0;
    virtual ~Trabajador();
};

class TrabajadorBase : public Trabajador {
public:
    static constexpr double sueldo_base = 2000;

    TrabajadorBase(std::string nombre, int id, int horas);

    double calcularSueldo() const override;
};

class Gerente : public Trabajador {
public:
    double sueldo;

    Gerente(std::string nombre, int id, int horas, double sueldo);

    double calcularSueldo() const override;
};

#endif // TRABAJADOR_H
