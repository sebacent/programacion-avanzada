#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Paga.h"
#include "Empresa.h"
#include <iostream>
#include <stdio.h>
#include <string>

class Empleado {
    private:
        std::string nombre;
        std::string ci;
        int edad;
        Empresa * miemp;
        Paga valorHora;

    public:
        
        void setempresa(Empresa *);
        Empleado(){};
        Empleado(std::string nombre, std::string ci, int edad, Paga valorHora, Empresa *miemp);
        virtual ~Empleado(){
        };
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
        Empresa * getEmpresa();
        double getPaga();
        //FUNCIONES VIRTUALES 
        virtual void imprimirEmpleado() = 0;
        virtual double getSueldoPeso() = 0;
        virtual double getSueldoDolar() = 0;
};

class Jornalero : public Empleado {
    private:
        int horas;

    public:
        Jornalero(std::string nombre, std::string ci, int edad, Paga valorHora,int horas, Empresa *miemp);
        //~Jornalero(); HEREDAN EL DE EMPLEADO
        void setHoras(int horas);
        int getHoras();
        void imprimirEmpleado() override;
        double getSueldoPeso()override;
        double getSueldoDolar()override;
};

class Fijo : public Empleado {
    public:
        Fijo(std::string nombre, std::string ci, int edad, Paga valorHora, Empresa *miemp);
        //~Fijo();HEREDAN EL DE EMPLEADO
        void imprimirEmpleado() override;
        double getSueldoPeso()override;
        double getSueldoDolar()override;
};
#endif