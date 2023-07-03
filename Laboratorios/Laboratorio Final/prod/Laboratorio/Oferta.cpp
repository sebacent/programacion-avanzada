#include "Oferta.h"

OfertaLaboral::OfertaLaboral(int _idExpediente, std::string _titulo, std::string _descripcion, int _cantPuestos, int _horas, Date* _fechaInicio, Date* _fechaFin, RangoSueldo* _rangoSalarial) {
    this->descripcion = _descripcion;
    this->titulo = _titulo;
    this->cantPuestos = _cantPuestos;
    this->idExpediente = _idExpediente;
    this->horas = _horas;
    this->fechaInicio = _fechaInicio;
    this->fechaFin = _fechaFin;
    this->rangoSalarial = _rangoSalarial;
    this->asignaturas = new OrderedDictionary();
    this->inscripciones = new OrderedDictionary();
    this->seccion = NULL;
};
OfertaLaboral::~OfertaLaboral(){
    delete this->asignaturas;
    delete this->inscripciones;
    delete this->rangoSalarial;
    delete this->fechaInicio;
    delete this->fechaFin;
    delete this->seccion;
    //delete this;

};


int OfertaLaboral::getIdExpediente() {
    return idExpediente;
}
std::string OfertaLaboral::getTitulo() {
    return titulo;
}
std::string OfertaLaboral::getDescripcion() {
    return descripcion;
}
int OfertaLaboral::getHoras() {
    return horas;
}
RangoSueldo* OfertaLaboral::getRangoSalarial() {
    return rangoSalarial;
}

int OfertaLaboral::getSueldoMax() {
    return rangoSalarial->getMaximo();
}

int OfertaLaboral::getSueldoMin() {
    return rangoSalarial->getMinimo();
}

Date* OfertaLaboral::getFechaInicio() {
    return fechaInicio;
}   
Date* OfertaLaboral::getFechaFin() {
    return fechaFin;
}
int OfertaLaboral::getCantPuestos() {
    return cantPuestos;
}

Seccion* OfertaLaboral::getSeccion() {
    return seccion;
}

bool OfertaLaboral::activa(Date* _fechaHoy)
{
    
    return (this->fechaInicio->operator<=(_fechaHoy) && this->fechaFin->operator>=(_fechaHoy));
}

void OfertaLaboral::setIdExpediente(int _idExpediente){
    this->idExpediente = _idExpediente;
}
void OfertaLaboral::setTitulo(std::string _titulo){
    this->titulo = _titulo;
}
void OfertaLaboral::setDescripcion(std::string _descripcion){
    this->descripcion = _descripcion;
}
void OfertaLaboral::setRangoSalarial(RangoSueldo* _rangoSalarial){
    this->rangoSalarial = _rangoSalarial;
}
void OfertaLaboral::setFechaInicio(Date* _fechaInicio){
    this->fechaInicio = _fechaInicio;
}
void OfertaLaboral::setFechaFin(Date* _fechaFin){
    this->fechaFin = _fechaFin;
}

void OfertaLaboral::setHoras(int _horas){
    this->horas = _horas;
}
void OfertaLaboral::setCantPuestos(int _cantPuestos){
    this->cantPuestos = _cantPuestos;
}

void OfertaLaboral::agregarAsignatura(Asignatura* _asignatura){
    IKey *key = new Integer(_asignatura->getId());
    this->asignaturas->add(key, _asignatura);
    //delete key;
}

void OfertaLaboral::agregarInscripcion(Inscripcion* _inscripcion){
    IKey *key = new Integer(_inscripcion->getId());
    this->inscripciones->add(key, _inscripcion);
    //delete key;
}

// void OfertaLaboral::agregarContratacion(Contratacion* _contratacion){
//     IKey *key = new Integer(_contratacion->getId());
//     this->contrataciones->add(key, _contratacion);
//     delete key;
// }
void OfertaLaboral::eliminarAsignatura(Asignatura* _asignatura){
    IKey *key = new Integer(_asignatura->getId());
    this->asignaturas->remove(key);
    delete key;
}

void OfertaLaboral::eliminarInscripcion(Inscripcion* _inscripcion){
    IKey *key = new Integer(_inscripcion->getId());
    this->inscripciones->remove(key);
    delete key;
}

// void OfertaLaboral::eliminarContratacion(Contratacion* _contratacion){
//     this->contrataciones->remove(_contratacion);
// }

void OfertaLaboral::setSeccion(Seccion* _seccion){
    this->seccion = _seccion;
}    

OrderedDictionary* OfertaLaboral::getAsignaturas(){
    return this->asignaturas;
}

OrderedDictionary* OfertaLaboral::getInscripciones(){
    return this->inscripciones;
}

// DtOferta* OfertaLaboral::getDtOferta(){
//     DtOferta* dtOferta = new DtOferta(this->titulo, this->descripcion, this->cantPuestos, this->idExpediente, this->horas, this->fechaInicio, this->fechaFin, this->rangoSalarial, this->asignaturas);
//     return dtOferta;
// }

// ICollection* OfertaLaboral::getContrataciones(){
//     return this->contrataciones;
// }
