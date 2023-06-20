#include "DtOferta.h"

DtOferta::DtOferta() {
    this->descripcion = "";
    this->titulo = "";
    this->cantPuestos = 0;
    this->idExpediente = 0;
    this->horas = 0;
    this->fechaInicio = NULL;
    this->fechaFin = NULL;
    this->rangoSalarial = NULL;
    this->asignaturas = new OrderedDictionary();
    //this->inscripciones = new OrderedDictionary();
};

DtOferta::DtOferta(std::string _titulo, std::string _descripcion, int _cantPuestos, int _idExpediente, int _horas, Date* _fechaInicio, Date* _fechaFin, RangoSueldo* _rangoSalarial, OrderedDictionary* _asignaturas) {
    this->descripcion = _descripcion;
    this->titulo = _titulo;
    this->cantPuestos = _cantPuestos;
    this->idExpediente = _idExpediente;
    this->horas = _horas;
    this->fechaInicio = _fechaInicio;
    this->fechaFin = _fechaFin;
    this->rangoSalarial = _rangoSalarial;
    this->asignaturas = _asignaturas;
};

DtOferta::~DtOferta(){};

int DtOferta::getIdExpediente() {
    return idExpediente;
}
std::string DtOferta::getTitulo() {
    return titulo;
}
std::string DtOferta::getDescripcion() {
    return descripcion;
}
int DtOferta::getHoras() {
    return horas;
}
RangoSueldo* DtOferta::getRangoSalarial() {
    return rangoSalarial;
}
Date* DtOferta::getFechaInicio() {
    return fechaInicio;
}   
Date* DtOferta::getFechaFin() {
    return fechaFin;
}
int DtOferta::getCantPuestos() {
    return cantPuestos;
}