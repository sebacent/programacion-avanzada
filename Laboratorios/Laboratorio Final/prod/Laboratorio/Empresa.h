#ifndef EMPRESA_H
#define EMPRESA_H
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
#include "DtEmpresa.h"
//#include "ICollection/collections/OrderedDictionary.h"


class Empresa : public ICollectible {

    private: 
        int RUT;
        std::string nombre; 
        OrderedDictionary * sucursales; 
        //List *sucursales; 
    public:
        Empresa(int _rut, std::string _nombre);
        ~Empresa();
        //Empresa();
        //SETS
        void setRUT(int _RUT);
        void setNombre(std::string _nombre);
        //GETS
        int getRUT();
        std::string getNombre(); 

        //OPERACIONES DE SUCURSALES
        void addSucursal(std::string _nombre, std::string _telefono, std::string _direccion, int _idSucursal);
        std::string getInfoSuc(int _idSuc);
        void deleteSucursal(int _idSuc);
        void ListarSucursales();
        void eliminarSucursales();
        Sucursal* buscarSucursal(int _idSuc);
        void addSeccion(int _idSuc, int _idSeccion, std::string _nombre, std::string _telefono);

        //ALTA OFERTA
        void linkOferta(OfertaLaboral* _Oferta , int _idSuc , int _idSeccion);

        DtEmpresa* getDtEmpresa();

        void ListarSecciones(int _idSucursal);
        void ListarOfertas(int _idSucursal, int _idSeccion);
        
};


        //ADDS/DELETE
        
        //void deleteSucursal(int _idSucursal);

    //     //OPERACIONES DE CLASE
        
    //     void addSucursal(int idSucursal,std::string sucNombre, std::string telefono, std::string direccion);    
    //     //IDictionary* getSucursales();
    //     void deleteSucursal(int idSucursal);
    //    // ICollection* listarSecciones();

#endif /* EMPRESA_H */