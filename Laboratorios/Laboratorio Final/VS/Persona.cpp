#include "Persona.h"


std::string Persona::getNombre() {
      return nombre;
    }
std::string Persona::getCedula() {
      return cedula;
    }
Date Persona::getFechaNacimiento() {
      return fechaNacimiento;
    }
Persona::~Persona() {
    }

void Persona::setFechaNacimiento(Date _fechaNacimiento) {
      fechaNacimiento = _fechaNacimiento;
    }
void Persona::setNombre(std::string _nombre) {
      nombre = _nombre;
    }
void Persona::setCedula(std::string _cedula) {
      cedula = _cedula;
    }

    