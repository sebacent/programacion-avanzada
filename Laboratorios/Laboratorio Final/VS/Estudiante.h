#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"
//#include "Asignatura.h"
#include "ICollection/collections/OrderedDictionary.h"
// #include "Inscripcion.h"
// #include "Contrato.h"
class Estudiante : public Persona {
  private:
    std::string telefono;
    int creditos;
    OrderedDictionary* carreras; 
    //OrderedDictionary* asignaturas;
    // Inscripcion* inscripciones;

  public:
    Estudiante(std::string _nombre, std::string _cedula, std::string _direccion, Date _fechaNacimiento, std::string _telefono, int _creditos );
    ~Estudiante();
    int getCreditos();
    void setCreditos(int _creditos);
    std::string getTelefono();
    void setTelefono(std::string _telefono);
    void setNombre(std::string _nombre);
    // OrderedDictionary* getCarrera();
    // void setCarrera(OrderedDictionary* _carrera);
    // OrderedDictionary* getAsignaturas();
    // void setAsignaturas(OrderedDictionary* _asignaturas);
    // void addAsignaturas(ICollectible* _asignatura);
    // void removeAsignaturas(ICollectible* _asignatura);
    

};
#endif /* ESTUDIANTE_H */