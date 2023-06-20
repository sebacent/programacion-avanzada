#include "Sucursal.h"


Sucursal::Sucursal(std::string _nombre, std::string _direccion, std::string _telefono, int _idSucursal) {
    this->nombre = _nombre;
    this->direccion = _direccion;
    this->telefono = _telefono;
    this->idSucursal = _idSucursal; 
    this->secciones = new OrderedDictionary();
    }

Sucursal::~Sucursal() {
    delete secciones;
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

void Sucursal::agregarSeccion(std::string _nombre, std::string _telefono,int _idSeccion) {
    IKey* KSeccion = new Integer(_idSeccion);
    Seccion* _seccion = new Seccion(_nombre,_telefono,_idSeccion);
    this->secciones->add(KSeccion, _seccion);
    //delete KSeccion;
}
void Sucursal::eliminarSeccion(int _idSeccion) {
    IKey* KSeccion = new Integer(_idSeccion);
    this->secciones->remove(KSeccion);
    delete KSeccion;
}
Seccion* Sucursal::buscarSeccion(int _idSeccion) {
    IKey* KSeccion = new Integer(_idSeccion);
    return (Seccion*)this->secciones->find(KSeccion);
}

void Sucursal::listarSecciones(){
    IIterator* it = secciones->getIterator();
    std::cout << "Secciones para la sucursal: " <<this->getNombre()<< std::endl;
    while(it->hasCurrent()){
        Seccion* seccion = (Seccion*)it->getCurrent();
        std::cout << "  Nombre: " << seccion->getNombre() << std::endl;
        std::cout << "  Telefono: " << seccion->getTelefono() << std::endl;
        std::cout << "  ID: " << seccion->getidSeccion() << std::endl;
        std::cout << "  ------------------- " << std::endl;
        it->next();
    }
    delete it;
}

void Sucursal::eliminarSecciones(){
    IIterator* it = secciones->getIterator();
    while(it->hasCurrent()){
        Seccion* seccion = (Seccion*)it->getCurrent();
        delete seccion;
        it->next();
    }
    delete it;
    //this->secciones->empty();
}