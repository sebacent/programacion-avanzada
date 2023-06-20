#include "Inscripcion.h"

Inscripcion::Inscripcion(int _id, Date* _fecha, List* _entrevistas) {
    this->id = _id;
    this->fecha = _fecha;
    this->entrevistas = new List();
    this->entrevistas = _entrevistas;
}

Inscripcion::~Inscripcion() {
    delete this->fecha;
    delete this->entrevistas;
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

List* Inscripcion::getEntrevistas() {
    return this->entrevistas;
}

void Inscripcion::setEntrevistas(List* _entrevistas) {
    this->entrevistas = _entrevistas;
}

void Inscripcion::agregarEntrevista(Date* _fecha) {

    this->entrevistas->add(_fecha);
    
}
