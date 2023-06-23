#include "Carrera.h"

Carrera::Carrera(std::string nombre, int id) {
  this->nombre = nombre;
  this->id = id;
  this->asignaturas = new OrderedDictionary();

}
std::string Carrera::getNombre() {
  return nombre;
}
int Carrera::getId() {
  return id;
}
void Carrera::linkAsignatura(Asignatura *_asignatura)
{
  IKey* key = new Integer(_asignatura->getId());
  this->asignaturas->add(key, _asignatura);

}

Carrera::~Carrera(){};