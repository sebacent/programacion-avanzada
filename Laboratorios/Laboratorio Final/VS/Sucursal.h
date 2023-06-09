#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"
#include <string.h>
#include <iostream>

class Sucursal : public ICollectible {
  private:
    std::string nombre;
    std::string direccion;
    std::string telefono;
    int idSucursal;
  public:
    Sucursal(std::string _nombre, std::string _direccion, std::string _telefono, int _idSucursal); 
    std::string getNombre();
    std::string getDireccion();
    std::string getTelefono();
    int getidSucursal();
    void setNombre(std::string _nombre);
    void setDireccion(std::string _direccion);
    void setTelefono(std::string _telefono);
    void setidSucursal(int _idSucursal);

};