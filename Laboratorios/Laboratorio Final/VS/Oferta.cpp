#include "Oferta.h"

OfertaLaboral::OfertaLaboral( std::string _titulo, std::string _descripcion, int _cantPuestos, int _idExpediente, int _horas, Date* _fechaInicio, Date* _fechaFin, RangoSueldo* _rangoSalarial) {
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

    };
OfertaLaboral::~OfertaLaboral(){};


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
Date* OfertaLaboral::getFechaInicio() {
    return fechaInicio;
}   
Date* OfertaLaboral::getFechaFin() {
    return fechaFin;
}
int OfertaLaboral::getCantPuestos() {
    return cantPuestos;
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
    delete key;
}

void OfertaLaboral::agregarInscripcion(Inscripcion* _inscripcion){
    IKey *key = new Integer(_inscripcion->getId());
    this->inscripciones->add(key, _inscripcion);
    delete key;
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

OrderedDictionary* OfertaLaboral::getAsignaturas(){
    return this->asignaturas;
}

OrderedDictionary* OfertaLaboral::getInscripciones(){
    return this->inscripciones;
}

DtOferta* OfertaLaboral::getDtOferta(){
    DtOferta* dtOferta = new DtOferta(this->titulo, this->descripcion, this->cantPuestos, this->idExpediente, this->horas, this->fechaInicio, this->fechaFin, this->rangoSalarial, this->asignaturas);
    return dtOferta;
}

// ICollection* OfertaLaboral::getContrataciones(){
//     return this->contrataciones;
// }
