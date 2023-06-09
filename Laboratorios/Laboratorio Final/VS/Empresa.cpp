#include "Empresa.h"

Empresa::Empresa(std::string _nombre, int _rut) {
    nombre = _nombre;
    RUT = _rut;
    sucursales = new List; 
    //sucursales = new IDictionary(); 
}


std::string Empresa::getNombre()
{
    return nombre;
}
void Empresa::setNombre(std::string _nombre)
{
    this->nombre = _nombre;
}
int Empresa::getRUT()
{
    return RUT;
}
void Empresa::setRUT(int _RUT)
{
    this->RUT = _RUT;
}
