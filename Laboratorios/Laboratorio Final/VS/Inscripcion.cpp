#include "Inscripcion.h"

Inscripcion::Inscripcion(Date _fecha, Date** _entrevistas) {
    this->fecha = _fecha;
    this->entrevistas = _entrevistas;
}

Inscripcion::~Inscripcion() {
    delete this->fecha;
    delete this->entrevistas;
}

Date Inscripcion::getFecha() {
    return this->fecha;
}

void Inscripcion::setFecha(Date _fecha) {
    this->fecha = _fecha;
}

Date** Inscripcion::getEntrevistas() {
    return this->entrevistas;
}

void Inscripcion::setEntrevistas(Date** _entrevistas) {
    this->entrevistas = _entrevistas;
}

void Inscripcion::agregarEntrevista(Date _fecha) {
    this->entrevistas->add(_fecha);
    
}
