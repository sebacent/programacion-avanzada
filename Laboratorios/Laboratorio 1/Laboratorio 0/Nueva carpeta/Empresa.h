//using namespace std;
#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <string>
#include "Paga.h"
//#include "Empleado.h"
//#include "Fijo.h"
//#include "Jornalero.h"
#include<vector>
class Empleado;

class Empresa{

    private:
        std::string nombre;
        std::string nombreLegal;
        int rut;
        int cantEmpleados;
        Empleado** misEmpleados;

    public: 
        
        

         //Empleado ** misEmpleados;
        int getCantEmpleados();
        void setCantEmpleados();
        //void agregarEmpleados(Empleado *empl);
        Empresa();
        ~Empresa();
        Empresa(std::string nombre,std::string nombre_legal, int rut);
        Empresa(std::string nombre,std::string nombre_legal, int rut, int cantEmpleados, Empleado** misEmpleados);
        void setNombre(std::string nombre);
        void setNombreLegal(std::string nombreLegal);
        void setRut(int rut);
        
        std::string getNombre();
        std::string getNombreLegal();
        int getRut();
        Paga totalSueldoPeso();
        Paga totalSueldoDolar();
        
        void empresaImprimir();

        //FUNCIONES CON EMPLEADOS
        void AddEmpleado(Empleado* empleado);
        void listarEmpleados();
        //Empleado** getEmpleados() { return misEmpleados; }
};
#endif