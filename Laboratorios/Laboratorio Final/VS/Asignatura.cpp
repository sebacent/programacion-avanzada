#include "Asignatura.h"

  Asignatura::Asignatura(std::string nombre, std::string id, int creditos) {
      this->nombre = nombre;
      this->id = id;
      this->creditos = creditos;
    }

    Asignatura::~Asignatura();
    std::string Asignatura::getNombre() {
      return nombre;
    }

    std::string Asignatura::getid() {
      return id;
    }
    int Asignatura::getcreditos() {
      return creditos;
    } 