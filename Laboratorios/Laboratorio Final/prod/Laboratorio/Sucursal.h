#ifndef SUCURSAL_H
#define SUCURSAL_H

//#include "ICollection/interfaces/ICollectible.h"
//#include "ICollection/interfaces/ICollection.h"
//#include "ICollection/interfaces/IDictionary.h"
//#include "ICollection/collections/List.h"
// #include <string.h>
// #include <iostream>
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/Integer.h"
#include <iostream>

#include "Seccion.h"


class Sucursal : public ICollectible {
  private:
    std::string nombre;
    std::string direccion;
    std::string telefono;
    int idSucursal;
    OrderedDictionary* secciones;
  public:
    Sucursal(std::string _nombre, std::string _telefono, std::string _direccion,  int _idSucursal); 
    ~Sucursal();
    
    //GETS
    std::string getNombre();
    std::string getDireccion();
    std::string getTelefono();
    int getidSucursal();

    //SETS
    void setNombre(std::string _nombre);
    void setDireccion(std::string _direccion);
    void setTelefono(std::string _telefono);
    void setidSucursal(int _idSucursal);

    //SECCIONES
    void agregarSeccion(std::string _nombre,std::string telefono, int _idSeccion);
    void eliminarSeccion(int _idSeccion);
    Seccion* buscarSeccion(int _idSeccion);
    void ListarSecciones();
    void eliminarSecciones();

    //ALTA OFERTA
    void linkOferta(int _idSeccion, OfertaLaboral* _Oferta);
    void unlinkOferta(int _idSeccion, int _idOferta);

    void ListarOfertas(int _idSeccion);

    

 


};

#endif /* SUCURSAL_H */