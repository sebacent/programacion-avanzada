#include "Encargado.h"

Encargado::Encargado() {
    this->setNombre("DEFAULT");
    this->setCedula("1111111");
    this->setFechaNacimiento(Date(01,01,2000));

}
Encargado::Encargado(std::string _nombre, std::string _cedula, Date _fechaNacimiento) {
    this->setNombre(_nombre);
    this->setCedula(_cedula);
    this->setFechaNacimiento(_fechaNacimiento);
}

Encargado::~Encargado() {
}


