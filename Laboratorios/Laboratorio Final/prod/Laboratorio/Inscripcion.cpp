#include "Inscripcion.h"

Inscripcion::Inscripcion(int _id, Date* _fecha, Estudiante* _estudiante, OfertaLaboral* _oferta) {
    //idInscripcion += 1;
    this->id = _id;
    this->fecha = _fecha;
    this->entrevistas = new OrderedDictionary();
    this->estudiante = _estudiante;
    this->oferta = _oferta;
}

Inscripcion::~Inscripcion() {
    // delete this->fecha;
    // delete this->entrevistas;
    // delete this->estudiante;
    // delete this->oferta;
    //std::cout << "Inscripcion eliminada" << std::endl;
}

int Inscripcion::getId() {
    return this->id;
}

void Inscripcion::setId(int _id) {
    this->id = _id;
}


Date* Inscripcion::getFecha() {
    return this->fecha;
}


void Inscripcion::setFecha(Date* _fecha) {
    this->fecha = _fecha;
}

OrderedDictionary* Inscripcion::getEntrevistas() {
    return this->entrevistas;
}

void Inscripcion::setEntrevistas(OrderedDictionary* _entrevistas) {
    this->entrevistas = _entrevistas;
}

void Inscripcion::agregarEntrevista(Date* _fecha) {
    IKey *key = new Integer(_fecha->getDia() + _fecha->getMes() + _fecha->getAnio());
    this->entrevistas->add(key, _fecha);
    delete key;
    
}

void Inscripcion::eliminarEntrevista(Date* _fecha) {
    IKey *key = new Integer(_fecha->getDia() + _fecha->getMes() + _fecha->getAnio());
    this->entrevistas->remove(key);
    delete key;
}

Estudiante* Inscripcion::getEstudiante() {
    return this->estudiante;
}

OfertaLaboral* Inscripcion::getOferta() {
    return this->oferta;
}

