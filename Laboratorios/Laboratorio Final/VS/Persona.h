//#include "ICollection/interfaces/ICollection.h"
//#include "ICollection/collections/List.h"
//#include <iostream>
#include "Carre.h"
#include "ICollection/interfaces/IDictionary.h"
#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"


class Persona : public ICollectible {
  protected:
    std::string nombre;
    std::string cedula;
    Date fechaNacimiento;
  public:
    virtual ~Persona();
    std::string getNombre();
    std::string getCedula();
    Date getFechaNacimiento();
    void setFechaNacimiento(Date _fechaNacimiento);
    void setNombre(std::string _nombre);
    void setCedula(std::string _cedula);
    
};



