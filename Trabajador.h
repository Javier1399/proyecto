#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include <string>
using namespace std;

class Trabajador {
protected:
    string nombre;
    int id;
    int horas_trabajadas;

public:
    Trabajador(const string& nombre, int id, int horas);
    virtual double calcularSueldo() const = 0;

    std::string getNombre() const;
    void setNombre(const string& nuevoNombre);

    int getId() const;
    void setId(int nuevoId);

    int getHorasTrabajadas() const;
    void setHorasTrabajadas(int nuevasHoras);

    virtual ~Trabajador();
};

#endif
