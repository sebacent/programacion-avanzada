#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include <string>

class Carrera : public  ICollectible {
  private:
    std::string nombre;
    int id;
    //IDictionary * asignaturas;

  public:
    Carrera(std::string nombre, int id);
    ~Carrera();
    std::string getNombre();
    int getid();
};