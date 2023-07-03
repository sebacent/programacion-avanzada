#include "Persona.h"


std::string Persona::getNombre() {
      return this->nombre;
    }
std::string Persona::getCedula() {
      return this->cedula;
    }
Date* Persona::getFechaNacimiento() {
      return this->fechaNacimiento;
    }
Persona::~Persona() {
    }

void Persona::setFechaNacimiento(Date* _fechaNacimiento) {
      this->fechaNacimiento = _fechaNacimiento;
    }
void Persona::setNombre(std::string _nombre) {
      this->nombre = _nombre;
    }
void Persona::setCedula(std::string _cedula) {
      this->cedula = _cedula;
    }

// Persona::Persona() {
//     this->setNombre("DEFAULT");
//     this->setCedula("1111111");
//     Date* fecha  = new Date(01,01,2000)
//     this->setFechaNacimiento();
    
// }