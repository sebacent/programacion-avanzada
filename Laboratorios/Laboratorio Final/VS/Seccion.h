#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"
#include "Persona.h"
#include <string.h>
#include <iostream>
class Seccion : public ICollectible {
  private:
    std::string nombre;
    std::string telefono;
    int idSeccion;
    Persona* encargado; 
  public:
    Seccion(std::string _nombre, std::string _telefono, int _idSeccion);
    std::string getNombre();
    std::string getTelefono();
    int getidSeccion();
    void setNombre(std::string _nombre);
    void setTelefono(std::string _telefono);
    void setidSeccion(int _idSeccion);
    Persona* getEncargado();
    void setEncargado(Persona* _encargado);
    
};