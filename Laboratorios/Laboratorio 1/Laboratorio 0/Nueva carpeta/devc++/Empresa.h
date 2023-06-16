//using namespace std;
#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <string>
#include "Fijo.h"
#include "Jornalero.h"
#include<vector>
class Empleado;

class Empresa{

    private:
        std::string nombre;
        std::string nombreLegal;
        int rut;
        int cantEmpleados;
        //Empleado ** misEmpleados;

        std::vector<Empleado*> misEmpleados;
    public: 
        const std::vector<Empleado*>& getEmpleados() const { return misEmpleados; }
        void AddEmpleado(Empleado* Empleado) { misEmpleados.push_back(Empleado); }

         //Empleado ** misEmpleados;
        int getCantEmpleados();
        void setCantEmpleados();
        //void agregarEmpleados(Empleado *empl);
        Empresa(std::string nombre,std::string nombre_legal, int rut);
        Empresa();
        ~Empresa();
        void setNombre(std::string nombre);
        void setNombreLegal(std::string nombreLegal);
        void setRut(int rut);
        std::string getNombre();
        std::string getNombreLegal();
        int getRut();
        Paga  totalSueldoPeso();
        Paga  totalSueldoDolar();
        void empresaImprimir();

};
#endif