#include "Persona.h"

Persona::Persona(std::string _nombre, std::string _cedula, Date _fechaNacimiento) {
    this->nombre = _nombre;
    this->cedula = _cedula;
    this->fechaNacimiento = _fechaNacimiento;
}
std::string Persona::getNombre() {
      return nombre;
    }
std::string Persona::getCedula() {
      return cedula;
    }
Date Persona::getFechaNacimiento() {
      return fechaNacimiento;
    }

void Persona::setNombre(std::string _nombre) {
      this->nombre = _nombre;
    }
void Persona::setCedula(std::string _cedula) {
      this->cedula = _cedula;
    }
void Persona::setFechaNacimiento(Date _fechaNacimiento) {
      this->fechaNacimiento = _fechaNacimiento;
    }
