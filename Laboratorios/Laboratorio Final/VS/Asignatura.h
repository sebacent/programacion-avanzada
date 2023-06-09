#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"
#include "Carrera.h"


class Asignatura : public  ICollectible {
  private:
    std::string nombre;
    std::string direccion;
    std::string telefono;
    int numero;
  public:
    Asignatura(std::string nombre, std::string direccion, std::string telefono, int numero) {
      this->nombre = nombre;
      this->direccion = direccion;
      this->telefono = telefono;
      this->numero = numero;
    }
    std::string getNombre() {
      return nombre;
    }
    std::string getDireccion() {
      return direccion;
    }
    std::string getTelefono() {
      return telefono;
    }
    int getNumero() {
      return numero;
    }
};