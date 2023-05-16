#ifndef JORNALERO_H
#define JORNALERO_H
#include "Empleado.h"
#include <string>


class Jornalero: public Empleado {
    
    private:
        int horas;

    public:
        Jornalero(std::string nombre, std::string ci, int edad, Paga valor_hora, Empresa *miemp);
        ~Jornalero();
        void set_horas(int horas);
        int get_horas();
        float get_sueldo_peso();
        float get_sueldo_dolar();

};

#endif