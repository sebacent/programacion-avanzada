#include "Seccion.h"

Seccion::Seccion(std::string _nombre, std::string _telefono, int _idSeccion) {
    this->nombre = _nombre;
    this->telefono = _telefono;
    this->idSeccion = _idSeccion;
    this->ofertas = new OrderedDictionary();
    this->encargado = NULL;
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

void Seccion::agregarOferta(OfertaLaboral* _oferta) {
    IKey* KOferta = new Integer(_oferta->getIdExpediente());
    this->ofertas->add(KOferta, _oferta);
    //delete KOferta;
}

void Seccion::eliminarOferta(int _idOferta) {
    IKey* KOferta = new Integer(_idOferta);
    this->ofertas->remove(KOferta);
    delete KOferta;
}

//DEBERIA DEVOLVER UNA COLECCION DE DTOFERTAS Y LISTAR DESDE EL MAIN
void Seccion::ListarOfertas()
{
    IIterator* it = this->ofertas->getIterator();
    while (it->hasCurrent()) {
        OfertaLaboral* oferta = dynamic_cast<OfertaLaboral*> (it->getCurrent());
        std::cout << "ID: " << oferta->getIdExpediente() << " - " << oferta->getTitulo() << std::endl;
        std::cout << "Descripcion: " <<oferta->getDescripcion() << std::endl;
        std::cout << "Sueldo Mínimo: " << oferta->getSueldoMin() << std::endl;
        std::cout << "Sueldo Máximo: " << oferta->getSueldoMax() << std::endl;
        std::cout << "Cantidad de Puestos: " << oferta->getCantPuestos() << std::endl;
        std::cout << "Horas Semanales: " << oferta->getHoras() << std::endl;
        std::cout << "Fecha de Inicio: " << oferta->getFechaInicio()->getDia() << "/" << oferta->getFechaInicio()->getMes() << "/" << oferta->getFechaInicio()->getAnio() << std::endl;
        std::cout << "Fecha de Fin: " << oferta->getFechaFin()->getDia() << "/" << oferta->getFechaFin()->getMes() << "/" << oferta->getFechaFin()->getAnio() << std::endl;
        

        it->next();
    }
    delete it;
}
