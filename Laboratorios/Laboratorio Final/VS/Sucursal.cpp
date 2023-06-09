#include "Sucursal.h"


Sucursal::Sucursal(std::string _nombre, std::string _direccion, std::string _telefono, int _idSucursal) {
    this->nombre = _nombre;
    this->direccion = _direccion;
    this->telefono = _telefono;
    this->idSucursal = _idSucursal; 
    }

std::string Sucursal::getNombre() {
    return nombre;
}
std::string Sucursal::getDireccion() {
    return direccion;
}
std::string Sucursal::getTelefono() {
    return telefono;
}
int Sucursal::getidSucursal() {
    return idSucursal;
}    
void Sucursal::setNombre(std::string _nombre) {
    this->nombre = _nombre;
}
void Sucursal::setDireccion(std::string _direccion) {
    this->direccion = _direccion;
}
void Sucursal::setTelefono(std::string _telefono) {
    this->telefono = _telefono;
}
void Sucursal::setidSucursal(int _idSucursal) {
    this->idSucursal = _idSucursal;
}
