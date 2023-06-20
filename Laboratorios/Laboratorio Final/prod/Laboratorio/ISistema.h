#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <iostream>


class ISistema {
    public:
        virtual void addEmpresa(int, std::string) = 0;
        //virtual std::string getNombreSocio () = 0;
        ~ISistema();
        virtual void ListarEmpresas() = 0;
        virtual Empresa * BuscarEmpresa(int) = 0;
        //virtual void addSucursal(int, std::string) = 0;
};

#endif