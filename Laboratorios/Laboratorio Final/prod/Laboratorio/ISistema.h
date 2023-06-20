#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <iostream>


class ISistema {
    public:
        virtual void addEmpresa(int, std::string) = 0;
        //virtual std::string getNombreSocio () = 0;
        ~ISistema();
};

#endif