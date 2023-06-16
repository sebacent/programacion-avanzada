#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Empresa.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "Paga.h"

class Empresa;


class Empleado {
    private:
        std::string nombre;
        std::string ci;
        int edad;
        Paga valorHora;
        Empresa * miemp;
    public:
        
        void setempresa(Empresa *);
        Empleado();
        Empleado(std::string nombre, std::string ci, int edad, Paga valorHora, Empresa *miemp);
        ~Empleado();

        //SET FUNCTION
        void setNombre(std::string nombre);
        void setCi(std::string ci);
        void setEdad(int edad);
        void setEmpresa(Empresa *miemp);
        void setValorHora(Paga valorHora);

        //GET FUNCTION
        std::string getNombre();
        std::string getCi();
        int getEdad();
        Paga getValorHora();
        
        virtual float getSueldoPeso();
        virtual float getSueldoDolar();
        void imprimirEmpleado();
};

#endif