#include "Asignatura.h"

  Asignatura::Asignatura(std::string _nombre, int _id, int _creditos) {
      this->nombre = _nombre;
      this->id = _id;
      this->creditos = _creditos;
    }

    Asignatura::~Asignatura(){};
    
    std::string Asignatura::getNombre() {
      return nombre;
    }

    int Asignatura::getId() {
      return id;
    }
    int Asignatura::getcreditos() {
      return creditos;
    } 