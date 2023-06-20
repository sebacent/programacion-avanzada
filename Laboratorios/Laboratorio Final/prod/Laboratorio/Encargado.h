#ifndef ENCARGADO_H
#define ENCARGADO_H

#include "Persona.h"

class Encargado : public Persona {
  private:

  public:
    //Encargado();
    ~Encargado();
    Encargado(std::string _nombre, std::string _cedula, Date* _fechaNacimiento);
    // std::string getNombre();
    // std::string getCedula();
    // Date getFechaNacimiento();
    // void setNombre(std::string _nombre);
    // void setCedula(std::string _cedula);
    // void setFechaNacimiento(Date _fechaNacimiento);
};

#endif /* ENCARGADO_H */
