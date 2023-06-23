#ifndef CARRERA_H
#define CARRERA_H


#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/collections/OrderedDictionary.h"
#include <string>
#include "Asignatura.h"
class Asignatura;

class Carrera : public  ICollectible {
  private:
    std::string nombre;
    int id;
    OrderedDictionary * asignaturas;

  public:
    Carrera(std::string nombre, int id);
    ~Carrera();
    std::string getNombre();
    int getId();
    OrderedDictionary* getAsignaturas();
    void linkAsignatura(Asignatura* _asignatura);
    void unlinkAsignatura(int _idAsignatura);

};

#endif /* CARRERA_H */