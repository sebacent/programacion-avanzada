#include "Nota.h"


Nota::Nota(Estudiante* _estudiante, ICollectible* _asignatura, Date* _fecha, int _nota, int _id){
    this->estudiante = _estudiante;
    Asignatura* auxAsignatura = (Asignatura*)_asignatura; // AL PEDOOOOOO O HAGO TODO POR ICOLLETIBLE O NADA 
    this->asignatura = auxAsignatura;
    this->fecha = _fecha;
    this->nota = _nota;
    this->id = _id;
};

Nota::~Nota(){};

Estudiante* Nota::getEstudiante(){
    return this->estudiante;
};

Asignatura* Nota::getAsignatura(){
    return this->asignatura;
};

Date* Nota::getFecha(){
    return this->fecha;
};

int Nota::getNota(){
    return this->nota;
}
int Nota::getCreditos()
{
    return this->asignatura->getCreditos();
};

void Nota::setEstudiante(Estudiante* _estudiante){
    this->estudiante = _estudiante;
};

void Nota::setAsignatura(Asignatura* _asignatura){
    this->asignatura = _asignatura;
};

void Nota::setFecha(Date* _fecha){
    this->fecha = _fecha;
};

void Nota::setNota(int _nota){
    this->nota = _nota;
};

bool Nota::operator>=(Nota* _nota){
    if(this->nota >= _nota->getNota()){
        return true;
    }
    return false;
};

