#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <iostream>
#include "DtEmpresa.h"

class ISistema {
    public:
        virtual void addEmpresa(int, std::string) = 0;
        //virtual std::string getNombreSocio () = 0;
        ~ISistema();
        virtual void ListarEmpresas() = 0;
        virtual void ListarSucursales(int) = 0;
        virtual void ListarSecciones(int, int) = 0;
        virtual void ListarAsignaturas() = 0;
        virtual void addOferta(int, std::string, std::string, int, int, Date*, Date*, RangoSueldo*, int, int, int, int[50]) = 0;
        //virtual void ListarEstudiantes() = 0;
        //virtual void ListarOfertas() = 0;
        
        //virtual DtEmpresa * BuscarEmpresa(int) = 0;
        //virtual void addSucursal(int, std::string) = 0;


};

#endif