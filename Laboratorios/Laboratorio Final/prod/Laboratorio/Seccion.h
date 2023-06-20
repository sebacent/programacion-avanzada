#ifndef SECCION_H
#define SECCION_H

// #include "ICollection/interfaces/ICollectible.h"
// #include "ICollection/interfaces/ICollection.h"
// #include "ICollection/interfaces/IDictionary.h"
// #include "ICollection/collections/List.h"
// #include "Persona.h"
// #include <string.h>
// #include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "Oferta.h"
#include <string>

class Oferta;
class Seccion : public ICollectible {
  private:
    std::string nombre;
    std::string telefono;
    int idSeccion;
    OrderedDictionary * ofertas;
   // Persona* encargado; 
  public:
    Seccion(std::string _nombre, std::string _telefono, int _idSeccion);
    ~Seccion();
    //GETS
    std::string getNombre();
    std::string getTelefono();
    int getidSeccion();

    //SETS
    void setNombre(std::string _nombre);
    void setTelefono(std::string _telefono);
    void setidSeccion(int _idSeccion);


    //ELIMINAR
    //Persona* getEncargado();
    //void setEncargado(Persona* _encargado);
};

#endif /* SECCION_H */