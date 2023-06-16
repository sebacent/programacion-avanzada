#ifndef FIJO_H
#define FIJO_H
#include "Empleado.h"
#include <string>


class Fijo : public Empleado{
    public:
        Fijo(std::string nombre, std::string ci, int edad, Paga valor_hora, Empresa *miemp);
        ~Fijo();
        void imprimir_Fijo();
        float get_sueldo_peso();
        float get_sueldo_dolar();

};

#endif