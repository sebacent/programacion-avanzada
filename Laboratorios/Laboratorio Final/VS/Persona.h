#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"
#include "Carrera.h"
//#include <iostream>

class Persona : public ICollectible {
  private:
    std::string nombre;
    std::string cedula;
    Date fechaNacimiento;
  public:
    Persona();
    ~Persona();
    Persona(std::string _nombre, std::string _cedula, Date _fechaNacimiento);
    std::string getNombre();
    std::string getCedula();
    Date getFechaNacimiento();
    void setNombre(std::string _nombre);
    void setCedula(std::string _cedula);
    void setFechaNacimiento(Date _fechaNacimiento);

};

class Estudiante : public Persona {
  private:
    std::string telefono;
    int creditos;
    Carrera* carrera;
  public:
    Estudiante(std::string _nombre, std::string _cedula, std::string _direccion, Date _fechaNacimiento, std::string _telefono, int _creditos) {
      this->nombre = _nombre;
      this->cedula = _cedula;
      this->telefono = telefono;
      this->creditos = _creditos;
    }

    std::string getTelefono() {
      return telefono;
    }
    int getCreditos() {
      return creditos;
    }
    void setNombre(std::string _nombre){
        this->nombre = _nombre;
    }
};

class Encargado : public Persona {
  private:

  public:
    Encargado() {
    }

};