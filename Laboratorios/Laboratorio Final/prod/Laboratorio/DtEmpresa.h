#ifndef DTEMPRESA_H
#define DTEMPRESA_H
#include <string>
#include "Sucursal.h"
#include "ICollection/collections/OrderedDictionary.h"


class DtEmpresa{
    private: 
        int RUT;
        std::string nombre; 
        IDictionary * sucursales; 
        //List *sucursales; 
    public:
        DtEmpresa(int _rut, std::string _nombre);
        ~DtEmpresa();
        //Empresa();
        //SETS
        void setRUT(int _RUT);
        void setNombre(std::string _nombre);
        //GETS
        int getRUT();
        std::string getNombre(); 

        //OPERACIONES DE SUCURSALES
        void addSucursal(std::string _nombre, std::string _direccion, std::string _telefono, int _idSucursal);
        std::string getInfoSuc(int _idSuc);
        void deleteSucursal(int _idSuc);
        void ListarSucursales();
        void eliminarSucursales();
        Sucursal* buscarSucursal(int _idSuc);
        void agregarSeccion(int _idSuc, std::string _nombre, std::string _telefono, int _idSeccion);
};

#endif /* DTEMPRESA_H */