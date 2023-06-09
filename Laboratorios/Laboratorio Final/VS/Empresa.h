#include <string.h>
#include <iostream>
#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"

class Empresa : public ICollectible {

    private: 
        int RUT;
        std::string nombre; 
        //IDictionary *sucursales; 
        List *sucursales; 
    public:
        Empresa(std::string nombre,int rut);
        ~Empresa();

        //GETS/SETS
        int getRUT();
        std::string getNombre();
        void setRUT(int rut);
        void setNombre(std::string nombre);

        //ADDS/DELETE
        void addSucursal();
        void deleteSucursal();

        //OPERACIONES DE CLASE
        
        void addSucursal(int idSucursal,std::string sucNombre, std::string telefono, std::string direccion);    
        IDictionary* getSucursales();
        void deleteSucursal(int idSucursal);
        ICollection* listarSecciones();
};
