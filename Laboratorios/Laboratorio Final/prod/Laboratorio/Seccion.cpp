#include "Seccion.h"

Seccion::Seccion(std::string _nombre, std::string _telefono, int _idSeccion) {
    this->nombre = _nombre;
    this->telefono = _telefono;
    this->idSeccion = _idSeccion;
}

Seccion::~Seccion() {}

std::string Seccion::getNombre() {
    return nombre;
}
std::string Seccion::getTelefono() {
    return telefono;
}
int Seccion::getidSeccion() {
    return idSeccion;
}
void Seccion::setNombre(std::string _nombre) {
    this->nombre = _nombre;
}
void Seccion::setTelefono(std::string _telefono) {
    this->telefono = _telefono;
}
void Seccion::setidSeccion(int _idSeccion) {
    this->idSeccion = _idSeccion;
}
// Persona* Seccion::getEncargado() {
//     return encargado;
// }
// void Seccion::setEncargado(Persona* _encargado) {
//     this->encargado = _encargado;
// }
