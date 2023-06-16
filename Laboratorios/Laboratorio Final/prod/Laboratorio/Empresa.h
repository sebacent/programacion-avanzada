//#include "Date.h"
//
//#include "ICollection/interfaces/ICollection.h"
//#include "ICollection/interfaces/IDictionary.h"
//#include "ICollection/collections/List.h"
// #include"ICollection.h"
// #include "List.h"
//#include <iostream>
//#include <string.h>
// #include "ICollection/interfaces/ICollectible.h"
// #include "ICollection/collections/OrderedDictionary.h"
//#include <string> 
#include "Sucursal.h"


class Empresa : public ICollectible {

    private: 
        int RUT;
        std::string nombre; 
        IDictionary * sucursales; 
        //List *sucursales; 
    public:
        Empresa(std::string _nombre,int _rut);
        ~Empresa();
        Empresa();
        //SETS
        void setRUT(int _RUT);
        void setNombre(std::string _nombre);
        //GETS
        int getRUT();
        std::string getNombre(); 

        //OPERACIONES DE SUCURSALES
        void addSucursal(Sucursal * _sucursal);
        std::string getInfoSuc(int _idSuc);
        void deleteSucursal(int _idSuc);
        void ListarSucursales();
};


        //ADDS/DELETE
        
        //void deleteSucursal(int _idSucursal);

    //     //OPERACIONES DE CLASE
        
    //     void addSucursal(int idSucursal,std::string sucNombre, std::string telefono, std::string direccion);    
    //     //IDictionary* getSucursales();
    //     void deleteSucursal(int idSucursal);
    //    // ICollection* listarSecciones();

