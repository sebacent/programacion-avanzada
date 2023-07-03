#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"
#include "Nota.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "Inscripcion.h"
#include <iostream>
#include "Oferta.h"
// #include "Inscripcion.h"
// #include "Contrato.h"
class OfertaLaboral;
class Estudiante : public Persona {
  private:
    std::string telefono;
    int creditos; //CALCULADO
    OrderedDictionary* carreras; 
    OrderedDictionary* asignaturas;
    OrderedDictionary* inscripciones;//A OFERTAS

  public:
    Estudiante(std::string _nombre, std::string _cedula, Date* _fechaNacimiento, std::string _telefono);
    ~Estudiante();
    
    int getCreditos();
    void setCreditos(int _creditos);
    
    void setTelefono(std::string _telefono);
    std::string getTelefono();
    
    void setNombre(std::string _nombre);
    std::string getNombre();

    void ListarEstudiante();

    void setCedula(std::string _cedula);
    std::string getCedula();

    void setFechaNacimiento(Date* _fechaNacimiento);
   // Date* getFechaNacimiento(); YA ESTA EN LA PERSONA





    void addAsignatura(int _id, Date* _fecha, int _nota, ICollectible* _asignatura);
    void removeAsignatura(int idAsignatura);

    void addInscripcion(OfertaLaboral* _Oferta, int _idOferta, int _idInscripcion, Date * _fecha );
    void removeInscripcion(int idInscripcion);
    
    void addCarrera(ICollectible* _carrera, int _idCarrera);
    void removeCarrera(int idCarrera);
    
    
    OrderedDictionary* getCarreras();
    OrderedDictionary* getAsignaturas();
    OrderedDictionary* getInscripciones();
    
    // void addCarrera(ICollectible* _carrera);

    // OrderedDictionary* getCarrera();
    // void setCarrera(OrderedDictionary* _carrera);
    // OrderedDictionary* getAsignaturas();
    // void setAsignaturas(OrderedDictionary* _asignaturas);
    // void addAsignaturas(ICollectible* _asignatura);
    // void removeAsignaturas(ICollectible* _asignatura);
    

};
#endif /* ESTUDIANTE_H */